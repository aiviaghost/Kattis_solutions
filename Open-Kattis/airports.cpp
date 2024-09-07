#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// #define unordered_map gp_hash_table

#define int ll
#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vi = vector<int>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

const int INF = 2e9;
const int MOD = 1e9 + 7;

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
    vi A(g.size()), B(btoa.size()), cur, next;
    for (;;) {
        fill(all(A), 0);
        fill(all(B), 0);
        /// Find the starting nodes for BFS (i.e. layer 0).
        cur.clear();
        for (int a : btoa) if (a != -1) A[a] = -1;
        rep(a, 0, sz(g)) if (A[a] == 0) cur.push_back(a);
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
        rep(a, 0, sz(g))
            res += dfs(a, 0, g, btoa, A, B);
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<int> service_times(n);
    for (auto&& x : service_times) {
        cin >> x;
    }

    auto adjacent_dists = make(0, n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjacent_dists[i][j];
            adjacent_dists[i][j] += service_times[j];
        }
    }

    struct FlightPath {
        int start, end, start_time;
        FlightPath() {}
    };

    vector<FlightPath> flight_paths(m);
    for (auto&& fp : flight_paths) {
        cin >> fp.start >> fp.end >> fp.start_time;
        fp.start--;
        fp.end--;
    }

    auto dist = make(INF, n, n);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int start = 0; start < n; start++) {
        dist[start][start] = service_times[start];
        pq.push({ 0, start });
        while (!pq.empty()) {
            auto [curr_dist, curr] = pq.top();
            pq.pop();
            for (int next = 0; next < n; next++) {
                int new_dist = curr_dist + adjacent_dists[curr][next];
                if (new_dist < dist[start][next]) {
                    dist[start][next] = new_dist;
                    pq.push({ new_dist, next });
                }
            }
        }
    }

    vector<vector<int>> g(m);
    for (int i = 0; i < m; i++) {
        auto fp1 = flight_paths[i];
        for (int j = 0; j < m; j++) {
            if (i == j) {
                continue;
            }

            auto fp2 = flight_paths[j];
            if (fp1.start_time + adjacent_dists[fp1.start][fp1.end] + dist[fp1.end][fp2.start] * (fp1.end != fp2.start) <= fp2.start_time) {
                g[i].push_back(j);
            }
        }
    }

    vi btoa(m, -1);
    cout << m - hopcroftKarp(g, btoa) << "\n";
}
