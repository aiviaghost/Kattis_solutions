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

template <typename T> using uset = unordered_map<T, null_type>;

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
        queue<int> Q({ s });
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
                path.push_back({ par[curr], curr });
            }
            return path;
        }
    }

    Edmonds_Karp(int n) : n(n), MAX_FLOW(0), adj(n) {}

    void add_edge(int u, int v, int c) {
        adj[u][v] = { c, 0 };
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

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    auto grid = make<ll>(0, k, n);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    bool is_valid = true;
    vector <uset<int>> rows, cols;
    for (int i = 0; i < k; i++) {
        rows.push_back(uset<ll>(all(grid[i])));
        if (size(rows.back()) < n) {
            is_valid = false;
        }
    }
    for (int i = 0; i < n; i++) {
        uset<ll> seen;
        for (int j = 0; j < k; j++) {
            seen.insert(grid[j][i]);
        }
        cols.push_back(seen);
        if (size(cols.back()) < k) {
            is_valid = false;
        }
    }

    if (!is_valid) {
        cout << "no\n";
        return 0;
    }

    for (int row = k; row < n; row++) {
        Edmonds_Karp flow(2 * n + 2);
        for (int num = 0; num < n; num++) {
            flow.add_edge(2 * n, num, 1);
        }
        for (int num = 0; num < n; num++) {
            for (int col = 0; col < n; col++) {
                if (!in(cols[col], num + 1)) {
                    flow.add_edge(num, n + col, 1);
                }
            }
        }
        for (int col = 0; col < n; col++) {
            flow.add_edge(n + col, 2 * n + 1, 1);
        }

        flow.max_flow(2 * n, 2 * n + 1);

        grid.push_back(vector<int>(n));
        for (int num = 0; num < n; num++) {
            for (int col = 0; col < n; col++) {
                if (flow.adj[num][n + col].f == 1) {
                    grid.back()[col] = num + 1;
                    cols[col].insert(num + 1);
                }
            }
        }
    }

    cout << "yes\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}
