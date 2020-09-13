#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int n, m;

bool is_inside(int x, int y) {
    return 0 <= x && x < m && 0 <= y && y < n;
}

void dfs(int x, int y, vector<vector<char>> &grid) {
    /*
    if (grid[y][x] == 'V') {
        return;
    }
    */
    
    grid[y][x] = 'V';

    if (is_inside(x, y + 1) && grid[y + 1][x] == '.') {
        dfs(x, y + 1, grid);
    }
    else if (is_inside(x, y + 1) && grid[y + 1][x] == '#') {
        if (is_inside(x + 1, y) && grid[y][x + 1] == '.') {
            dfs(x + 1, y, grid);
        }
        
        if (is_inside(x - 1, y) && grid[y][x - 1] == '.') {
            dfs(x - 1, y, grid);
        }
    }
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;

    vector<pii> start_points;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'V') {
                start_points.push_back({j, i});
            }
        }
    }

    for (pii s : start_points) {
        dfs(s.first, s.second, grid);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}
