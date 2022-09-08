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
#define in(x, a) (x.find(a) != x.end())

const int INF = 2e9;
const int MOD = 1e9 + 7;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define unordered_map gp_hash_table

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    pii dirs[8] = {
        {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}
    };
    int r, c;
    cin >> r >> c;
    auto grid = make<int>(0, r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char x;
            cin >> x;
            grid[i][j] = x - '0';
        }
    }
    auto is_inside = [&](int x, int y) {
        return 0 <= x && x < c && 0 <= y && y < r;
    };
    int n;
    cin >> n;
    while (n--) {
        int rs, cs, rd, cd;
        cin >> rs >> cs >> rd >> cd, rs--, cs--, rd--, cd--;
        auto dist = make<int>(INF, r, c);
        dist[rs][cs] = 0;
        deque<pii> q({{cs, rs}});
        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop_front();
            for (int i = 0; i < 8; i++) {
                int nx = cx + dirs[i].first, 
                    ny = cy + dirs[i].second;
                int w = grid[cy][cx] != i;
                if (is_inside(nx, ny) && dist[cy][cx] + w < dist[ny][nx]) {
                    dist[ny][nx] = dist[cy][cx] + w;
                    if (w == 1) {
                        q.push_back({nx, ny});
                    }
                    else {
                        q.push_front({nx, ny});
                    }
                }
            }
        }
        cout << dist[rd][cd] << "\n";
    }
}
