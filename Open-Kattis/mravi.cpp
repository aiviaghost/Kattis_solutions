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

struct Pipe {
    int to;
    double flow;
    int type;
};

vector<int> req;
vector<vector<Pipe>> adj;

double dfs(unordered_set<int> & vis, int curr) {
    if (in(vis, curr)) {
        return 0;
    }
    vis.emplace(curr);

    if (req[curr] != -1) {
        return req[curr];
    }

    double tot = 0;
    for (auto [to, flow, type] : adj[curr]) {
        if (type == 1) {
            double c_res = dfs(vis, to);
            if (c_res < 1) {
                tot = max(tot, c_res / flow);
            }
            else {
                tot = max(tot, sqrt(c_res) / flow);
            }
        }
        else {
            tot = max(tot, dfs(vis, to) / flow);
        }
    }

    return tot;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    req.resize(n);
    adj.resize(n);

    for (int i = 0 ; i < n - 1; i++) {
        int a, b, x, t;
        cin >> a >> b >> x >> t, a--, b--;
        adj[a].push_back({b, x / 100.0, t});
        adj[b].push_back({a, x / 100.0, t});
    }

    for (int i = 0; i < n; i++) {
        cin >> req[i];
    }

    unordered_set<int> vis;
    cout << fixed << setprecision(20) << dfs(vis, 0) << "\n";
}
