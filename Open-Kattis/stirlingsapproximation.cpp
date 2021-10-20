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

/*
n! / S(n) = e^(ln(n! / S(n))) = e^(ln(n!) - ln(S(n)))

ln(n!) = sum(i = 0...n)(ln(i))
ln(S(n)) = lln(sqrt(2 * pi * n) * ((n^n) / (e^n)))
		  = ln(sqrt(2 * pi * n)) + ln((n^n) / (e^n))
		  = 0.5 * ln(2 * pi * n) + ln(n^n) - ln(e^n)
		  = 0.5 * ln(2 * pi * n) + ln(n^n) - n
		  = 0.5 * ln(2 * pi * n) + n * ln(n) - n
*/

double log_fac(int n) {
	double res = 0;
	for (int i = 2; i <= n; i++) {
		res += log(i);
	}
	return res;
}

auto main() -> int {
	cin.tie(0)->sync_with_stdio(0);

	double n;
	while (cin >> n && n != 0) {
		double log_res = log_fac(n) - (0.5 * log(2 * M_PI * n) + n * log(n) - n);
		cout << setprecision(30) << fixed << pow(M_E, log_res) << "\n";
	}
}
