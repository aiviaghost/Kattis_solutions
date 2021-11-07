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

	int T;
	cin >> T;
	while (T--) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		if (d < 1000) {
			ll ans = -INF;
			for (ll i = 0; i <= d; i++) {
				for (ll j = 0; j <= d - i; j++) {
					ll k = d - i - j;
					ll maybe_ans = (a + i) * (a + i) + (b + j) * (b + j) + (c + k) * (c + k) + 7 * min(a + i, min(b + j, c + k));
					ans = max(maybe_ans, ans);
				}
			}
			cout << ans << "\n";
		}
		else {
			vector<ll> x = {a, b, c};
			sort(x.begin(), x.end());
			ll ans = x[0] * x[0] + x[1] * x[1] + (x[2] + d) * (x[2] + d) + 7 * min(x[0], min(x[1], x[2] + d));
			cout << ans << "\n";
		}
	}
}
