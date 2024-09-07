#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// #define unordered_map gp_hash_table

#define int ll
#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
#define size(x) (ll)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)

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

struct Cog {
    int x, y, r;

    Cog() {}

    bool is_touching(Cog other) {
        return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) <= (r + other.r) * (r + other.r);
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<Cog> ps(n);
    for (int i = 0; i < n; i++) {
        cin >> ps[i].x >> ps[i].y >> ps[i].r;
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ps[i].is_touching(ps[j])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    bool is_bipartite = true;
    bool is_even_depth;
    vector<int> color(n, -1);
    auto solve = [&](auto&& solve, int curr, int curr_color = 0, int depth = 0) -> void {
        color[curr] = curr_color;
        if (curr == n - 1) {
            is_even_depth = depth % 2 == 0;
        }
        for (int next : adj[curr]) {
            if (color[next] == -1) {
                solve(solve, next, 1 - curr_color, depth + 1);
            }
            else if (color[next] == curr_color) {
                is_bipartite = false;
                return;
            }
        }
        };

    solve(solve, 0);

    if (!is_bipartite) {
        cout << -1 << "\n";
    }
    else if (color[n - 1] == -1) {
        cout << 0 << "\n";
    }
    else {
        int a = ps[0].r, b = ps[n - 1].r;
        int d = __gcd(a, b);
        a /= d;
        b /= d;
        cout << b << " " << a * (is_even_depth ? 1 : -1) << "\n";
    }
}
