#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

void dfs(int &curr, unordered_map<int, vector<pii>> &adj, unordered_set<int> &vis) {
    if (vis.find(curr) != vis.end()) {
        return;
    }

    vis.emplace(curr);

    for (pii next : adj[curr]) {
        dfs(next.first, adj, vis);    
    }
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    vector<vector<string>> answers;
    int n, m, q, s;
    while (cin >> n >> m >> q >> s) {
        if (n == 0 && m == 0 && q == 0 && s == 0) {
            break;
        }

        unordered_map<int, vector<pii>> adj;
        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
        }

        // start of spfa
        vector<int> dist(n, numeric_limits<int>::max());
        dist[s] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, s});
        unordered_set<int> in_pq;
        in_pq.emplace(s);
        vector<int> visits(n);
        
        while (!pq.empty()) {
            pii curr = pq.top();
            pq.pop();
            in_pq.erase(curr.second);
            visits[curr.second] += 1;

            if (visits[curr.second] < n) {
                for (pii next : adj[curr.second]) {
                    int alt_dist = dist[curr.second] + next.second;
                    if (alt_dist < dist[next.first]) {
                        dist[next.first] = alt_dist;
                        if (in_pq.find(next.first) == in_pq.end()) {
                            pq.push({dist[next.first], next.first});
                            in_pq.emplace(next.first);
                        }
                    }
                }
            }
        }
        //end of spfa

        // start dfs to find negative cycles
        unordered_set<int> vis;
        for (int v = 0; v < n; v++) {
            if (visits[v] == n) {
                dfs(v, adj, vis);
            }
        }

        for (int v = 0; v < n; v++) {
            if (vis.find(v) != vis.end()) {
                dist[v] = numeric_limits<int>::min();
            }
        }
        // end of dfs
        
        vector<string> current_answers;
        while (q--) {
            int t;
            cin >> t;
            if (dist[t] == numeric_limits<int>::max()) {
                current_answers.push_back("Impossible");
            }
            else if (dist[t] == numeric_limits<int>::min()) {
                current_answers.push_back("-Infinity");
            }
            else {
                current_answers.push_back(to_string(dist[t]));
            }
        }
        answers.push_back(current_answers);
    }

    for (int i = 0; i < answers.size(); i++) {
        for (string ans : answers[i]) {
            cout << ans << "\n";
        }

        if (i != answers.size() - 1) {
            cout << "\n";
        }
    }
}
