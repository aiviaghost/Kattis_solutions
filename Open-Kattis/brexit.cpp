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

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int c, p, x, l;
    cin >> c >> p >> x >> l, x--, l--;
    vector<vector<int>> adj(c);
    vector<int> in_deg(c);
    for (int i = 0; i < p; i++) {
        int a,b;
        cin >> a >> b, a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        in_deg[a]++;
        in_deg[b]++;
    }
    vector<int> curr_deg = in_deg;
    queue<int> q({l});
    vector<bool> vis(c);
    vis[l] = true;
    bool leave = false;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == x) {
            leave = true;
        }
        for (int next : adj[curr]) {
            curr_deg[next]--;
            if (!vis[next] && 2 * curr_deg[next] <= in_deg[next]) {
                vis[next] = true;
                q.push(next);
            }
        }
    }
    cout << (leave ? "leave" : "stay") << "\n";
}
