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

	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			adj[i].push_back(j);
		}
	}

	if (m < n - 1 || m > (n * (n - 1)) / 2) {
		cout << -1 << "\n";
		return 0;
	}

	vector<pii> edges;
	unordered_set<int> seen;
	for (int i = 0; i < n - 1; i++) {
		edges.push_back({i, i + 1});
		seen.emplace(i + i + 1);
	}

	for (int i = 0; i < n; i++) {
		for (int next : adj[i]) {
			if (edges.size() < m && seen.find(i + next) == seen.end()) {
				edges.push_back({i, next});
				seen.emplace(i + next);
			}
		}
	}

	if (edges.size() == m) {
		for (pii edge : edges) {
			cout << edge.first + 1 << " " << edge.second + 1 << "\n";
		}
	}
	else {
		cout << -1 << "\n";
	}
}
