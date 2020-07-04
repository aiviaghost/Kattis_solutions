#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

struct edge {
    int vertex, cap, cost;
};

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    unordered_map<int, vector<edge>> adj;
    while (m--) {
        int u, v, c, w;
        cin >> u >> v >> c >> w;
        adj[u].push_back({v, c, w});
    }

    vector<int> max_flow_yet(n);
    max_flow_yet[s] = numeric_limits<int>::max();
    unordered_set<int> vis;
    priority_queue<pii> pq;
    pq.push({numeric_limits<int>::max(), s});
    // unordered_map<int, int> parents;
    vector<int> min_cost_yet(n, numeric_limits<int>::max());
    min_cost_yet[s] = 0;

    while (!pq.empty()) {
        pii curr = pq.top();
        pq.pop();

        if (vis.find(curr.second) != vis.end()) {
            continue;
        }

        vis.emplace(curr.second);

        for (edge next : adj[curr.second]) {
            int alt_flow = min(max_flow_yet[curr.second], next.cap);
            if (alt_flow > max_flow_yet[next.vertex]) {
                // min_cost_yet[next.vertex] = min_cost_yet[curr.second] + alt_flow * next.cost;
                max_flow_yet[next.vertex] = alt_flow;
                // parents[next.vertex] = curr.second;
                pq.push({max_flow_yet[next.vertex], next.vertex});
            }
            else if (alt_flow == max_flow_yet[next.vertex]) {
                // parents[next.vertex] = curr.second;
                min_cost_yet[next.vertex] = min(min_cost_yet[curr.second] + alt_flow * next.cost, min_cost_yet[next.vertex]);
            }
        }
    }
    /*
    int min_cost = 0;
    int curr = t;
    while (curr != s) {
        for (edge e : adj[parents[curr]]) {
            if (e.vertex = curr) {
                min_cost += max_flow_yet[t] * e.cost;
                break;
            }
        }
        curr = parents[curr];
    }
    */
    cout << max_flow_yet[t] << " " << min_cost_yet[t] << "\n";
}
