#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int w, h;
        cin >> w >> h;
        char grid[h][w];
        pii start;
        vector<pii> fires;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == '*') {
                    fires.push_back({j, i});
                }
                else if (grid[i][j] == '@') {
                    start = {j, i};
                }
            }
        }

        auto is_inside = [&] (int x, int y) { return 0 <= x && x < w && 0 <= y && y < h; };
        pii neighbours[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int dist[h][w];
        memset(dist, -1, 4 * h * w);
        dist[start.second][start.first] = 0;
        vector<pii> curr_layer{start};
        while (!curr_layer.empty()) {
            vector<pii> next_fires;
            for (pii curr : fires) {
                for (int i = 0; i < 4; i++) {
                    int nx = curr.first + neighbours[i].first, ny = curr.second + neighbours[i].second;
                    if (is_inside(nx, ny) && grid[ny][nx] != '#' && grid[ny][nx] != '*') {
                        grid[ny][nx] = '*';
                        next_fires.push_back({nx, ny});
                    }
                }
            }
            fires = next_fires;

            vector<pii> next_layer;
            for (pii curr : curr_layer) {
                for (int i = 0; i < 4; i++) {
                    int nx = curr.first + neighbours[i].first, ny = curr.second + neighbours[i].second;
                    if (is_inside(nx, ny) && dist[ny][nx] == -1 && grid[ny][nx] == '.') {
                        dist[ny][nx] = dist[curr.second][curr.first] + 1;
                        next_layer.push_back({nx, ny});
                    }
                }
            }
            curr_layer = next_layer;
        }

        int min_dist = INF;
        for (int i = 0; i < w; i++) {
            if (dist[0][i] != -1) {
                min_dist = min(dist[0][i], min_dist);
            }
            if (dist[h - 1][i] != -1) {
                min_dist = min(dist[h - 1][i], min_dist);
            }
        }
        for (int i = 0; i < h; i++) {
            if (dist[i][0] != -1) {
                min_dist = min(dist[i][0], min_dist);
            }
            if (dist[i][w - 1] != -1) {
                min_dist = min(dist[i][w - 1], min_dist);
            }
        }
        cout << (min_dist < INF ? to_string(min_dist + 1) : "IMPOSSIBLE") << "\n";
    }
}
