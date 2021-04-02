#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

const int INF = 2e9;

int m, n;

auto is_all_connected(vector<vector<int>> &adj, int rev_a = -1, int rev_b = -1) -> bool {
    int components[m];
    memset(components, -1, 4 * m);
    
    for (int c = 0; c < m; c++) {
        if (components[c] != -1) {
            continue;
        }

        // compute strongly connected components
    }

    for (int i = 0; i < m - 1; i++) {
        if (components[i] != components[i + 1]) {
            return false;
        }
    }
    return true;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    
    int t = 0;
    while (cin >> m >> n) {
        t++;
        vector<vector<int>> adj(m);
        vector<pii> edge_list;
        edge_list.reserve(n);
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            edge_list.push_back({a, b});
        }

        if (is_all_connected(adj)) {
            cout << "Case " << t << ": valid\n";
        }
        else {
            bool valid_change = false;
            for (pii edge : edge_list) {
                if (is_all_connected(adj, edge.second, edge.first)) {
                    valid_change = true;
                    cout << "Case " << t << ": " << edge.first << " " << edge.second << "\n";
                    break;
                }
            }
            if (!valid_change) {
                cout << "Case " << t << ": invalid\n";
            }
        }
    }
}
