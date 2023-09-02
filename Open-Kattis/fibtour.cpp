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

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    unordered_map<int, int> next_fib;
    int f1 = 1, f2 = 1;
    while (f1 <= 1e18) {
        next_fib[f1] = f2;
        int f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }

    vector<int> starts;

    int n, m;
    cin >> n >> m;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
        if (in(next_fib, heights[i])) {
            starts.push_back(i);
        }
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;

    vector<bool> uses_one_case(n);
    vector<int> longest_path(n);

    auto dfs = [&](int curr, bool is_start_vertex, bool came_from_one, auto&& dfs) -> int {
        if (longest_path[curr] != 0 && !is_start_vertex) {
            return longest_path[curr];
        }
        longest_path[curr] = 1;

        for (int next : adj[curr]) {
            bool is_one_case = heights[curr] == 1 && heights[next] == 1 && !came_from_one && !uses_one_case[next];

            if (heights[next] == next_fib[heights[curr]] || is_one_case) {
                int alt_path_length = 1 + dfs(next, false, heights[curr] == 1, dfs);
            
                if (alt_path_length > longest_path[curr] || (alt_path_length == longest_path[curr] && !is_one_case)) {
                    longest_path[curr] = alt_path_length;
                    uses_one_case[curr] = is_one_case;
                }
            }
        }

        return longest_path[curr];
    };

    for (int start : starts) {
        ans = max(ans, dfs(start, true, false, dfs));
    }

    cout << ans << "\n";
}
