#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using pii = pair<int, int>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        pii nodes[n + 2];
        for (int i = 0; i < n + 2; i++) {
            int x, y;
            cin >> x >> y;
            nodes[i] = {x, y};
        }

        vector<pii> adj[n + 2];
        for (int i = 0; i < n + 1; i++) {
            for (int j = i + 1; j < n + 2; j++) {
                int w = abs(nodes[i].first - nodes[j].first) + abs(nodes[i].second - nodes[j].second);
                adj[i].push_back({j, w});
                adj[j].push_back({i, w});
            }
        }

        bool vis[n + 2];
        memset(vis, 0, sizeof(vis));
        vector<int> dist(n + 2, INF);
        dist[0] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});
    
        while (!pq.empty()) {
            pii curr = pq.top();
            pq.pop();

            if (vis[curr.second]) {
                continue;
            }

            vis[curr.second] = true;

            for (pii next : adj[curr.second]) {
                int alt_dist = dist[curr.second] + next.second;
                if (alt_dist < dist[next.first] && next.second <= 1000) {
                    dist[next.first] = alt_dist;
                    pq.push({alt_dist, next.first});
                }
            }
        }

        cout << (dist.back() != INF ? "happy" : "sad") << "\n";
    }
}
