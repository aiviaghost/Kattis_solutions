#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using pii = pair<int, int>;
using pdd = pair<double, double>;

// dfs to find if node[v] is connected to node[n - 1]
auto is_connected(int &n, vector<int> adj[], unordered_set<int> &vis, int v) -> bool {
    if (vis.find(v) != vis.end()) {
        return false;
    }

    if (v == n - 1) {
        return true;
    }

    vis.emplace(v);

    for (int next : adj[v]) {
        if (is_connected(n, adj, vis, next)) {
            return true;
        }
    }

    return false;
}

// dfs to find if node[v] is part of a positive cycle
auto positive_cycle(vector<int> adj[], unordered_set<int> &vis, int v, bool &has_positive_cycle, vector<int> &sum, int weight[], int running_sum, int &org_v) -> void {
    running_sum += weight[v];

    if (running_sum <= 0 || sum[v] == INF) {
        return;
    }

    if (vis.find(v) != vis.end()) {
        if (v == org_v && running_sum > sum[org_v]) {
            has_positive_cycle = true;
        }
        return;
    }

    vis.emplace(v);

    for (int next : adj[v]) {
        positive_cycle(adj, vis, next, has_positive_cycle, sum, weight, running_sum, org_v);
    }
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    while (cin >> n && n != -1) {
        int weight[n];
        vector<int> adj[n];
        for (int i = 0; i < n; i++) {
            cin >> weight[i];
            int cr;
            cin >> cr;
            adj[i].resize(cr);
            for (int j = 0; j < cr; j++) {
                cin >> adj[i][j], adj[i][j]--;
            }
        }
        
        // spfa to check if "normal path" exists from node[0] to node[n - 1]
        vector<int> sum(n, INF);
        sum[0] = 100;
        int vis_count[n];
        memset(vis_count, 0, 4 * n);
        queue<int> q;
        q.push(0);
        unordered_set<int> in_q{0};
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            in_q.erase(curr);
            vis_count[curr]++;
            if (vis_count[curr] < n) {
                for (int next : adj[curr]) {
                    int alt_sum = sum[curr] + weight[next];
                    if (0 < alt_sum && alt_sum < sum[next]) {
                        sum[next] = alt_sum;
                        if (in_q.find(next) == in_q.end()) {
                            q.push(next);
                            in_q.emplace(next);
                        }
                    }
                }
            }
        }

        unordered_set<int> vis;
        // can node[n - 1] be reached from node[v]
        bool can_reach[n];
        memset(can_reach, 0, n);
        for (int v = 0; v < n - 1; v++) {
            if (is_connected(n, adj, vis, v)) {
                can_reach[v] = 1;
            }
            vis.clear();
        }

        // check if positive cycle exists and if node[n - 1] is reachable from potential positive cycle
        bool has_positive_cycle = false;
        for (int v = 0; v < n - 1; v++) {
            if (sum[v] < INF) {
                positive_cycle(adj, vis, v, has_positive_cycle, sum, weight, sum[v], v);
            }

            if (!can_reach[v]) {
                has_positive_cycle = false;
            }

            if (has_positive_cycle) {
                break;
            }
            
            vis.clear();
        }

        cout << (can_reach[0] && (sum[n - 1] < INF || has_positive_cycle) ? "winnable" : "hopeless") << "\n";
    }
}
