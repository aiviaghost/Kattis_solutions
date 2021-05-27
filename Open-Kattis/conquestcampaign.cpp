#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using pii = pair<int, int>;
using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int r, c, n;
    cin >> r >> c >> n;

    int dist[r][c];
    memset(dist, -1, 4 * r * c);
    vector<pii> curr_layer;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> y >> x, y--, x--;
        dist[y][x] = 0;
        curr_layer.push_back({x, y});
    }
    pii neighbours[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int days = 0;
    while (!curr_layer.empty()) {
        vector<pii> next_layer;
        for (pii curr : curr_layer) {
            for (pii next : neighbours) {
                int nx = curr.first + next.first, ny = curr.second + next.second;
                if (0 <= nx && nx < c && 0 <= ny && ny < r && dist[ny][nx] == -1) {
                    dist[ny][nx] = dist[curr.second][curr.first] + 1;
                    next_layer.push_back({nx, ny});
                }
            }
        }
        curr_layer = next_layer;
        days++;
    }

    cout << days << "\n";
}
