#include <bits/stdc++.h>

using namespace std;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    while (cin >> n) {
        if (n == -1) {
            break;
        }

        vector<vector<int>> adj(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> adj[i][j];
            }
        }

        bool is_weak[n];
        memset(is_weak, true, sizeof(is_weak));
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                for (int w = 0; w < n; w++) {
                    if (adj[u][v] && adj[v][w] && adj[w][u]) {
                        is_weak[u] = false;
                    }
                }
            }
        }
        
        vector<int> weak_vertices;
        for (int u = 0; u < n; u++) {
            if (is_weak[u]) {
                weak_vertices.push_back(u);
            }
        }

        if (weak_vertices.empty()) {
            cout << "\n";
        }
        else {
            cout << weak_vertices.front();
            for (int i = 1; i < weak_vertices.size(); i++) {
                cout << " " << weak_vertices[i];
            }
            cout << "\n";
        }
    }
}
