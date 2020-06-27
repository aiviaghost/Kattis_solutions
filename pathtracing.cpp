#include <bits/stdc++.h>

using namespace std;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int curr_x = 0, curr_y = 0, min_x = 0, min_y = 0, max_x = 0, max_y = 0;

    vector<pair<int, int>> path;
    path.push_back({curr_x, curr_y});

    string move;
    while (getline(cin, move)) {
        if (move == "up") {
            curr_y--;
        }
        else if (move == "right") {
            curr_x++;
        }
        else if (move == "down") {
            curr_y++;
        }
        else {
            curr_x--;
        }

        path.push_back({curr_x, curr_y});

        min_x = min(curr_x, min_x);
        min_y = min(curr_y, min_y);
        max_x = max(curr_x, max_x);
        max_y = max(curr_y, max_y);
    }

    int w = abs(max_x - min_x) + 1;
    int h = abs(max_y - min_y) + 1;
    
    vector<vector<char>> grid;

    grid.push_back({});
    for (int i = 0; i < w + 2; i++) {
        grid[0].push_back('#');
    }

    for (int i = 1; i < h + 1; i++) {
        grid.push_back({});
        for (int j = 0; j < w + 2; j++) {
            grid[i].push_back(' ');
        }
    }

    grid.push_back({});
    for (int i = 0; i < w + 2; i++) {
        grid[h + 1].push_back('#');
    }

    for (int i = 1; i < h + 1; i++) {
        grid[i][0] = '#';
        grid[i][w + 1] = '#';
    }
    
    for (int i = 1; i < path.size() - 1; i++) {
        grid[path[i].second + abs(min_y) + 1][path[i].first + abs(min_x) + 1] = '*';
    }
    grid[path[0].second + abs(min_y) + 1][path[0].first + abs(min_x) + 1] = 'S';
    grid[path[path.size() - 1].second + abs(min_y) + 1][path[path.size() - 1].first + abs(min_x) + 1] = 'E';

    for (int i = 0; i < h + 2; i++) {
        for (int j = 0; j < w + 2; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }

    return 0;
}
