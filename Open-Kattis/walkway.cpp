#include <bits/stdc++.h>

using namespace std;

using pdd = pair<double, double>;

const int INF = numeric_limits<int>::max();

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(2);

    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }

        unordered_map<int, vector<pdd>> adj;
        for (int i = 0; i < n; i++) {
            int a, b, h;
            cin >> a >> b >> h;
            double w = 0.01 * (a + b) * h;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }

        int s, t;
        cin >> s >> t;

        if (s == t) {
            cout << 0.00 << "\n";
            continue;
        }

        unordered_set<int> vis;
        unordered_map<int, double> cost;
        for (unordered_map<int, vector<pdd>>::iterator itr = adj.begin(); itr != adj.end(); itr++) {
            cost[itr->first] = INF;
        }
        cost[s] = 0;
        cost[t] = INF;
        priority_queue<pdd, vector<pdd>, greater<pdd>> pq;
        pq.push({0, s});

        while (!pq.empty()) {
            pdd curr = pq.top();
            pq.pop();

            if (vis.find(curr.second) != vis.end()) {
                continue;
            }

            vis.emplace(curr.second);

            for (pdd next : adj[curr.second]) {
                double alt_cost = cost[curr.second] + next.second;
                if (alt_cost < cost[next.first]) {
                    cost[next.first] = alt_cost;
                    pq.push({alt_cost, next.first});
                }
            }
        }

        cout << cost[t] << "\n";
    }
}
