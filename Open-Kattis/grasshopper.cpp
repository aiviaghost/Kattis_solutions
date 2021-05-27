#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int r, c, gr, gc, lr, lc;
    while (cin >> r >> c >> gr >> gc >> lr >> lc) {
        vector<vector<int>> dist(r, vector<int>(c, -1));
        dist[gr - 1][gc - 1] = 0;
        vector<pii> neighbours{{2, 1}, {2, -1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {1, -2}, {-1, -2}}, curr_layer{{gc - 1, gr - 1}};

        auto is_inside = [&](int x, int y) {
            return 0 <= x && x < c && 0 <= y && y < r;
        };

        while (!curr_layer.empty()) {
            vector<pii> next_layer;
            for (pii c : curr_layer) {
                for (pii n : neighbours) {
                    int nx = c.first + n.first;
                    int ny = c.second + n.second;
                    if (is_inside(nx, ny) && dist[ny][nx] == -1) {
                        dist[ny][nx] = dist[c.second][c.first] + 1;
                        next_layer.push_back({nx, ny});
                    }
                }
            }
            curr_layer = next_layer;
        }

        cout << (dist[lr - 1][lc - 1] == -1 ? "impossible" : to_string(dist[lr - 1][lc - 1])) << "\n";
    }
}
