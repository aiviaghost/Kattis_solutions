#include <bits/stdc++.h>

using namespace std;

struct pos {
    int x, y, z;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int l, r, c;
    while (cin >> l >> r >> c) {
        if (l == 0 && r == 0 && c == 0) {
            break;
        }

        char d[l][r][c];

        pos start, end;

        for (int z = 0; z < l; z++) {
            for (int y = 0; y < r; y++) {
                for (int x = 0; x < c; x++) {
                    cin >> d[z][y][x];
                    if (d[z][y][x] == 'S') {
                        start = {x, y, z};
                    }
                    else if (d[z][y][x] == 'E') {
                        end = {x, y, z};
                    }
                }
            }
        }

        vector<pos> curr_layer{start};
        int dist[l][r][c];
        for (int z = 0; z < l; z++) {
            for (int y = 0; y < r; y++) {
                for (int x = 0; x < c; x++) {
                    dist[z][y][x] = -1;
                }
            }
        }
        dist[start.z][start.y][start.x] = 0;
        vector<pos> neighbours = {{-1, 0, 0}, {1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

        auto is_inside = [&](int x, int y, int z) {
            return 0 <= x && x < c && 0 <= y && y < r && 0 <= z && z < l;
        };

        while (!curr_layer.empty()) {
            vector<pos> next_layer;
            for (pos c : curr_layer) {
                for (pos n : neighbours) {
                    int nx = c.x + n.x;
                    int ny = c.y + n.y;
                    int nz = c.z + n.z;
                    if (is_inside(nx, ny, nz) && dist[nz][ny][nx] == -1 && d[nz][ny][nx] != '#') {
                         dist[nz][ny][nx] = dist[c.z][c.y][c.x] + 1;
                         next_layer.push_back({nx, ny, nz});
                    }
                }
            }
            curr_layer = next_layer;
        }

        cout << (dist[end.z][end.y][end.x] != -1 ? "Escaped in " + to_string(dist[end.z][end.y][end.x]) + " minute(s)." : "Trapped!") << "\n";
    }

    return 0;
}
