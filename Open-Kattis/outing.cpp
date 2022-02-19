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

int n, k;
vector<int> adj, color, depth;
vector<bool> vis;
unordered_map<int, pii> ccs;
int current_color = 0;

void dfs(int curr, int curr_depth = 0) {
    if (vis[curr]) {
        return;
    }
    depth[curr] = curr_depth;
    vis[curr] = true;
    int next = adj[curr];
    if (vis[next]) {
        if (color[next] != -1) {
            color[curr] = color[next];
            ccs[color[curr]].second++;
            return;
        }
        color[curr] = current_color;
        current_color++;
        ccs[color[curr]].first = curr_depth - depth[next] + 1;
    }
    dfs(next, curr_depth + 1);
    color[curr] = color[curr] == -1 ? color[next] : color[curr];
    ccs[color[curr]].second++;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    adj.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> adj[i], adj[i]--;
    }
    vis.resize(n);
    color.resize(n, -1);
    depth.resize(n);
    for (int i = 0; i < n; i++) {
        if (!vis[i]){
            dfs(i);
        }
    }
    
    vector<pii> ranges;
    ranges.reserve(ccs.size());
    for (auto p : ccs) {
        ranges.push_back(p.second);
    }

    vector<bool> possible(n + 1);
    possible[0] = true;
    for (auto [low, high] : ranges) {
        vector<bool> curr = possible;
        for (int i = 0; i <= n; i++) {
            for (int j = low; j <= high; j++) {
                curr[j] = true;
                if (possible[i] && i + j <= n) {
                    curr[i + j] = true;
                }
            }
        }
        possible = curr;
    }
    
    for (int i = k; i >= 0; i--) {
        if (possible[i]) {
            cout << i << "\n";
            break;
        }
    }
}
