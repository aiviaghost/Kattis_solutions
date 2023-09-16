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

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<unordered_set<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace(v);
        adj[v].emplace(u);
    }

    vector<int> L;
    int o;
    while (cin >> o) {
        L.push_back(o);
    }

    if (size(L) != n) {
        cout << "NO\n";
        return 0;
    }

    for (int i : L) {
        if (i < 0 || n - 1 < i) {
            cout << "NO\n";
            return 0;
        }
    }

    bool valid = true;
    int index = 0;
    vector<bool> vis(n);

    auto dfs = [&](int curr, auto&& dfs) {
        if (vis[curr]) {
            valid = false;
            return;
        }
        vis[curr] = true;

        for (int i = 0; i < size(adj[curr]); i++) {
            if (index < size(L) - 1) {
                index++;
                int next = L[index];
                if (in(adj[curr], next)) {
                    dfs(next, dfs);
                }
                else {
                    int count = 0;
                    for (int next : adj[curr]) {
                        if (vis[next]) {
                            count++;
                        }
                    }
                    if (count == size(adj[curr])) {
                        dfs(next, dfs);
                        break;
                    }
                    else {
                        valid = false;
                    }
                }
            }
        }
        };

    dfs(L[index], dfs);

    for (bool v : vis) {
        valid &= v;
    }

    cout << (valid ? "YES" : "NO") << "\n";
}
