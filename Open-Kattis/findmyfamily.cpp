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
		set<int> left, right;
		left.emplace(a[0]);
		for (int i = 2; i < n; i++) {
			right.emplace(a[i]);
		}
		for (int i = 1; i < n - 1; i++) {
			auto lp = left.upper_bound(a[i]);
            if (lp != left.end()) {
			    int l = *lp, r = *right.rbegin();
			    if (l > a[i] && r > l) {
			    	ans.push_back(k);
			    	break;
			    }
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
