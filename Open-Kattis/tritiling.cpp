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

	vector<int> dp(31);
	dp[0] = 1;
	for (int i = 2; i <= 30; i += 2) {
		dp[i] = 3 * dp[i - 2];
		for (int j = 4; j <= i; j += 2) {
			dp[i] += 2 * dp[i - j];
		}
	}
	int n;
	while (cin >> n && n != -1) {
		cout << dp[n] << "\n";
	}
}
