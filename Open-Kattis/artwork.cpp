#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// #define unordered_map gp_hash_table

#define int ll
#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
#define size(x) (ll)(x).size()

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

const int INF = 2e9;
const int MOD = 1e9 + 7;

struct UnionFind {
    vector<int> repr, sz;

    UnionFind(int n) : repr(n), sz(n, 1) {
        iota(all(repr), 0);
    }

    int find(int a) {
        if (repr[a] != a) {
            repr[a] = find(repr[a]);
        }
        return repr[a];
    }

    bool merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }
        if (sz[b] > sz[a]) {
            swap(a, b);
        }
        repr[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

struct Line {
    int x1, y1, x2, y2;
    vector<pii> points;

    Line() {}
    
    vector<pii> get_points() {
        if (!points.empty()) {
            return points;
        }
        if (x1 == x2) {
            for (int y = y1; y <= y2; y++) {
                points.push_back({y, x1});
            }
        } else {
            for (int x = x1; x <= x2; x++) {
                points.push_back({y1, x});
            }
        }
        return points;
    }

    bool on_line(int x, int y) {
        return x1 <= x && x <= x2 && y1 <= y && y <= y2;
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, q;
    cin >> m >> n >> q;

    auto grid = make(0, n, m);
    vector<Line> lines(q);
    for (auto&& line : lines) {
        cin >> line.x1 >> line.y1 >> line.x2 >> line.y2;
        line.x1--;
        line.x2--;
        line.y1--;
        line.y2--;
        for (auto [r, c] : line.get_points()) {
            grid[r][c]++;
        }
    }

    int num_regions = 0;
    auto vis = make(false, n, m);
    queue<pii> Q;
    UnionFind UF(n * m);

    auto get_neighbours = [&](int r, int c) {
        vector<pii> res;
        if (r - 1 >= 0) res.push_back({r - 1, c});
        if (r + 1 < n) res.push_back({r + 1, c});
        if (c - 1 >= 0) res.push_back({r, c - 1});
        if (c + 1 < m) res.push_back({r, c + 1});
        return res;
    };

    auto cell_to_id = [&](int r, int c) {
        return r * m + c;
    };

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (!vis[row][col] && grid[row][col] == 0) {
                num_regions++;
                vis[row][col] = true;
                Q.push({row, col});
                while (!Q.empty()) {
                    auto [r, c] = Q.front();
                    Q.pop();
                    for (auto [nr, nc] : get_neighbours(r, c)) {
                        if (!vis[nr][nc] && grid[nr][nc] == 0) {
                            UF.merge(cell_to_id(r, c), cell_to_id(nr, nc));
                            vis[nr][nc] = true;
                            Q.push({nr, nc});
                        }
                    }
                }
            }
        }
    }

    reverse(all(lines));
    lines.pop_back();
    vector<int> ans({num_regions});

    for (Line line : lines) {
        for (auto [r, c] : line.get_points()) {
            grid[r][c]--;
        }
        
        int num_merges = 0;
        bool active_segment = false;
        
        for (auto [r, c] : line.get_points()) {
            if (grid[r][c] == 0) {
                active_segment = true;
                for (auto [nr, nc] : get_neighbours(r, c)) {
                    if (grid[nr][nc] == 0){ 
                        int merge = UF.merge(cell_to_id(r, c), cell_to_id(nr, nc));
                        if (!line.on_line(nc, nr)) {
                            num_merges += merge;
                        }
                    }
                }
            } else if (active_segment) {
                active_segment = false;
                num_regions -= num_merges - 1;
                num_merges = 0;  
            }
        }
        if (active_segment) {
            num_regions -= num_merges - 1;
        }

        ans.push_back(num_regions);
    }

    reverse(all(ans));
    for (int a : ans) {
        cout << a << "\n";
    }
}
