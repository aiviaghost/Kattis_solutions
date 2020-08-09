#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        pdd nodes[n + 2];
        for (int i = 0; i < n + 2; i++) {
            int x, y;
            cin >> x >> y;
            nodes[i] = {x, y};
        }

        vector<pdd> adj[n + 2];
        for (int i = 0; i < n + 1; i++) {
            for (int j = i + 1; j < n + 2; j++) {
                double w = hypot(abs(nodes[i].first - nodes[j].first), abs(nodes[i].second - nodes[j].second));
                adj[i].push_back({j, w});
                adj[j].push_back({i, w});
            }
        }

        bool vis[n + 2];
        memset(vis, 0, sizeof(vis));
        vector<double> dist(n + 2, INF);
        dist[0] = 0;
        priority_queue<pdd, vector<pdd>, greater<pdd>> pq;
        pq.push({0, 0});
    
        while (!pq.empty()) {
            pdd curr = pq.top();
            pq.pop();

            if (vis[(int) curr.second]) {
                continue;
            }

            vis[(int) curr.second] = true;

            for (pdd next : adj[(int) curr.second]) {
                double alt_dist = dist[curr.second] + next.second;
                if (alt_dist < dist[next.first] && alt_dist <= 1000) {
                    dist[next.first] = alt_dist;
                    pq.push({alt_dist, next.first});
                }
            }
        }

        cout << (dist.back() != INF ? "happy" : "sad") << "\n";
    }
}
