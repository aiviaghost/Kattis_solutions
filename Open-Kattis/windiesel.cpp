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

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> depth(n, INF), par(n);
    const int surface = 0;
    depth[surface] = 0;
    queue<int> q({surface});
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int next : adj[curr]) {
            if (depth[next] == INF) {
                depth[next] = depth[curr] + 1;
                par[next] = curr;
                q.push(next);
            }
            else if (depth[curr] + 1 == depth[next] && par[next] > curr) {
                par[next] = curr;
            }
        }
    }

    const int LOG_MAX = 19;
    auto jump = make(0, LOG_MAX, n);
    jump[0] = par;
    for (int i = 1; i < LOG_MAX; i++) {
        for (int j = 0; j < n; j++) {
            jump[i][j] = jump[i - 1][jump[i - 1][j]];
        }
    }

    auto lca = [&](int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }
        int diff = depth[u] - depth[v];
        for (int i = 0; i < LOG_MAX; i++) {
            if (diff & (1 << i)) {
                u = jump[i][u];
            }
        }
        if (u == v) {
            return u;
        }
        for (int i = LOG_MAX - 1; i >= 0; i--) {
            if (jump[i][u] != jump[i][v]) {
                u = jump[i][u];
                v = jump[i][v];
            }
        }
        return par[u];
    };

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < n; i++) {
        pq.push({depth[i], i});
    }

    ll ans = 0;
    while (size(pq) > 1) {
        auto [_, curr] = pq.top();
        pq.pop();
        int next = pq.top().second;
        ans += depth[curr] + depth[next] - 2 * depth[lca(curr, next)];
    }
    cout << ans << "\n";
}
