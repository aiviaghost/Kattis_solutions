#include <bits/stdc++.h>

using namespace std;

using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(4);

    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }

        unordered_map<int, vector<pdd>> adj;
        while (m--) {
            int x, y;
            double f;
            cin >> x >> y >> f;
            adj[x].push_back({y, f});
            adj[y].push_back({x, f});
        }

        vector<double> curr_size(n);
        curr_size[0] = 1;
        unordered_set<int> vis;
        priority_queue<pdd> pq;
        pq.push({1.0, 0.0});

        while (!pq.empty()) {
            pdd curr = pq.top();
            pq.pop();

            if (vis.find(curr.second) != vis.end()) {
                continue;
            }

            vis.emplace(curr.second);

            for (pdd next : adj[curr.second]) {
                double alt_size = curr_size[curr.second] * next.second;
                if (alt_size > curr_size[next.first]) {
                    curr_size[next.first] = alt_size;
                    pq.push({curr_size[next.first], next.first});
                }
            }
        }

        cout << curr_size[n - 1] << "\n";
    }
}
