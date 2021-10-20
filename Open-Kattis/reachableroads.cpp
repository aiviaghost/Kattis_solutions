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
	while (n--) {
		int m;
		cin >> m;
		vector<vector<int>> adj(m);
		int r;
		cin >> r;
		for (int i = 0; i < r; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int components = 0;
		vector<bool> vis(m);
		for (int start = 0; start < m; start++) {
			if (vis[start]) {
				continue;
			}
			components++;
			queue<int> q;
			q.push(start);
			vis[start] = true;
			while (!q.empty()) {
				int curr = q.front();
				q.pop();
				for (int next : adj[curr]) {
					if (!vis[next]) {
						vis[next] = true;
						q.push(next);
					}
				}
			}
		}
		cout << components - 1 << "\n";
	}
}
