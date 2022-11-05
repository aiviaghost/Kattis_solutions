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

struct Edge {
    int c, f;
};

class Edmonds_Karp {
    public:
        int n, MAX_FLOW;
        vector<gp_hash_table<int, Edge>> adj;

        vector<pii> bfs(int s, int t, int cap) {
            vector<int> par(n, -1);
            par[s] = s;
            queue<int> Q({s});
            while (!Q.empty()) {
                int curr = Q.front();
                Q.pop();
                for (auto [next, edge] : adj[curr]) {
                    if (par[next] == -1 && edge.c - edge.f >= cap) {
                        par[next] = curr;
                        Q.push(next);
                    }
                }
            }

            if (par[t] == -1) {
                return {};
            }
            else {
                vector<pii> path;
                for (int curr = t; curr != s; curr = par[curr]) {
                    path.push_back({par[curr], curr});
                }
                return path;
            }
        }
    
        Edmonds_Karp(int n) : n(n), MAX_FLOW(0), adj(n) {}

        void add_edge(int u, int v, int c) {
            adj[u][v] = {c, 0};
        }

        int max_flow(int s, int t) {
            int cap = 1e8;
            while (cap >= 1) {
                vector<pii> path;
                while (!(path = bfs(s, t, cap)).empty()) {
                    int delta = INF;
                    for (auto [u, v] : path) {
                        delta = min(delta, adj[u][v].c - adj[u][v].f);
                    }
                    for (auto [u, v] : path) {
                        adj[u][v].f += delta;
                        adj[v][u].f -= delta;
                    }
                    MAX_FLOW += delta;
                }
                cap >>= 1;
            }
            return MAX_FLOW;
        }
};

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    
    Edmonds_Karp E_K(n);
    vector<pii> edges;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        E_K.add_edge(u, v, c);
        edges.push_back({u, v});
    }
    
    int max_flow = E_K.max_flow(s, t);

    vector<tuple<int, int, int>> used;
    for (auto [u, v] : edges) {
        int f = E_K.adj[u][v].f;
        if (f > 0) {
            used.push_back({u, v, f});
        }
    }

    cout << n << " " << max_flow << " " << size(used) << "\n";
    for (auto [u, v, f] : used) {
        cout << u << " " << v << " " << f << "\n";
    }
}
