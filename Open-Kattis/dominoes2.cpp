#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m, l;
        cin >> n >> m >> l;
        vector<int> adj[n];
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v, u--, v--;
            adj[u].push_back(v);
        }
        queue<int> q;
        unordered_set<int> vis;
        for (int i = 0; i < l; i++) {
            int u;
            cin >> u, u--;
            q.push(u);
            vis.emplace(u);
        }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next : adj[curr]) {
                if (vis.find(next) == vis.end()) {
                    vis.emplace(next);
                    q.push(next);
                }
            }
        }
        cout << vis.size() << "\n";
    }
}
