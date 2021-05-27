#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

struct edge {
    int vertex, d, t0, P;
};

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    vector<vector<string>> answers;

    int n, m, q, s;
    while (cin >> n >> m >> q >> s) {
        if (n == 0 && m == 0 && q == 0 && s == 0) {
            break;
        }
        
        unordered_map<int, vector<edge>> adj;
        while (m--) {
            int u, v, t0, P, d;
            cin >> u >> v >> t0 >> P >> d;
            adj[u].push_back({v, d, t0, P});
        }

        vector<int> time(n, numeric_limits<int>::max());
        time[s] = 0;
        unordered_set<int> vis;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, s});
        
        while (!pq.empty()) {
            pii curr = pq.top();
            pq.pop();

            if (vis.find(curr.second) != vis.end()) {
                continue;
            }

            vis.emplace(curr.second);

            for (edge next : adj[curr.second]) {
                int alt_time;
                if (time[curr.second] <= next.t0) {
                    alt_time = next.t0 + next.d;
                }
                else if (next.P > 0 && time[curr.second] >= next.t0 && (time[curr.second] - next.t0) % next.P == 0) {
                    alt_time = time[curr.second] + next.d;
                }
                else if (next.P > 0) {
                    alt_time = next.t0 + next.P * ceil((time[curr.second] - next.t0) / (double) next.P) + next.d;
                }
                else {
                    continue;
                }

                if (alt_time < time[next.vertex]) {
                    time[next.vertex] = alt_time;
                    pq.push({time[next.vertex], next.vertex});
                }
            }

        }

        vector<string> current_answers;
        while (q--) {
            int t;
            cin >> t;
            current_answers.push_back(time[t] == numeric_limits<int>::max() ? "Impossible" : to_string(time[t]));
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
