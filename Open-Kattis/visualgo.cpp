#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int V, E;
    cin >> V >> E;

    unordered_map<int, vector<pii>> adj;
    while (E--) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    
    int s, t;
    cin >> s >> t;

    unordered_set<int> vis;
    vector<int> dist(V, numeric_limits<int>::max());
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});

    vector<int> ways_to_get_here(V);
    ways_to_get_here[s] = 1;

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
                ways_to_get_here[next.first] = ways_to_get_here[curr.second];
                dist[next.first] = alt_dist;
                pq.push({dist[next.first], next.first});
            }
            else if (alt_dist == dist[next.first]) {
                ways_to_get_here[next.first] += ways_to_get_here[curr.second];
            }
        }
    }

    cout << ways_to_get_here[t] << "\n";

    return 0;
}
