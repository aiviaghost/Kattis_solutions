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

auto main() -> int {
	cin.tie(0)->sync_with_stdio(0);

	int C, n;
	while (cin >> C >> n) {
		vector<int> V(n + 1), W(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> V[i] >> W[i];
		}
		auto dp = make<int>(0, n + 1, C + 1);
		auto par = make<pii>({-1, -1}, n + 1, C + 1);
		auto take = make<bool>(false, n + 1, C + 1);
		for (int i = 1; i <= n; i++) {
			for (int w = 1; w <= C; w++) {
				if (W[i] > w) {
					dp[i][w] = dp[i - 1][w];
					par[i][w] = {i - 1, w};
					take[i][w] = false;
				}
				else {
					if (dp[i - 1][w - W[i]] + V[i] < dp[i - 1][w]) {
						dp[i][w] = dp[i - 1][w];
						par[i][w] = {i - 1, w};
						take[i][w] = false;
					}
					else {
						dp[i][w] = dp[i - 1][w - W[i]] + V[i];
						par[i][w] = {i - 1, w - W[i]};
						take[i][w] = true;
					}
				}
			}			
		}
		vector<int> indices;
		pii curr = {n, C};
		while (curr != make_pair(-1, -1)) {
			if (take[curr.first][curr.second]) {
				indices.push_back(curr.first);
			}
			curr = par[curr.first][curr.second];
		}
		cout << indices.size() << "\n";
		if (!indices.empty()) {
			cout << indices[0] - 1;
			for (int i = 1; i < indices.size(); i++) {
				cout << " " << indices[i] - 1;
			}
			cout << "\n";
		}
	}
}
