#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    vector<vector<string>> answers;

    int n, m, q;
    while (cin >> n >> m >> q) {
        if (n == 0 && m == 0 && q == 0) {
            break;
        }

        vector<vector<int>> dist(n, vector<int>(n, INF));

        for (int u = 0; u < n; u++) {
            dist[u][u] = 0;
        }

        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            dist[u][v] = min(w, dist[u][v]); // apparently we want to keep negative weights along the main diagonal but not positive, idk
        }
    
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    int alt_dist = dist[i][k] + dist[k][j];
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(alt_dist, dist[i][j]);
                    } 
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int t = 0; t < n; ++t) {
                    if (dist[i][t] != INF && dist[t][t] < 0 && dist[t][j] != INF) {
                        dist[i][j] = -INF; 
                    }
                }
            }
        }

        vector<string> current_answers;
        while (q--) {
            int s, t;
            cin >> s >> t;
            
            if (dist[s][t] == -INF) {
                current_answers.push_back("-Infinity");
            }
            else if (dist[s][t] == INF) {
                current_answers.push_back("Impossible");
            }
            else {
                current_answers.push_back(to_string(dist[s][t]));
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
