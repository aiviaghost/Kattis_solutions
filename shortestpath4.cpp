

// seems to be issue with k < V and cases with small V


#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int TC;
    cin >> TC;

    vector<vector<int>> answers;

    while (TC--) {
        int V;
        cin >> V;

        unordered_map<int, vector<pii>> adj;
        for (int i = 0; i < V; i++) {
            int x;
            cin >> x;
            while (x--) {
                int dest, w;
                cin >> dest >> w;
                adj[i].push_back({dest, w});
            }
        }

        int q;
        cin >> q;

        vector<int> current_answers;

        while (q--) {
            int s, t, k;
            cin >> s >> t >> k;
            
            unordered_set<int> vis;
            vector<int> dist(V, numeric_limits<int>::max());
            dist[s] = 0;
            priority_queue<pii, vector<pii>, greater<pii>> pq;
            pq.push({0, s});

            vector<int> junctions_so_far(V);
            junctions_so_far[s] = 1;

            while (!pq.empty()) {
                pii curr = pq.top();
                pq.pop();

                if (vis.find(curr.second) != vis.end()) {
                    continue;
                }

                vis.emplace(curr.second);

                for (pii next : adj[curr.second]) {
                    int alt_dist = dist[curr.second] + next.second;
                    if (alt_dist < dist[next.first] && junctions_so_far[curr.second] + 1 <= k) {
                        junctions_so_far[next.first] = junctions_so_far[curr.second] + 1;
                        dist[next.first] = alt_dist;
                        pq.push({dist[next.first], next.first});
                    }
                    else if (alt_dist == dist[next.first]) {
                        junctions_so_far[next.first] = min(junctions_so_far[curr.second] + 1, junctions_so_far[next.first]);
                    }
                }
            }

            for (int d : dist) {
                cout << d << " ";
            }

            current_answers.push_back((junctions_so_far[t] <= k && dist[t] < numeric_limits<int>::max()) ? dist[t] : -1);
        }

        answers.push_back(current_answers);
    }

    for (int i = 0; i < answers.size(); i++) {
        for (int ans : answers[i]) {
            cout << ans << "\n";
        }

        if (i != answers.size() - 1) {
            cout << "\n";
        }
    }

    return 0;
}
