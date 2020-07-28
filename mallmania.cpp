#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using pii = pair<int, int>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int p;
    while (cin >> p) {
        if (p == 0) {
            break;
        }

        int min_x = 0, min_y = 0, max_x = 0, max_y = 0;

        vector<pii> m1(p);
        for (int i = 0; i < p; i++) {
            int x, y;
            cin >> x >> y;
            m1[i] = {x, y};

            min_x = min(x, min_x);
            min_y = min(y, min_y);
            max_x = max(x, max_x);
            max_y = max(y, max_y);
        }

        cin >> p;
        vector<pii> m2(p);
        for (int i = 0; i < p; i++) {
            int x, y;
            cin >> x >> y;
            m2[i] = {x, y};

            min_x = min(x, min_x);
            min_y = min(y, min_y);
            max_x = max(x, max_x);
            max_y = max(y, max_y);
        }

        int w = max_x - min_x + 1;
        int h = max_y - min_y + 1;
        vector<vector<int>> grid(h, vector<int>(w));

        for (pii& p : m1) {
            grid[p.second][p.first] = 1;
        }
        for (pii& p : m2) {
            grid[p.second][p.first] = 2;
        }

        vector<pii> curr_layer = m1, neighbours{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> dist(h, vector<int>(w, INF));
        for (pii curr : m1) {
            dist[curr.second][curr.first] = 0;
        }

        auto is_inside = [&] (int x, int y) {
            return 0 <= x && x < w && 0 <= y && y < h;
        };

        int min_dist = INF;

        while (!curr_layer.empty()) {
            vector<pii> next_layer;
            for (pii curr : curr_layer) {
                for (pii next : neighbours) {
                    int nx = curr.first + next.first;
                    int ny = curr.second + next.second;
                    if (is_inside(nx, ny) && dist[ny][nx] == INF) {
                        dist[ny][nx] = dist[curr.second][curr.first] + 1;
                        next_layer.push_back({nx, ny});

                        if (grid[ny][nx] == 2) {
                            min_dist = min(dist[ny][nx], min_dist);
                        }
                    }
                }
            }
            curr_layer = next_layer;
        }

        cout << min_dist << "\n";
    }
}
