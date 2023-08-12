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

inline int get_int() {
    int r = 0;
    char c = getchar_unlocked();
    while (c < '0' || '9' < c) {
        c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9') {
        r = 10 * r + c - '0';
        c = getchar_unlocked();
    }
    return r;
}

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
    if (A[a] != L) return 0;
    A[a] = -1;
    for (int b : g[a]) if (B[b] == L + 1) {
        B[b] = 0;
        if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
            return btoa[b] = a, 1;
    }
    return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
    int res = 0;
    vi A(size(g)), B(size(btoa)), cur, next;
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

    int T = get_int();
    while (T--) {
        int n = get_int();
        vector<vector<int>> cards(n);
        unordered_map<int, int> lookup;
        for (int i = 0; i < n; i++) {
            int a = get_int() - 1, b = get_int() - 1;
            if (!in(lookup, a)) {
                lookup[a] = size(lookup);
            }
            if (!in(lookup, b)) {
                lookup[b] = size(lookup);
            }
            cards[i].push_back(lookup[a]);
            cards[i].push_back(lookup[b]);
        }
        vector<int> btoa(size(lookup), -1);
        cout << (hopcroftKarp(cards, btoa) == n ? "possible" : "impossible") << "\n";
    }
}
