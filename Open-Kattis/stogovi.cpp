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

    int n;
    cin >> n;

    vector<int> repr(n + 1), 
                parent(n + 1), 
                depth(n + 1), 
                value(n + 1);

    const int LOG_MAX = 20;
    auto jump = make(0, LOG_MAX, n + 1);
    
    auto lca = [&](int u, int v) {
        if (depth[v] > depth[u]) {
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
        return parent[u];
    };

    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        int v;
        cin >> v;
        v = repr[v];
        if (c == 'a') {
            parent[i] = v;
            repr[i] = i;
            value[i] = i;
            depth[i] = depth[parent[i]] + 1;
            jump[0][i] = parent[i];
            for (int j = 1; j < LOG_MAX; j++) {
                jump[j][i] = jump[j - 1][jump[j - 1][i]];
            }
        }
        else if (c == 'b') {
            repr[i] = parent[v];
            cout << value[v] << "\n";
        }
        else {
            int w;
            cin >> w;
            repr[i] = v;
            cout << depth[lca(v, repr[w])] << "\n";
        }
    }
}
