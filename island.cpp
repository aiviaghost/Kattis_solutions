#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int w, h;
int islands;
int bridges;
int buses;
vector<pii> neighbours{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<vector<bool>> vis;
vector<string> grid;

auto is_inside(int x, int y) -> bool {
    return 0 <= x && x < w && 0 <= y && y < h;
}

auto flood_fill(int i, int j) -> void;

auto dfs(int i, int j, bool is_new_bridge) -> void {
    if (vis[i][j]) {
        return;
    }
    
    vis[i][j] = true;

    if (is_new_bridge) {
        bridges++;
    }

    for (pii n : neighbours) {
        if (is_inside(j + n.first, i + n.second)) {
            if (grid[ i + n.second][j + n.first] == 'B') {
                if (grid[i][j] == 'X') {
                    dfs(i + n.second, j + n.first, true);
                }
                else {
                    dfs(i + n.second, j + n.first, false);
                }
            }
            else if (grid[i + n.second][j + n.first] == 'X') {
                cout << j << " " << i << " 3\n";
                flood_fill(i + n.second, j + n.first);
            }
        }
    }
}

void flood_fill(int i, int j) {
    islands++;
    
    vis[i][j] = true;
    vector<pii> curr_layer{{j, i}};
    
    while (!curr_layer.empty()) {
        vector<pii> next_layer;
        for (pii c : curr_layer) {
            for (pii n : neighbours) {
                int nx = c.first + n.first;
                int ny = c.second + n.second;
                if (is_inside(nx, ny) && !vis[ny][nx] && grid[ny][nx] != '.') {
                    if (grid[ny][nx] == 'X') {
                        bridges++;
                        cout << nx << " " << ny << " 2\n";
                        dfs(ny, nx, false);
                    }
                    vis[ny][nx] = true;
                    next_layer.push_back({nx, ny});
                }
            }
        }
        curr_layer = next_layer;
    }
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    vector<vector<int>> answers;

    string line;
    while (getline(cin, line)) {
        w = line.length();
        while (line != "") {
            grid.push_back(line);
            getline(cin, line);
        }
        h = grid.size();

        islands = 0;
        bridges = 0;
        buses = 0;

        vis.resize(h, vector<bool>(w));

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] != '.' && !vis[i][j]) {
                    buses++;
                    cout << j << " " << i << " 1\n";
                    flood_fill(i, j);
                }
            }
        }

        answers.push_back({islands, bridges, buses});
        grid.clear();
        vis.clear();
    }

    for (int i = 0; i < answers.size(); i++) {
        cout << "Map: " << (i + 1) << "\n";
        cout << "islands: " << answers[i][0] << "\n";
        cout << "bridges: " << answers[i][1] << "\n";
        cout << "buses needed: " << answers[i][2] << "\n";

        if (i != answers.size() - 1) {
            cout << "\n";
        }
    }
}
