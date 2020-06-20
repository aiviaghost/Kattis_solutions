#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    vector<vector<string>> answers;

    int n, m, q, s;
    while (cin >> n >> m >> q >> s) {
        if (n == 0 && m == 0 && q == 0 && s == 0) {
            break;
        }

        unordered_map<int, vector<pii>> L;
        while (m--) {
            int a, b, w;
            cin >> a >> b >> w;
            L[a].push_back({b, w});
        }

        unordered_set<int> vis;
        vector<int> dist(n, numeric_limits<int>::max());
        dist[s] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, s});
            
        while (!pq.empty()) {
            pii curr = pq.top();
            pq.pop();

            if (vis.find(curr.second) != vis.end()) {
                continue;
            }

            vis.emplace(curr.second);

            for (pii next : L[curr.second]) {
                int alt_dist = dist[curr.second] + next.second;
                if (alt_dist < dist[next.first]) {
                    dist[next.first] = alt_dist;
                    pq.push({dist[next.first], next.first});
                }
            }
        }

        vector<string> curr_answers;
        while (q--) {
            int end;
            cin >> end;
            curr_answers.push_back(dist[end] == numeric_limits<int>::max() ? "Impossible" : to_string(dist[end]));
        }
        answers.push_back(curr_answers);
    }

    for (int i = 0; i < answers.size(); i++) {
        for (string s : answers[i]) {
            cout << s << "\n";
        }

        if (i != answers.size() - 1) {
            cout << "\n";
        }
    }

    return 0;
}
