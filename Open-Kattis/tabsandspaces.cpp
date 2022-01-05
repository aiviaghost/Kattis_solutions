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

auto main() -> int {
	cin.tie(0)->sync_with_stdio(0);

	int F;
	cin >> F;
	vector<vector<int>> files(F);
	for (int i = 0; i < F; i++) {
		int L;
		cin >> L;
		files[i].resize(L);
		for (int j = 0; j < L; j++) {
			cin >> files[i][j];
		}
	}
	int optimal_len = INF, optimal_space_saved = -INF;
	for (int len = 1; len < 80; len++) {
		int space_saved = 0;
		for (int i = 0; i < F; i++) {
			for (int j = 0; j < files[i].size(); j++) {
				if (len <= files[i][j]) {
					int fill = files[i][j] / len;
					space_saved += files[i][j] - (fill + (files[i][j] - fill * len));
				}
			}
		}
		if (space_saved > optimal_space_saved) {
			optimal_space_saved = space_saved;
			optimal_len = len;
		}
	}
	cout << optimal_len << "\n";
	cout << optimal_space_saved << "\n";
}
