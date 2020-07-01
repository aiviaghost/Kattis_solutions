#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

auto get_dist(int x1, int y1, int x2, int y2) -> int {
    return pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2);
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    deque<pii> coords;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        coords.push_back({x, y});
    }

    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    coords.push_front({sx, sy});
    coords.push_back({tx, ty});

    unordered_map<int, vector<pii>> adj;
    for (int i = 0; i < n + 1; i++) {
        for (int j = i + 1; j < n + 2; j++) {
            int w = get_dist(coords[i].first, coords[i].second, coords[j].first, coords[j].second);
            adj[i].push_back({j, w});
            adj[j].push_back({i, w});
        }
    }

    unordered_set<int> vis;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    vector<int> dist(n + 2, numeric_limits<int>::max());
    dist[0] = 0;
    
    unordered_map<int, int> parents;

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
                parents[next.first] = curr.second;
                dist[next.first] = alt_dist;
                pq.push({dist[next.first], next.first});
            }
        }
    }

    if (parents[n] == 0) {
        cout << "-\n";
    }
    else {
        vector<int> path;
        int curr = parents[n + 1];
        while (curr != 0) {
            path.push_back(curr - 1);
            curr = parents[curr];
        }

        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << "\n";
        }
    }

    return 0;
}
