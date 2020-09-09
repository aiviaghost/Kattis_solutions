#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using pii = pair<int, int>;
using pdd = pair<double, double>;

int r, c;
pii neighbours[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

auto is_inside(int x, int y) -> bool {
    return 0 <= x && x <= c && 0 <= y && y < r;
}

auto update_grid(vector<vector<char>> &grid, int &t) -> void {
    vector<vector<int>> time_changed(r, vector<int>(c, t));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] != '.') {
                continue;
            }
            for (int k = 0; k < 4; k++) {
                int nx = j + neighbours[k].first, ny = i + neighbours[k].second;
                if (is_inside(nx, ny) && grid[ny][nx] == '*' && time_changed[ny][nx] == t) {
                    grid[i][j] = '*';
                    time_changed[i][j]++;
                }
            }
        }
    }
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    r, c;
    cin >> r >> c;

    vector<vector<char>> grid(r, vector<char>(c));
    int sx, sy, tx, ty;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char ch;
            cin >> ch;
            grid[i][j] = ch;
            if (grid[i][j] == 'S') {
                sx = j, sy = i;
            }
            else if (grid[i][j] == 'D') {
                tx = j, ty = i;
            }
        }
    }

    int t = 0, dist[r][c];
    memset(dist, -1, 4 * r * c);
    dist[sy][sx] = 0;
    vector<pii> curr_layer{{sx, sy}};
    while (!curr_layer.empty()) {
        vector<pii> next_layer;
        for (pii curr : curr_layer) {
            if (grid[curr.second][curr.first] == '*') {
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int nx = curr.first + neighbours[i].first, ny = curr.second + neighbours[i].second;
                if (is_inside(nx, ny) && dist[ny][nx] == -1 && (grid[ny][nx] == '.' || grid[ny][nx] == 'D')) {
                    dist[ny][nx] = dist[curr.second][curr.first] + 1;
                    next_layer.push_back({nx, ny});
                }
            }
        }
        curr_layer = next_layer;
        update_grid(grid, t);
        t++;
    }

    cout << (dist[ty][tx] != -1 ? to_string(dist[ty][tx]) : "KAKTUS") << "\n";
}
