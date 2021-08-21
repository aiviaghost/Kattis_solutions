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
    int lb, rb, val;
    segment_tree *left, *right;
    
    segment_tree(vector<int>& a, int lb, int rb) {
        this->lb = lb;
        this->rb = rb;
        if (lb == rb) {
            this->left = this->right = NULL;
            this->val = a[lb];
        }
        else {
            int mid = lb + (rb - lb) / 2;
            this->left = new segment_tree(a, lb, mid);
            this->right = new segment_tree(a, mid + 1, rb);
            this->val = max(this->left->val, this->right->val);
        }
    }
	
    auto query(int lb, int rb, int min_val) -> int {
        if (this->lb == this->rb) {
            return this->val >= min_val && lb <= this->lb && this->rb <= rb ? this->lb : INF;
        }

		if (this->rb < lb) {
			return INF;
		}

        int ret = INF;
		
		if (this->left->val >= min_val) {
			ret = this->left->query(lb, rb, min_val);
		}

		if (ret == INF && this->right->val >= min_val) {
			ret = this->right->query(lb, rb, min_val);
		}

		return ret;
    }
};

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a[n] = INF; // artificial node to create connected tree
    
	segment_tree *tree = new segment_tree(a, 0, n);
    
	int max_log = 0;
    while (1 << max_log <= n + 1) {
        max_log++;
    }

    auto dp = make<int>(0, n + 1, max_log + 1);
    for (int i = 0; i < n ; i++) {
        dp[i][0] = tree->query(i + 1, n, a[i]);
    }
	dp[n][0] = n;
    for (int i = 1; i <= max_log; i++) {
        for (int v = 0; v <= n; v++) {
            dp[v][i] = dp[dp[v][i - 1]][i - 1];
        }
    }

    while (q--) {
        int s, d;
        cin >> s >> d, s--;
        int v = s;
        for (int i = max_log; i >= 0; i--) {
            if ((1 << i) <= d) {
                v = dp[v][i];
                d -= (1 << i);
            }
        }
        cout << (v == n ? "leik lokid" : to_string(v + 1)) << "\n";
    }
}
