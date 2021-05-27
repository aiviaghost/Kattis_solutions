#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using pii = pair<int, int>;

int w, h, V;
pii neighbours[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct cell {
    bool is_gravestone, is_haunted_hole;
};

struct edge {
    pii from, to;
    int t;
};

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    while (cin >> w >> h && w != 0) {
        V = w * h;
        vector<vector<cell>> grid(h, vector<cell>(w, {false, false}));
        vector<edge> edges;

        int G;
        cin >> G;
        while (G--) {
            int x, y;
            cin >> x >> y;
            grid[y][x].is_gravestone = true;
        }

        int E;
        cin >> E;
        while (E--) {
            int x1, y1, x2, y2, dt;
            cin >> x1 >> y1 >> x2 >> y2 >> dt;
            grid[y1][x1].is_haunted_hole = true;
            edges.push_back({{x1, y1}, {x2, y2}, dt});
        }

        auto is_inside = [&] (int x, int y) {
            return 0 <= x && x < w && 0 <= y && y < h;
        };

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!(grid[i][j].is_haunted_hole || grid[i][j].is_gravestone) && !(i == h - 1 && j == w - 1)) {
                    for (pii next : neighbours) {
                        int nx = j + next.first, ny = i + next.second;
                        if (is_inside(nx, ny) && !grid[ny][nx].is_gravestone) {
                            edges.push_back({{j, i}, {nx, ny}, 1});
                        }
                    }
                }
            }
        }
        
        vector<vector<int>> time(h, vector<int>(w, INF)), can_be_reached(h, vector<int>(w));
        time[0][0] = 0, can_be_reached[0][0] = 1;
        for (int i = 0; i < V - 1; i++) {
            for (edge e : edges) {
                int alt_dist = time[e.from.second][e.from.first] + e.t;
                if (alt_dist < time[e.to.second][e.to.first]) {
                    can_be_reached[e.to.second][e.to.first] = can_be_reached[e.from.second][e.from.first];
                    time[e.to.second][e.to.first] = alt_dist;
                }
            }
        }
        
        bool has_negative_cycle = false;
        for (edge e : edges) {
            if (can_be_reached[e.from.second][e.from.first] && time[e.from.second][e.from.first] + e.t < time[e.to.second][e.to.first]) {
                has_negative_cycle = true;
                break;
            }
        }

        if (has_negative_cycle) {
            cout << "Never";
        }
        else if (!can_be_reached[h - 1][w - 1]) {
            cout << "Impossible";
        }
        else {
            cout << time[h - 1][w - 1];
        }
        cout << "\n";
    }
}
