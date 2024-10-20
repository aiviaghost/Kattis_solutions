#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// #define unordered_map gp_hash_table

#define int ll
#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
#define sz(x) (ll)(x).size()
#define rep(i, a, b) for (int i = a; i < (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vi = vector<int>;

template <typename T>
vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args>
auto make(T init, size_t first, Args... sizes)
{
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

const int INF = 2e9;
const int MOD = 1e9 + 7;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, cols, rows;
    cin >> n >> cols >> rows;
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    auto dist_to_base = make(INF, rows, cols);

    queue<pii> q;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        dist_to_base[y][x] = 0;
        q.push({x, y});
    }

    vector<pii> ns = {
        {0, -1},
        {0, 1},
        {-1, 0},
        {1, 0}};

    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();

        for (auto [dx, dy] : ns)
        {
            int nx = cx + dx, ny = cy + dy;
            if (0 <= nx && nx < cols && 0 <= ny && ny < rows && dist_to_base[ny][nx] == INF)
            {
                dist_to_base[ny][nx] = dist_to_base[cy][cx] + 1;
                q.push({nx, ny});
            }
        }
    }

    auto get_dist = [&](int min_dist) -> int
    {
        if (dist_to_base[sy][sx] < min_dist)
        {
            return INF;
        }
        auto dist = make(INF, rows, cols);
        dist[sy][sx] = 0;
        q.push({sx, sy});

        while (!q.empty())
        {
            auto [cx, cy] = q.front();
            q.pop();

            for (auto [dx, dy] : ns)
            {
                int nx = cx + dx, ny = cy + dy;
                if (0 <= nx && nx < cols && 0 <= ny && ny < rows && dist[ny][nx] == INF && dist_to_base[ny][nx] >= min_dist)
                {
                    dist[ny][nx] = dist[cy][cx] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return dist[ty][tx];
    };

    int lb = -1, rb = rows + cols + 5, mid;
    while (rb - lb > 1)
    {
        mid = lb + (rb - lb) / 2;
        bool ok = get_dist(mid) != INF;
        if (ok)
        {
            lb = mid;
        }
        else
        {
            rb = mid;
        }
    }

    cout << lb << " " << get_dist(lb) << "\n";
}
