#include <bits/stdc++.h>

using namespace std;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int n, t;
        cin >> n >> t;
        vector<int> neighbours(n);
        for (int i = 0; i < n; i++) {
            cin >> neighbours[i];
        }

        vector<int> dist(3601, -1);
        dist[0] = 0;
        vector<int> curr_layer{0};

        while (!curr_layer.empty()) {
            vector<int> next_layer;
            for (int c : curr_layer) {
                for (int next : neighbours) {
                    int nx = min(c + next, 3600);
                    if (0 <= nx && dist[nx] == -1) {
                        dist[nx] = dist[c] + 1;
                        next_layer.push_back(nx);
                    }
                }
            }
            curr_layer = next_layer;
        }

        for (int i = t; i < 3601; i++) {
            if (dist[i] != -1) {
                cout << dist[i] << " " << i - t << "\n";
                break;
            }
        }
    }
}
