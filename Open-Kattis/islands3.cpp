#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int r, c;
    cin >> r >> c;

    vector<vector<char>> grid(r, vector<char>(c));
    vector<vector<bool>> vis(r, vector<bool>(c));
    vector<pii> neighbours{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }

    int islands = 0;

    auto is_inside = [&](int x, int y) {
        return 0 <= x && x < c && 0 <= y && y < r;
    };

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!vis[i][j] && grid[i][j] == 'L') {
                islands++;
                vis[i][j] = true;
                vector<pii> curr_layer{{j, i}};
                while (!curr_layer.empty()) {
                    vector<pii> next_layer;
                    for (pii curr : curr_layer) {
                        for (pii n : neighbours) {
                            int nx = curr.first + n.first;
                            int ny = curr.second + n.second;
                            if (is_inside(nx, ny) && !vis[ny][nx] && grid[ny][nx] != 'W') {
                                vis[ny][nx] = true;
                                next_layer.push_back({nx, ny});
                            }
                        }
                    }
                    curr_layer = next_layer;
                }
            }
        }
    }

    cout << islands << "\n";

    return 0;
}
