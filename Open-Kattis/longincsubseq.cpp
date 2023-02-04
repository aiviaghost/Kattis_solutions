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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define unordered_map gp_hash_table

#define int ll
#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
#define size(x) (ll)(x).size()

const int INF = 2e9;
const int MOD = 1e9 + 7;

struct Segment_tree {

    Segment_tree *left, *right;
    int lb, rb, val = 0, val_idx = -1;

    Segment_tree(int lb, int rb) : lb(lb), rb(rb) {
        if (lb == rb) {
            val_idx = lb;
            left = right = 0;
        }
        else {
            int mid = lb + (rb - lb) / 2;
            left = new Segment_tree(lb, mid);
            right = new Segment_tree(mid + 1, rb);
        }
    }

    void set(int idx, int new_val) {
        if (lb == rb) {
            val = new_val;
            return;
        }

        if (left->lb <= idx && idx <= left->rb) {
            left->set(idx, new_val);
        }
        else {
            right->set(idx, new_val);
        }

        if (left->val > right->val) {
            val = left->val;
            val_idx = left->val_idx;
        }
        else {
            val = right->val;
            val_idx = right->val_idx;
        }
    }

    pii query(int l) {
        if (rb < l) {
            return {-INF, -1};
        }
        
        if (l <= lb) {
            return {val, val_idx};
        }

        return max(left->query(l), right->query(l));
    }

};

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    while (cin >> n) {
        vector<int> xs(n);
        for (int i = 0; i < n; i++) {
            cin >> xs[i];
        }
        vector<int> inds(n);
        iota(all(inds), 0);
        sort(all(inds), [&](int i, int j) {
            return xs[i] < xs[j] || (xs[i] == xs[j] && j < i);
        });

        Segment_tree st(0, n - 1);
        vector<int> par(n, -1), ans(n);
        for (int i = n - 1; i >= 0; i--) {
            auto [right_max, max_idx] = st.query(inds[i]);
            ans[inds[i]] = 1 + right_max;
            par[inds[i]] = xs[max_idx] > xs[inds[i]] ? max_idx : -1;
            st.set(inds[i], ans[inds[i]]);
        }
        
        int start_idx = 0;
        for (int i = 1; i < n; i++) {
            if (ans[i] > ans[start_idx]) {
                start_idx = i;
            }
        }

        vector<int> out;
        int curr = start_idx;
        while (curr != -1) {
            out.push_back(curr);
            curr = par[curr];
        }

        cout << size(out) << "\n";
        cout << out.front();
        for (int i = 1; i < size(out); i++) {
            cout << " " << out[i];
        }
        cout << "\n";
    }
}
