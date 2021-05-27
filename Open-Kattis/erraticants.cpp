#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    while (n--) {
        int s;
        cin >> s;
        map<pii ,vector<pii>> adj;
        pii coords[s + 1], curr_coords = {0, 0};
        coords[0] = curr_coords;
        int min_x = 0, min_y = 0, max_x = 0, max_y = 0;
        for (int i = 1; i < s + 1; i++) {
            char dir;
            cin >> dir;
            if (dir == 'N') {
                curr_coords.second -= 1;
            }
            else if (dir == 'W') {
                curr_coords.first -= 1;
            }
            else if (dir == 'E') {
                curr_coords.first += 1;
            }
            else {
                curr_coords.second += 1;
            }
            coords[i] = curr_coords;
            min_x = min(curr_coords.first, min_x);
            min_y = min(curr_coords.second, min_y);
            max_x = max(curr_coords.first, max_x);
            max_y = max(curr_coords.second, max_y);
        }
        for (int i = 1; i < s + 1; i++) {
            adj[{coords[i].first + abs(min_x), coords[i].second + abs(min_y)}].push_back({coords[i - 1].first + abs(min_x), coords[i - 1].second + abs(min_y)});
            adj[{coords[i - 1].first + abs(min_x), coords[i - 1].second + abs(min_y)}].push_back({coords[i].first + abs(min_x), coords[i].second + abs(min_y)});
        }
        pii sp = {abs(min_x), abs(min_y)}, ep = {abs(sp.first + curr_coords.first), abs(sp.second + curr_coords.second)};
        int w = abs(max_x - min_x) + 1, h = abs(max_y - min_y) + 1;
        int dist[h][w];
        memset(dist, -1, 4 * h * w);
        dist[sp.second][sp.first] = 0;
        queue<pii> q;
        q.push(sp);
        while (!q.empty()) {
            pii curr = q.front();
            q.pop();
            for (pii next : adj[curr]) {
                if (0 <= next.first && next.first < w && 0 <= next.second && next.second < h && dist[next.second][next.first] == -1) {
                    dist[next.second][next.first] = dist[curr.second][curr.first] + 1;
                    q.push(next);
                }
            }
        }
        cout << dist[ep.second][ep.first] << "\n";
    }
}
