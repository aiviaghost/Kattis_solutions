#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, s, t;
    cin >> n >> s >> t;

    unordered_map<int, vector<pii>> adj;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int w;
            cin >> w;
            adj[i].push_back({j, w});
        }
    }

    unordered_set<int> vis;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    vector<int> dist(n, numeric_limits<int>::max());
    dist[s] = 0;

    while (!pq.empty()) {
        pii curr = pq.top();
        pq.pop();

        if (vis.find(curr.second) != vis.end()) {
            continue;
        }

        vis.emplace(curr.second);

        for (pii next : adj[curr.second]) {
            int alt_dist = dist[curr.second] + next.second;
            if (alt_dist < dist[next.first]) {
                dist[next.first] = alt_dist;
                pq.push({dist[next.first], next.first});
            }
        }
    }

    cout << dist[t] << "\n";

    return 0;
}
