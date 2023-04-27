#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define unordered_map gp_hash_table

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

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int k, l;
        cin >> k >> l;
        adj[k].push_back(l);
        adj[l].push_back(k);
    }

    vector<double> E(n);
    for (int i = 0; i < 1e4; i++) {
        vector<double> E_next(n);
        for (int u = 0; u < n; u++) {
            if (u == n - 1) {
                continue;
            }
            for (int v : adj[u]) {
                E_next[u] += (E[v] + 1) * (1.0 / size(adj[u]));
            }
        }
        E = E_next;
    }

    cout << fixed << setprecision(20) << E[0] << "\n";
}
