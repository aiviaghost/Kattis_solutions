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

int n, coins[101], dp[101][(int)2e6];

int greedy(int target) {
	int res = 0, i = n;
	while (target > 0) {
		if (target - coins[i] >= 0) {
			target -= coins[i];
			res++;
		}
		else {
			i--;
		}
	}
	return res;
}

auto main() -> int {
	cin.tie(0)->sync_with_stdio(0);

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < (int)2e6; j++) {
			dp[i][j] = INF;
		}
	}

	cin >> n;
	// vector<int> coins(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> coins[i];
	}
	int max_sum = coins[n] + coins[n - 1];
	// auto dp = make<int>(INF, n + 1, max_sum + 1);
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= max_sum; j++) {
			if (j - coins[i] >= 0) {
				dp[i][j] = min(dp[i][j - coins[i]] + 1, dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}/*
	for (int i = 1; i <= max_sum; i++) {
		cout << i << ": " << dp[n][i] << " " << greedy(i) << endl;
	}*/
	bool is_canonical = true;
	for (int i = 1; i <= max_sum; i++) {
		if (dp[n][i] < greedy(i)) {
			is_canonical = false;
			break;
		}
	}
	cout << (is_canonical ? "canonical\n" : "non-canonical\n");
}
