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

struct Bound_tree {
    Bound_tree *left = 0, *right = 0;
    int val, index_of_val, lb, rb;
    
    Bound_tree(vector<int> & hs, int lb, int rb) : lb(lb), rb(rb) {
        if (lb == rb) {
            val = hs[lb];
            index_of_val = lb;
        }
        else {
            int mid = lb + (rb - lb) / 2;
            left = new Bound_tree(hs, lb, mid);
            right = new Bound_tree(hs, mid + 1, rb);
            if (left->val >= right->val) {
                val = left->val;
                index_of_val = left->index_of_val;
            }
            else {
                val = right->val;
                index_of_val = right->index_of_val;
            }
        }
    }

    int query(int min_h, int lb) {
        if (this->lb == this->rb) {
            return lb <= this->lb ? index_of_val : INF;
        }

		if (this->rb < lb) {
			return INF;
		}

        int ret = INF;
		
		if (left->val >= min_h) {
			ret = left->query(min_h, lb);
		}
        else if (right->val >= min_h) {
			ret = right->query(min_h, lb);
		}

		return ret;
    }
};

struct Min_tree {
    Min_tree *left = 0, *right = 0;
    int val, lb, rb;
    
    Min_tree(vector<int> & hs, int lb, int rb) : lb(lb), rb(rb) {
        if (lb == rb) {
            val = hs[lb];
        }
        else {
            int mid = lb + (rb - lb) / 2;
            left = new Min_tree(hs, lb, mid);
            right = new Min_tree(hs, mid + 1, rb);
            val = min(left->val, right->val);
        }
    }

    int query(int lb, int rb) {
        if (this->rb < lb || rb < this->lb) {
            return INF;
        }

        if (lb <= this->lb && this->rb <= rb) {
            return val;
        }

        return min(left->query(lb, rb), right->query(lb, rb));
    }
};

struct Max_tree {
    Max_tree *left = 0, *right = 0;
    int lb, rb;
    pii vp;

    Max_tree(vector<int> & hs, int lb, int rb) : lb(lb), rb(rb) {
        if (lb == rb) {
            vp = {hs[lb], lb};
        }
        else {
            int mid = lb + (rb - lb) / 2;
            left = new Max_tree(hs, lb, mid);
            right = new Max_tree(hs, mid + 1, rb);
            if (left->vp.first >= right->vp.first) {
                vp = left->vp;
            }
            else {
                vp = right->vp;
            }
        }
    }

    pii query(int lb, int rb) {
        if (this->rb < lb || rb < this->lb) {
            return {-INF, -1};
        }

        if (lb <= this->lb && this->rb <= rb) {
            return vp;
        }

        pii l = left->query(lb, rb), r = right->query(lb, rb);
        return l.first >= r.first ? l : r;
    }
};

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> hs(n);
    for (int i = 0; i < n; i++) {
        cin >> hs[i];
    }
    Bound_tree *bound_tree = new Bound_tree(hs, 0, n - 1);
    Max_tree *max_tree = new Max_tree(hs, 0, n - 1);
    vector<int> next(n);
    for (int i = 0; i < n - 1; i++) {
        int index = bound_tree->query(hs[i], i + 1);
        next[i] = index != INF ? index : max_tree->query(i + 1, n).second;
    }
    Min_tree *min_tree = new Min_tree(hs, 0, n - 1);
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans = max(ans, min(hs[i], hs[next[i]]) - min_tree->query(i + 1, next[i] - 1));
    }
    cout << ans << "\n";
}
