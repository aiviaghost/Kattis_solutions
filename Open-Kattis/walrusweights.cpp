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

auto closest(int w, int a, int b) -> int {
	int diff_a = abs(w - a), diff_b = abs(w - b);
	if (diff_a < diff_b) {
		return a;
	}
	else if (diff_b < diff_a) {
		return b;
	}
	else {
		return max(a, b);
	}
}

auto main() -> int {
	cin.tie(0)->sync_with_stdio(0);
	
	const int target = 1000;
	int n;
	cin >> n;
	vector<int> W(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> W[i];
	}
	auto dp = make<int>(0, n + 1, 2 * target + 1);
	for (int i = 1; i <= n; i++) {
		for (int w = 0; w <= 2 * target; w++) {
			if (w - W[i] >= 0) {
				dp[i][w] = closest(w, dp[i - 1][w - W[i]] + W[i], dp[i - 1][w]);
			}
			else {
				dp[i][w] = closest(w, W[i], dp[i - 1][w]);
			}
		}
	}
	cout << dp[n][target] << "\n";
}
