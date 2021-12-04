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

	double d, s;
	cin >> d >> s;
	double EPS = 1e-10, lb = 0, rb = 125001, mid;
	while (rb - lb > EPS) {
		mid = lb + (rb - lb) / 2;
		double guess = mid + s - mid * cosh(d / (2 * mid));
		if (guess > 0) {
			rb = mid;
		}
		else {
			lb = mid;
		}
	}
	cout << fixed << setprecision(10) << 2 * mid * sinh(d / (2 * mid)) << "\n";
}
