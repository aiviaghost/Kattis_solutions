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

const int INF = 2e18;
const int MOD = 1e9 + 7;

struct Edge {
    int u, v, w;
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, k, a, b;
    cin >> n >> m >> k >> a >> b;

    vector<vector<pii>> adj(n);
    unordered_set<int> next_nodes{ a, b };
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        if (w < 0) {
            next_nodes.insert({ u, v });
        }
    }

    unordered_map<int, vector<pii>> new_adj;
    vector<int> dist(n);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int start : next_nodes) {
        fill(all(dist), INF);
        dist[start] = 0;
        pq.push({ 0, start });
        while (!pq.empty()) {
            auto [curr_dist, curr] = pq.top();
            pq.pop();
            if (curr_dist > dist[curr]) {
                continue;
            }
            if (in(next_nodes, curr)) {
                new_adj[start].push_back({ curr, curr_dist });
            }
            for (auto [next, w] : adj[curr]) {
                if (w < 0) {
                    continue;
                }
                int new_dist = curr_dist + w;
                if (new_dist < dist[next]) {
                    dist[next] = new_dist;
                    pq.push({ new_dist, next });
                }
            }
        }
    }

    vector<Edge> edges;
    for (auto [u, nexts] : new_adj) {
        for (auto [v, w] : nexts) {
            edges.push_back({ u, v, w });
        }
    }
    for (int u = 0; u < n; u++) {
        for (auto [v, w] : adj[u]) {
            if (w < 0) {
                edges.push_back({ u, v, w });
            }
        }
    }

    n = size(next_nodes);
    fill(all(dist), INF);
    dist[a] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] == INF) {
                continue;
            }
            int new_dist = dist[u] + w;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
            }
        }
    }

    unordered_map<int, bool> is_negative;
    queue<int> reachable_from_negative_cycle;
    for (auto [u, v, w] : edges) {
        if (dist[u] == INF) {
            continue;
        }
        int new_dist = dist[u] + w;
        if (new_dist < dist[v]) {
            reachable_from_negative_cycle.push(u);
            reachable_from_negative_cycle.push(v);
        }
    }

    while (!reachable_from_negative_cycle.empty()) {
        int curr = reachable_from_negative_cycle.front();
        reachable_from_negative_cycle.pop();
        is_negative[curr] = true;
        for (auto [next, _] : adj[curr]) {
            if (!in(is_negative, next)) {
                reachable_from_negative_cycle.push(next);
            }
        }
    }

    if (dist[b] == INF) {
        cout << "POSITIVE INFINITY\n";
    }
    else if (is_negative[b]) {
        cout << "NEGATIVE INFINITY\n";
    }
    else {
        cout << dist[b] << "\n";
    }
}
