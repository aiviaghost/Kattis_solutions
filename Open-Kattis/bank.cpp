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

	int N, T;
	cin >> N >> T;
	vector<pii> q;
	q.reserve(N);
	for (int i = 0; i < N; i++) {
		int c, t;
		cin >> c >> t;
		q.push_back({c, t});
	}
	sort(q.begin(), q.end(), [&](pii& p1, pii& p2) {
		return (p1.first > p2.first) || (p1.first == p2.first && p1.second > p2.second);
	});
	int ans = 0;
	vector<bool> taken(T);
	for (pii p : q) {
		for (int i = p.second; i >= 0; i--) {
			if (!taken[i]) {
				taken[i] = true;
				ans += p.first;
				break;
			}
		}
	}
	cout << ans << "\n";
}
