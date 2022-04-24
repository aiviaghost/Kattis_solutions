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

#define all(x) x.begin(), x.end()

const int INF = 2e9;
const int MOD = 1e9 + 7;

using tiii = tuple<int, int, int>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<int> ps(n);
    for (int i = 0; i < n; i++) {
        cin >> ps[i];
    }
    vector<vector<pii>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }
    int q;
    cin >> q;
    while (q--) {
        int c, s, e;
        cin >> c >> s >> e;
        auto dp = make<int>(INF, n, c + 1);
        dp[s][0] = 0;
        priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
        pq.push({0, 0, s});
        while (!pq.empty()) {
            auto [curr_cost, curr_fill, curr] = pq.top();
            if (curr == e) {
                break;
            }
            pq.pop();
            if (curr_cost > dp[curr][curr_fill]) {
                continue;
            }
            if (curr_fill < c) {
                int alt_cost = curr_cost + ps[curr];
                if (alt_cost < dp[curr][curr_fill + 1]) {
                    dp[curr][curr_fill + 1] = alt_cost;
                    pq.push({alt_cost, curr_fill + 1, curr});
                }
            }
            for (auto [next, d] : adj[curr]) {
                if (curr_fill >= d && curr_cost < dp[next][curr_fill - d]) {
                    dp[next][curr_fill - d] = curr_cost;
                    pq.push({curr_cost, curr_fill - d, next});
                }
            }
        }
        cout << (dp[e][0] < INF ? to_string(dp[e][0]) : "impossible") << "\n";
    }
}

