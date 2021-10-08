#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

const int INF = 2e9;
const int MOD = 1e9 + 7;

struct segment_tree {
    segment_tree *left = 0, *right = 0;
    int lb, rb, val = 0;
    segment_tree(int lb, int rb): lb(lb), rb(rb) {
        if (lb != rb) {
            int mid = lb + (rb - lb) / 2;
            left = new segment_tree(lb, mid);
            right = new segment_tree(mid + 1, rb);
        }
    }

    void insert(int index) {
        if (lb > index || rb < index) {
            return;
        }

        if (lb == rb) {
            val = 1;
            return;
        }

        if (left->lb <= index && index <= left->rb) {
            left->insert(index);
        }
        else {
            right->insert(index);
        }

        val = left->val + right->val;
    }

    int query(int lb) {
        if (this->rb < lb) {
            return 0;
        }

        if (lb <= this->lb || this->lb == this->rb) {
            return val;
        }

        return left->query(lb) + right->query(lb);
    }
};

int inversions(vector<int>& a) {
    int n = a.size();
    vector<pii> posi;
    posi.reserve(n);
    for (int i = 0; i < n; i++) {
        posi.push_back({i, a[i]});
    }
    sort(posi.begin(), posi.end(), [&](pii& p1, pii& p2) {
        return p1.second < p2.second;
    });
    segment_tree *tree = new segment_tree(0, n);
    int ans = 0;
    for (pii p : posi) {
        tree->insert(p.first);
        ans += tree->query(p.first + 1);
    }
    return ans;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    cout << (inversions(a) % 2 == inversions(b) % 2 ? "Possible\n" : "Impossible\n");
}
