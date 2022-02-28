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

#define all(x) x.begin(), x.end()

const int INF = 2e9;

double C(int n, int k) {
	int tot = 1;
	for (int i = k + 1; i <= n; i++) {
		tot *= i;
	}
	for (int i = 1; i <= n - k; i++) {
		tot /= i;
	}
	return tot;
}

auto main() -> int {
	cin.tie(0)->sync_with_stdio(0);
	
	int n;
	cin >> n;
	while (n--) {
		int r, s, x, y, w;
		cin >> r >> s >> x >> y >> w;
		double p = (s - r + 1) / (double) s;
		double tot = 0;
		for (int k = x; k <= y; k++) {
			tot += pow(p, k) * pow(1 - p, y - k) * C(y, k);
		}
		if (tot * w > 1.0) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
}
