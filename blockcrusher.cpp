#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using pii = pair<int, int>;
using pip = pair<int, pii>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int h, w;
    while (cin >> h >> w) {
        if (h == 0 && w == 0) {
            break;
        }

        char grid[h][w];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> grid[i][j];
            }
        }

        auto is_inside = [&] (int x, int y) {
            return 0 <= x && x < w && 0 <= y && y < h;
        };

        map<pii, vector<pii>> adj;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (is_inside(j - 1, i + 1)) {
                    adj[{j, i}].push_back({j - 1, i + 1});
                }

                if (is_inside(j, i + 1)) {
                    adj[{j, i}].push_back({j, i + 1});
                }

                if (is_inside(j + 1, i + 1)) {
                    adj[{j, i}].push_back({j + 1, i + 1});
                }

                if (is_inside(j - 1, i)) {
                    adj[{j, i}].push_back({j - 1, i});
                }

                if (is_inside(j - 1, i - 1)) {
                    adj[{j, i}].push_back({j - 1, i - 1});
                }

                if (is_inside(j, i - 1)) {
                    adj[{j, i}].push_back({j, i - 1});
                }

                if (is_inside(j + 1, i - 1)) {
                    adj[{j, i}].push_back({j + 1, i - 1});
                }

                if (is_inside(j + 1, i)) {
                    adj[{j, i}].push_back({j + 1, i});
                }
            }
        }

        vector<vector<int>> dist(h, vector<int>(w, INF));
        map<pii, pii> parents;

        for (int s = 0; s < w; s++) {
            vector<vector<bool>> vis(h, vector<bool>(w));
            priority_queue<pip, vector<pip>, greater<pip>> pq;
            pq.push({grid[0][s] - '0', {s, 0}});
            dist[0][s] = grid[0][s] - '0';
            parents[{s, 0}] = {-1, -1};

            while (!pq.empty()) {
                pip curr = pq.top();
                pq.pop();

                if (vis[curr.second.second][curr.second.first]) {
                    continue;
                }

                vis[curr.second.second][curr.second.first] = true;
                
                for (pii next : adj[{curr.second.first, curr.second.second}]) {
                    int alt_dist = dist[curr.second.second][curr.second.first] + (grid[next.second][next.first] - '0');
                    if (alt_dist < dist[next.second][next.first]) {
                        parents[{next.first, next.second}] = curr.second;
                        dist[next.second][next.first] = alt_dist;
                        pq.push({alt_dist, {next.first, next.second}});
                    }
                }
            }
        }

        pii ans = {INF, -1};
        for (int i = 0; i < w; i++) {
            if (dist[h - 1][i] < ans.first) {
                ans.first = dist[h - 1][i];
                ans.second = i;
            }
        }

        grid[h - 1][ans.second] = ' ';
        pii level = parents[{ans.second, h - 1}];
        while (level.second != -1) {
            grid[level.second][level.first] = ' ';
            level = parents[level];
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cout << grid[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }
}
