#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using pii = pair<int, int>;
using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int r, c;
    cin >> r >> c;

    char grid[r + 2][c + 2];
    int sx, sy;
    vector<pii> curr_fires;
    for (int i = 1; i < r + 1; i++) {
        for (int j = 1; j < c + 1; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'F') {
                curr_fires.push_back({j, i});
            }
            else if (grid[i][j] == 'J') {
                sx = j;
                sy = i;
            }
        }
    }

    for (int i = 0; i < c + 2; i++) {
        grid[0][i] = '.';
        grid[r + 1][i] = '.';
    }
    for (int i = 0; i < r + 2; i++) {
        grid[i][0] = '.';
        grid[i][c + 1] = '.';
    }

    int dist[r + 2][c + 2];
    memset(dist, -1, 4 * (r + 2) * (c + 2));
    dist[sy][sx] = 0;
    vector<pii> curr_layer{{sx, sy}};
    pii neighbours[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (!curr_layer.empty()) {
        vector<pii> next_layer;
        for (pii curr : curr_layer) {
            if (grid[curr.second][curr.first] == 'F') {
                continue;
            }
            for (pii next : neighbours) {
                int nx = curr.first + next.first, ny = curr.second + next.second;
                if (0 <= nx && nx < c + 2 && 0 <= ny && ny < r + 2 && dist[ny][nx] == -1 && grid[ny][nx] == '.') {
                    dist[ny][nx] = dist[curr.second][curr.first] + 1;
                    next_layer.push_back({nx, ny});
                }
            }
        }
        curr_layer = next_layer;

        // update fires
        vector<pii> next_fires;
        for (pii curr_fire : curr_fires) {
            for (pii next : neighbours) {
                int nx = curr_fire.first + next.first, ny = curr_fire.second + next.second;
                // note how the fire should not spread to the outer most cells
                // this is because we have added those cells to more easily compute the shortest path but they are not in the original input data!
                if (1 <= nx && nx < c + 1 && 1 <= ny && ny < r + 1 && grid[ny][nx] != '#' && grid[ny][nx] != 'F') {
                    grid[ny][nx] = 'F';
                    next_fires.push_back({nx, ny});
                }
            }
        }
        curr_fires = next_fires;
    }

    bool can_exit = false;
    int min_dist = INF;
    for (int i = 1; i < c + 1; i++) {
        if (dist[0][i] != -1) {
            can_exit = true;
            min_dist = min(dist[0][i], min_dist);
        }
        
        if (dist[r + 1][i] != -1) {
            can_exit = true;
            min_dist = min(dist[r + 1][i], min_dist);
        }
    }
    for (int i = 1; i < r + 1; i++) {
        if (dist[i][0] != -1) {
            can_exit = true;
            min_dist = min(dist[i][0], min_dist);
        }
        
        if (dist[i][c + 1] != -1) {
            can_exit = true;
            min_dist = min(dist[i][c + 1], min_dist);
        }
    }

    cout << (can_exit ? to_string(min_dist) : "IMPOSSIBLE") << "\n";
}
