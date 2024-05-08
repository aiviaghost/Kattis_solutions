#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// #define unordered_map gp_hash_table

#define int ll
#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
#define size(x) (ll)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)

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

bool dfs(int a, int L, vector<vector<int>>& g, vector<int>& btoa, vector<int>& A, vector<int>& B) {
    if (A[a] != L) return 0;
    A[a] = -1;
    for (int b : g[a]) if (B[b] == L + 1) {
        B[b] = 0;
        if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
            return btoa[b] = a, 1;
    }
    return 0;
}

int hopcroftKarp(vector<vector<int>>& g, vector<int>& btoa) {
    int res = 0;
    vector<int> A(size(g)), B(size(btoa)), cur, next;
    for (;;) {
        fill(all(A), 0);
        fill(all(B), 0);
        /// Find the starting nodes for BFS (i.e. layer 0).
        cur.clear();
        for (int a : btoa) if (a != -1) A[a] = -1;
        rep(a, 0, size(g)) if (A[a] == 0) cur.push_back(a);
        /// Find all layers using bfs.
        for (int lay = 1;; lay++) {
            bool islast = 0;
            next.clear();
            for (int a : cur) for (int b : g[a]) {
                if (btoa[b] == -1) {
                    B[b] = lay;
                    islast = 1;
                }
                else if (btoa[b] != a && !B[b]) {
                    B[b] = lay;
                    next.push_back(btoa[b]);
                }
            }
            if (islast) break;
            if (next.empty()) return res;
            for (int a : next) A[a] = lay;
            cur.swap(next);
        }
        /// Use DFS to scan for augmenting paths.
        rep(a, 0, size(g))
            res += dfs(a, 0, g, btoa, A, B);
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<pii> edges(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        edges[i] = { u, v };
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        auto [u, v] = edges[i];
        g[u].push_back(i);
        g[v].push_back(i);
    }
    vector<int> btoa(n, -1);
    hopcroftKarp(g, btoa);

    for (int i = 0; i < n; i++) {
        auto [u, v] = edges[i];
        int match = btoa[i];
        if (u == match) {
            cout << u + 1 << " " << v + 1 << "\n";
        }
        else {
            cout << v + 1 << " " << u + 1 << "\n";
        }
    }
}
