#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// #define unordered_map gp_hash_table

#define int ll
#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
#define sz(x) (ll)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vi = vector<int>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

const int INF = 2e9;
const int MOD = 1e9 + 7;

inline int get_int() {
    int r = 0, c = getchar_unlocked();
    while (c < '0' || '9' < c) c = getchar_unlocked();
    while ('0' <= c && c <= '9') r = r * 10 + c - '0', c = getchar_unlocked();
    return r;
}

using i64 = uint64_t;

struct Grid {
    int h, w;
    int zr, zc;
    array<i64, 8> grid;

    Grid(int h, int w) : h(h), w(w), grid{} {}

    void set(int i, int j, int val) {
        i64 curr = (i64(0b11111111) << ((7 - j) * 8)) & grid[i];
        grid[i] = (grid[i] ^ curr) | (val << ((7 - j) * 8));
    }

    i64 get(int i, int j) const {
        return (grid[i] >> ((7 - j) * 8)) & i64(0b11111111);
    }

    void find_zero() {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (get(i, j) == 0) {
                    zr = i;
                    zc = j;
                }
            }
        }
    }

    Grid swap(int r, int c) const {
        Grid res(*this);
        res.set(zr, zc, res.get(zr + r, zc + c));
        res.set(zr + r, zc + c, 0);            
        res.zr += r;
        res.zc += c;
        return res;
    }

    Grid up() const {
        return this->swap(-1, 0);
    }

    Grid down() const {
        return this->swap(1, 0);
    }

    Grid left() const {
        return this->swap(0, -1);
    }

    Grid right() const {
        return this->swap(0, 1);
    }

    vector<Grid> get_neighbours() const {
        vector<Grid> res;
        if (zr > 0) res.push_back(up());
        if (zr + 1 < h) res.push_back(down());
        if (zc > 0) res.push_back(left());
        if (zc + 1 < w) res.push_back(right());
        return res;
    }

    bool operator==(const Grid & other) const {
        return grid == other.grid;
    }
};

namespace std {
    template<> struct hash<Grid> {
        size_t operator()(const Grid & grid) const noexcept {
            size_t h = 0;
            for (int i = 0; i < grid.h; i++) {
                h = i64(692711) * h + grid.grid[i];
            }
            return h;
        }
    };
}

int bfs(Grid start, Grid target, unordered_map<Grid, int> & dist, unordered_map<Grid, int> & prev_dist, int num_steps) {
    vector<Grid> curr_layer({start});
    dist[start] = 0;

    int ans = INF;
    for (int i = 0; i < num_steps; i++) {
        vector<Grid> next_layer;
        for (Grid curr : curr_layer) {
            int curr_dist = dist[curr];
            for (Grid next : curr.get_neighbours()) {
                if (in(prev_dist, next)) {
                    ans = min(ans, curr_dist + 1 + prev_dist[next]);
                }
                if (!in(dist, next)) {
                    dist[next] = curr_dist + 1,
                    next_layer.push_back(next);
                }
            }
        }
        curr_layer = next_layer;
    }

    return min(ans, in(dist, target) ? dist[target] : INF);
}

int solve(Grid & grid) {
    int h = grid.h;
    int w = grid.w;
    
    Grid target(h, w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            target.set(i, j, i * w + j + 1);
        }
    }
    target.set(h - 1, w - 1, 0);
    target.find_zero();

    unordered_map<Grid, int> dist, prev_dist;

    bfs(target, target, dist, prev_dist, 10);
    
    unordered_map<Grid, int> new_dist;
    
    return bfs(grid, target, new_dist, dist, 10);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n = get_int();
    while (n--) {
        int h = get_int(), w = get_int();
        Grid grid(h, w);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                grid.set(i, j, get_int());
            }
        }
        grid.find_zero();

        cout << solve(grid) << "\n";
    }
}