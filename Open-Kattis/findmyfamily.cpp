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
    segment_tree *left = 0, *right = 0;
    int lb, rb, val;
    segment_tree(vector<int>& a, int lb, int rb): lb(lb), rb(rb) {
        if (lb == rb) {
			val = a[lb];
		}
		else {
            int mid = lb + (rb - lb) / 2;
            left = new segment_tree(a, lb, mid);
            right = new segment_tree(a, mid + 1, rb);
			val = max(left->val, right->val);
		}
    }

    int query(int lb, int rb) {
        if (this->rb < lb || this->lb > rb) {
            return 0;
        }

        if (lb <= this->lb && this->rb <= rb) {
            return val;
        }

        return max(left->query(lb, rb), right->query(lb, rb));
    }
};

auto main() -> int {
	cin.tie(0)->sync_with_stdio(0);

	vector<int> ans;
	int K;
	cin >> K;
	for (int k = 1; k <= K; k++) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		if (n < 3) {
			continue;
		}
		set<int> left, right;
		left.emplace(a[0]);
		for (int i = 2; i < n; i++) {
			right.emplace(a[i]);
		}
		for (int i = 1; i < n - 1; i++) {
			auto lp = left.upper_bound(a[i]);
			if (lp == left.end()) {
				left.emplace(a[i]);
				right.erase(a[i + 1]);
				continue;
			}
			auto rp = right.upper_bound(*lp);
			if (rp == right.end()) {
				left.emplace(a[i]);
				right.erase(a[i + 1]);
				continue;
			}
			int l = *lp, r = *rp;
			if (l > a[i] && r > l) {
				ans.push_back(k);
				break;
			}
			left.emplace(a[i]);
			right.erase(a[i + 1]);
		}
	}
	cout << ans.size() << "\n";
	for (int i : ans) {
		cout << i << "\n";
	}
}
