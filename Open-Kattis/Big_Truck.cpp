#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> items(n), sum(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i];
        sum[i] = items[i];
    }

    int m;
    cin >> m;

    unordered_map<int, vector<pii>> adj;
    while (m--) {
        int a, b, d;
        cin >> a >> b >> d;
        adj[a - 1].push_back({b - 1, d});
        adj[b - 1].push_back({a - 1, d});
    }

    vector<int> dist(n, numeric_limits<int>::max());
    dist[0] = 0;
    unordered_set<int> vis;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});

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
                sum[next.first] = sum[curr.second] + items[next.first];
                dist[next.first] = alt_dist;
                pq.push({dist[next.first], next.first});
            }

            if (alt_dist == dist[next.first]) {
                sum[next.first] = max(sum[curr.second] + items[next.first], sum[next.first]);
            }
        }
    }

    cout << (dist[n - 1] == numeric_limits<int>::max() ? "impossible" : to_string(dist[n - 1]) + " " + to_string(sum[n - 1])) << "\n";

    return 0;
}
