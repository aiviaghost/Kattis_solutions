#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using pip = pair<int, pii>;
using pipip = pair<int, pip>;

auto get_manhattan_dist(pii p1, pii p2) -> int {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    unordered_map<int, vector<pip>> adj;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            adj[val].push_back({val, {j, i}});
        }
    }

    int shortest_dist = numeric_limits<int>::max();

    for (pip s_node : adj[1]) { // run dijkstra from every 1-node
        vector<vector<int>> dist(n, vector<int>(n, numeric_limits<int>::max())), vis(n, vector<int>(n, -1));
        dist[s_node.second.second][s_node.second.first] = 0;
        priority_queue<pipip, vector<pipip>, greater<pipip>> pq;
        pq.push({0, {s_node.first, {s_node.second.first, s_node.second.second}}});

        while (!pq.empty()) {
            pipip curr = pq.top();
            pq.pop();

            if (vis[curr.second.second.second][curr.second.second.first] != -1) {
                continue;
            }

            vis[curr.second.second.second][curr.second.second.first] = 1;
            
            for (pip next : adj[curr.second.first + 1]) {
                int alt_dist = dist[curr.second.second.second][curr.second.second.first] + get_manhattan_dist(curr.second.second, next.second);
                if (alt_dist < dist[next.second.second][next.second.first]) {
                    shortest_dist = (curr.first + 1 == k ? min(alt_dist, shortest_dist) : shortest_dist);
                    dist[next.second.second][next.second.first] = alt_dist;
                    pq.push({dist[next.second.second][next.second.first], {next.first, {next.second.first, next.second.second}}});
                }
            }
        }
    }

    cout << (shortest_dist == numeric_limits<int>::max() ? "-1" : to_string(shortest_dist)) << "\n";
}
