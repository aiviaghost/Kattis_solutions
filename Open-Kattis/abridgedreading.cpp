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

using t3 = tuple<int, int, int>;

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> pages(n + 1), in_deg(n);
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        in_deg[v]++;
    }

    for (int i = 0; i < n; i++) {
        if (in_deg[i] == 0) {
            adj[n].push_back(i);
        }
    }

    auto solve = [&](int curr, auto&& solve) -> pii {
        if (size(adj[curr]) == 0) {
            return {pages[curr], INF};
        }

        if (size(adj[curr]) == 1) {
            auto [a, b] = solve(adj[curr][0], solve);
            return {a + pages[curr], b + pages[curr]};
        }
        else {
            vector<int> singles, doubles;
            for (int next : adj[curr]) {
                auto [a, b] = solve(next, solve);
                singles.push_back(a);
                doubles.push_back(b);
            }
            sort(all(singles));
            sort(all(doubles));
            int s1 = singles[0], s2 = singles[1], t = min(doubles[0], s1 + s2);
            return {s1 + pages[curr], t + pages[curr]};
        }
    };

    auto [_, ans] = solve(n, solve);

    cout << ans << "\n";
}
