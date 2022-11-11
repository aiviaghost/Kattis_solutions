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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define unordered_map gp_hash_table

#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
#define size(x) (ll)(x).size()

const int INF = 2e9;
const int MOD = 1e9 + 7;

const int LOG_MAX = 19;

vector<vector<int>> adj, jump;
vector<int> parent, depth;

void dfs(int curr) {
    for (int next : adj[curr]) {
        if (next != parent[curr]) {
            parent[next] = curr;
            depth[next] = depth[curr] + 1;
            jump[0][next] = curr;
            for (int i = 1; i < LOG_MAX; i++) {
                jump[i][next] = jump[i - 1][jump[i - 1][next]];
            }
            dfs(next);
        }
    }
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    adj.resize(n);
    parent.resize(n);
    depth.resize(n);
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b, a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    jump = make(0, LOG_MAX, n);
    dfs(0);

    auto get_parent = [&](int u, int dist) {
        for (int i = 0; i < LOG_MAX; i++) {
            if (dist & (1 << i)) {
                u = jump[i][u];
            }
        }
        return u;
    };

    auto lca = [&](int u, int v) {
        if (depth[v] > depth[u]) {
            swap(u, v);
        }
        
        u = get_parent(u, depth[u] - depth[v]);

        if (u == v) {
            return u;
        }

        for (int i = LOG_MAX - 1; i >= 0; i--) {
            if (jump[i][u] != jump[i][v]) {
                u = jump[i][u];
                v = jump[i][v];
            }
        }

        return jump[0][u];
    };

    ll ans = 0;
    for (int u = 1; u <= n; u++) {
        int v = u * 2;
        while (v <= n) {
            ans += (depth[u - 1] + 1) + (depth[v - 1] + 1) - (2 * (depth[lca(u - 1, v - 1)] + 1)) + 1;
            v += u;
        }
    }
    cout << ans << "\n";
}
