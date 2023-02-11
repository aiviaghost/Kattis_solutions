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
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> army(n);
    for (int i = 0; i < n; i++) {
        cin >> army[i];
    }

    int s = 0;
    int curr_army = 0;

    vector<bool> vis(n);
    vis[s] = true;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({army[s], s});

    while (!q.empty()) {
        auto [_, curr] = q.top();
        q.pop();
        if (army[curr] < curr_army || curr == s){
            curr_army += army[curr];
        }
        else {
            break;
        }
        for (int next : adj[curr]) {
            if (!vis[next]) {
                vis[next] = true;
                q.push({army[next], next});
            }
        }
    }

    cout << curr_army << "\n";
}
