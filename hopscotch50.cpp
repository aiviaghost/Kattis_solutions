#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using pip = pair<int, pii>;

auto get_manhattan_dist(pii p1, pii p2) -> int {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> grid(n, vector<int>(n));
    unordered_map<int, vector<pii>> adj;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            adj[val].push_back({j, i});
            grid[i][j] = val;
        }
    }

    int shortest_dist = numeric_limits<int>::max();

    if (!adj[1].empty()) {
        for (pii s_node : adj[1]) { // run dijkstra from every 1-node
            if (grid[s_node.second][s_node.first] == k) {
                shortest_dist = 0;
                break;
            }

            vector<vector<int>> dist(n, vector<int>(n, numeric_limits<int>::max())), vis(n, vector<int>(n, -1));
            dist[s_node.second][s_node.first] = 0;
            priority_queue<pip, vector<pip>, greater<pip>> pq;
            pq.push({0, {s_node.first, s_node.second}});

            while (!pq.empty()) {
                pip curr = pq.top();
                pq.pop();

                if (vis[curr.second.second][curr.second.first] != -1) {
                    continue;
                }

                vis[curr.second.second][curr.second.first] = 1;

                if (!adj[grid[curr.second.second][curr.second.first] + 1].empty()) {
                    for (pii next : adj[grid[curr.second.second][curr.second.first] + 1]) {
                        int alt_dist = dist[curr.second.second][curr.second.first] + get_manhattan_dist(curr.second, next);
                        if (alt_dist < dist[next.second][next.first]) {
                            shortest_dist = (grid[next.second][next.first] == k ? min(alt_dist, shortest_dist) : shortest_dist);
                            dist[next.second][next.first] = alt_dist;
                            pq.push({dist[next.second][next.first], {next.first, next.second}});
                        }
                    }
                }
            }
        }
    }
    
    cout << (shortest_dist == numeric_limits<int>::max() ? "-1" : to_string(shortest_dist)) << "\n";
}
