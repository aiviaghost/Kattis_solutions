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

	int N, B;
	while (cin >> N >> B && N != -1) {
		vector<int> pops(N);
		int largest_population = -1;
		for (int i = 0; i < N; i++) {
			cin >> pops[i];
			largest_population = max(pops[i], largest_population);
		}
		auto fill = [&](int max_p) {
			bool valid = true;
			int available = B;
			for (int i = 0; i < N; i++) {
				int needed = ceil(pops[i] / (double)min(pops[i], max_p));
				if (needed <= available) {
					available -= needed;
				}
				else {
					valid = false;
					break;
				}
			}
			return valid;
		};
		int lb = 1, rb = largest_population, mid, ans = INF;
		while (lb < rb) {
			mid = lb + (rb - lb) / 2;
			if (fill(mid)) {
				rb = mid;
				ans = min(mid, ans);
			}
			else {
				lb = mid + 1;
			}
		}
		cout << ans << "\n";
	}
}
