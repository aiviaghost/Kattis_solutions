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

const ll INF64 = 2e18;	
const int delft = 0, amserdam = 1;

set<pii> to_remove;

vector<pii> dijkstra(vector<vector<pii>> & adj, int s, int t) {
	int n = adj.size();
	vector<ll> dist(n, INF64);
	dist[s] = 0;
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	pq.push({0, s});
	vector<int> par(n, -1);
	while (!pq.empty()) {
		auto [cd, curr] = pq.top();
		pq.pop();
		if (cd > dist[curr]) {
			continue;
		}
		to_remove.emplace(make_pair(curr, par[curr]));
		for (auto [next, w] : adj[curr]) {
			ll alt = cd + w;
			if (alt < dist[next]) {
				dist[next] = alt;
				par[next] = curr;
				pq.push({alt, next});
			}
		}
	}
	vector<pii> path;
	if (dist[t] != INF64) {
		int curr = t;
		while (curr != s) {
			path.push_back(make_pair(par[curr], curr));
			curr = par[curr];
		}
		reverse(all(path));
	}
	return path;
}

auto main() -> int {
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	vector<vector<pii>> adj(n);
	for (int i = 0; i < m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		adj[a].push_back({b, d});
		adj[b].push_back({a, d});
	}
	dijkstra(adj, amserdam, delft);
	vector<vector<pii>> new_adj(n);
	for (int u = 0; u < n; u++) {
		for (auto [v, d] : adj[u]) {
			if (!to_remove.count({u, v})) {
				new_adj[u].push_back({v, d});
			}
		}
	}
	vector<pii> ans = dijkstra(new_adj, delft, amserdam);
	if (ans.empty()) {
		cout << "impossible\n";
	}
	else {
		cout << ans.size() + 1 << " " << ans[0].first << " " << ans[0].second;
		for (int i = 1; i < ans.size(); i++) {
			cout << " " << ans[i].second;
		}
		cout << "\n";
	}
}
