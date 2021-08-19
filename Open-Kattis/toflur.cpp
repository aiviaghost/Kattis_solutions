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

	int n;
	cin >> n;
	vector<int> tiles(n);
	for (int i = 0; i < n; i++) {
		cin >> tiles[i];
	}
	/*if (n == 1) {
		cout << tiles[0] << "\n";
		return 0;
	}*/
	sort(tiles.begin(), tiles.end());
	ll sum = 0;
	for (int i = 0; i < n - 1; i++) {
		sum += pow(tiles[i] - tiles[i + 1], 2);
	}
	cout << sum << "\n";
}
