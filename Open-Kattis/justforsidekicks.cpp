#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

const int INF = 2e9;
const int MOD = 1e9 + 7;

struct segment_tree {
    int lb, rb;
    vector<int> pc;
    segment_tree *left = 0, *right = 0;

    segment_tree(vector<int>& gems, int lb, int rb) : lb(lb), rb(rb) {
        pc.resize(6);
        if (lb == rb) {
            pc[gems[lb]]++;
        }
        else {
            int mid = lb + (rb - lb) / 2;
            left = new segment_tree(gems, lb, mid);
            right = new segment_tree(gems, mid + 1, rb);
            for (int i = 0; i < 6; i++) {
                pc[i] = left->pc[i] + right->pc[i];
            }
        }
    }

    void set(int index, int val) {
        if (rb < index || index < lb) {
            return;
        }

        if (lb == index && index == rb) {
            for (int i = 0; i < 6; i++) {
                pc[i] = 0;
            }
            pc[val]++;
            return;
        }

        left->set(index, val);
        right->set(index, val);

        for (int i = 0; i < 6; i++) {
            pc[i] = left->pc[i] + right->pc[i];
        }
    }

    vector<int> query(int lb, int rb) {
        if (rb < this->lb || this->rb < lb) {
            return vector<int>(6);
        }

        if (lb <= this->lb && this->rb <= rb) {
            return pc;
        }

        vector<int> left_ans = left->query(lb, rb);
        vector<int> right_ans = right->query(lb, rb);
        vector<int> ans(6);
        for (int i = 0; i < 6; i++) {
            ans[i] = left_ans[i] + right_ans[i];
        }
        return ans;
    }
};

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    vector<int> V(6);
    for (int i = 0; i < 6; i++) {
        cin >> V[i];
    }
    cin.ignore();
    vector<int> gems(n);
    string gem_string;
    cin >> gem_string;
    int index = 0;
    for (char c : gem_string) {
        gems[index] = c - '0' - 1;
        index++;
    }
    segment_tree *tree = new segment_tree(gems, 0, n - 1);
    while (q--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int k, p;
            cin >> k >> p, k--, p--;
            tree->set(k, p);
        }
        else if (opt == 2) {
            int p, v;
            cin >> p >> v, p--;
            V[p] = v;
        }
        else {
            int l, r;
            cin >> l >> r, l--, r--;
            vector<int> gc = tree->query(l, r);
            ll ans = 0;
            for (int i = 0; i < 6; i++) {
                ans += (ll)gc[i] * (ll)V[i];
            }
            cout << ans << "\n";
        }
    }
}
