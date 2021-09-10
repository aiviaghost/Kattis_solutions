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
	vector<int> guests(n);
	for (int i = 0; i < n; i++) {
		cin >> guests[i];
	}
	vector<pii> a;
	a.reserve(n);
	for (int i = 0; i < n; i++) {
		a.push_back({guests[i], i});
	}
	sort(a.begin(), a.end());
	int ans = n, prev = guests[0], prev_i = 0;
	for (int i = 1; i < n; i++) {
		if (a[i].first == prev) {
			ans = min(a[i].second - a[prev_i].second, ans);
		}
		else {
			prev = a[i].first;
			prev_i = i;
		}
	}
	cout << ans << "\n";
}
