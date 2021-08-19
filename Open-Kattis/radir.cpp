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

	vector<unordered_set<int>> seen_vals(4);
	vector<vector<pii>> suits(4);
	int n, p;
	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		int suit, val;
		cin >> suit >> val, suit--;
		if (seen_vals[suit].find(val) == seen_vals[suit].end()) {
			seen_vals[suit].emplace(val);
			suits[suit].push_back({val, i});
		}
	}
	int ans = INF;
	for (int suit = 0; suit < 4; suit++) {
		sort(suits[suit].begin(), suits[suit].end());
		for (int i = 0; i < suits[suit].size(); i++) {
			if (i + 2 < suits[suit].size()) {
				if (suits[suit][i].first == suits[suit][i + 1].first - 1 && suits[suit][i + 1].first == suits[suit][i + 2].first - 1) {
					int highest_index = max(suits[suit][i].second, max(suits[suit][i + 1].second, suits[suit][i + 2].second));
					ans = min((highest_index < p ? 0 : highest_index - p + 1), ans);
				}
			}
		}
	}
	cout << (ans == INF ? "neibb" : to_string(max(ans, 1))) << "\n";
}
