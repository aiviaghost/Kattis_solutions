#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

#define all(x) x.begin(), x.end()

const int INF = 2e9;

using pip = pair<int, pii>;

pii neighbours[] = {
    {-1, -1}, {0, -1}, {1, -1}, 
    {-1, 0},           {1, 0}, 
    {-1, 1},  {0, 1},  {1, 1}
};

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int h, w;
    cin >> h >> w;
    auto grid = make<int>(0, h, w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }
    int sx, sy;
    cin >> sy >> sx, sx--, sy--; // why didn't they put x first then y like normal people???
    auto vis = make<bool>(false, h, w);
    priority_queue<pip, vector<pip>, greater<pip>> lowest;
    lowest.push({grid[sy][sx], {sx, sy}});
    ll acc = 0;
    while (!lowest.empty()) {
        auto [curr_depth, curr] = lowest.top();
        lowest.pop();
        auto [cx, cy] = curr;
        if (vis[cy][cx]) {
            continue;
        }
        acc += abs(grid[cy][cx]);
        vis[cy][cx] = true;
        for (auto [dx, dy] : neighbours) {
            int nx = cx + dx, ny = cy + dy;
            if (0 <= nx && nx < w && 0 <= ny && ny < h && grid[ny][nx] < 0 && !vis[ny][nx]) {
                grid[ny][nx] = max(grid[ny][nx], curr_depth);
                lowest.push({grid[ny][nx], {nx, ny}});
            }
        }
    }
    cout << acc << "\n";
}

