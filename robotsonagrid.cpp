#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

#define MOD 2147483647

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    cin.ignore();
    string grid[n];
    for (int i = 0; i < n; i++) {
        getline(cin, grid[i]);
    }

    auto is_inside = [&] (int x, int y) { return 0 <= x && x < n && 0 <= y && y < n; };
    pii neighbours[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    ll ways[n][n];
    memset(ways, 0, 8 * n * n);
    ways[0][0] = 1;
    vector<pii> curr_layer{{0, 0}};
    while (!curr_layer.empty()) {
        vector<pii> next_layer;
        for (pii curr : curr_layer) {
            for (int i = 0; i < 2; i++) {
                int nx = curr.first + neighbours[i].first, ny = curr.second + neighbours[i].second;
                if (is_inside(nx, ny) && grid[ny][nx] == '.' && ways[ny][nx] == 0) {
                    ways[ny][nx] = ((is_inside(nx, ny - 1) ? ways[ny - 1][nx] : 0) + (is_inside(nx - 1, ny) ? ways[ny][nx - 1] : 0)) % MOD;
                    next_layer.push_back({nx, ny});
                }
            }
        }
        curr_layer = next_layer;
    }

    if (ways[n - 1][n - 1] > 0) {
        cout << ways[n - 1][n - 1] << "\n";
    }
    else {
        bool vis[n][n];
        memset(vis, 0, n * n);
        queue<pii> q;
        q.push({0, 0});
        while (!q.empty()) {
            pii curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = curr.first + neighbours[i].first, ny = curr.second + neighbours[i].second;
                if (is_inside(nx, ny) && !vis[ny][nx] && grid[ny][nx] == '.') {
                    vis[ny][nx] = true;
                    q.push({nx, ny});
                }
            }
        }

        cout << (vis[n - 1][n - 1] ? "THE GAME IS A LIE" : "INCONCEIVABLE") << "\n";
    }
}
