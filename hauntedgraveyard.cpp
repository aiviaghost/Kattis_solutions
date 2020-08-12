#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using pii = pair<int, int>;

int w, h, V;
pii neighbours[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct cell {
    int id, dt;
    bool is_gravestone, is_haunted_hole;
    pii to_cell;
};

auto is_inside(int &x, int &y) -> bool {
    return 0 <= x && x < w && 0 <= y && y < h;
}

auto dfs(vector<vector<cell>> &grid, unordered_set<int> &vis, int curr) -> void {
    if (vis.find(curr) != vis.end()) {
        return;
    }

    vis.emplace(curr);

    for (pii n : neighbours) {
        int cx = curr % w, cy = (curr - cx) / w;
        int nx = cx + n.first, ny = cy + n.second;

        if (!is_inside(nx ,ny)) {
            continue;
        }

        if (grid[ny][nx].is_gravestone) {
            continue;
        }

        if (grid[ny][nx].is_haunted_hole) {
            int tx = nx;
            nx = grid[ny][nx].to_cell.first;
            ny = grid[ny][tx].to_cell.second;
        }
        int next = ny * w + nx;
        dfs(grid, vis, next);
    }
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    while (cin >> w >> h && (w != 0 || h != 0)) {
        V = w * h;
        vector<vector<cell>> grid(h, vector<cell>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                grid[i][j] = {w * i + j, 1, false, false}; // maybe 0?
            }
        }

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
            grid[y1][x1].to_cell = {x2, y2};
            grid[y1][x1].dt = dt;
        }

        // calculate all final positions of haunted holes:
        int temp_vis[h][w];
        memset(temp_vis, 0, sizeof(temp_vis));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j].is_haunted_hole) {
                    int nx = j, ny = i, new_t = 0;
                    while (grid[ny][nx].is_haunted_hole && temp_vis[ny][nx] < V) {
                        temp_vis[ny][nx]++;
                        new_t += grid[ny][nx].dt;
                        int tx = nx;
                        nx = grid[ny][nx].to_cell.first;
                        ny = grid[ny][tx].to_cell.second;
                    }
                    grid[i][j].to_cell = {nx, ny};
                    grid[i][j].dt = new_t;
                }
            }
        }
        
        int vis_count[h][w];
        memset(vis_count, 0, sizeof(vis_count));
        vector<vector<int>> time(h, vector<int>(w, INF));
        time[0][0] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});
        unordered_set<int> in_pq{0};
        
        while (!pq.empty()) { // spfa
            pii curr = pq.top();
            pq.pop();
            in_pq.erase(curr.second);
            int cx = curr.second % w, cy = (curr.second - cx) / w;
            
            vis_count[cy][cx] += 1;
            if (vis_count[cy][cx] < V) {
                for (pii next : neighbours) {
                    int nx = cx + next.first, ny = cy + next.second;
                    
                    if (!is_inside(nx, ny)) {
                        continue;
                    }

                    if (grid[ny][nx].is_gravestone) {
                        continue;
                    }
                    
                    int new_t = 1;
                    if (grid[ny][nx].is_haunted_hole) { // travel to final exit of haunted hole
                        new_t += grid[ny][nx].dt;
                        int tx = nx;
                        nx = grid[ny][nx].to_cell.first;
                        ny = grid[ny][tx].to_cell.second;
                    }
                    
                    int alt_time = time[cy][cx] + new_t;
                    if (alt_time < time[ny][nx]) {
                        time[ny][nx] = alt_time;
                        if (in_pq.find(grid[ny][nx].id) == in_pq.end()) {
                            pq.push({alt_time, grid[ny][nx].id});
                            in_pq.emplace(grid[ny][nx].id);
                        }
                    }
                }
            }
        }
        
        unordered_set<int> vis;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (vis_count[i][j] == V) {
                    dfs(grid, vis, i * w + j);
                }
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (vis.find(i * w + j) != vis.end()) {
                    time[i][j] = -INF;
                }
            }
        }

        if (time[h - 1][w - 1] == INF) {
            cout << "Impossible";
        }
        else if (time[h - 1][w - 1] == -INF) {
            cout << "Never";
        }
        else {
            cout << time[h - 1][w - 1];
        }
        cout << "\n";
    }
}
