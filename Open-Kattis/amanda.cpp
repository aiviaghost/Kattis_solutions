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

/*

Insight is if an edge has c == 0 || c == 2 we know the state of both nodes. 
We can propagate this information throughout each component by viewing the 
state of a node as a color, "1" is a lounge and "0" is not a lounge. If we 
ever encounter a node of the same color as the one we are at but the edge 
between them is a "1-edge" the graph has no solution, that is valid = false.

There is however still an edge case left to handle. If a component has no 
"2-edges" or "0-edges" there will exist two valid colorings of the graph. 
Take for example this input data
    5 4
    1 2 1
    2 3 1
    3 4 1
    4 5 1
This can be colored either 10101 or 01010. To handle this we can simply say 
that whichever color we used the least of for that component is a lounge. So 
in the first coloring the lounges have color "0" but in the second coloring 
they are colored "1".

*/

int n, m;
vector<vector<int>> adj;
vector<int> color;
vector<bool> known, vis;
map<pii, int> e_reqs;
bool valid = true;

int propagate_known(int start, int start_color) {
    int lounges = 0;
    queue<pii> q({{start, start_color}});
    vis[start] = true;
    while (!q.empty()) {
        auto [cn, cc] = q.front();
        q.pop();
        lounges += cc;
        for (int next : adj[cn]) {
            if (e_reqs[{cn, next}] == 1) {
                if (known[next] && color[next] == cc) {
                    valid = false;
                }
                if (!vis[next]) {
                    vis[next] = known[next] = true;
                    color[next] = 1 - cc;
                    q.push({next, 1 - cc});
                }
            }
            else {
                if (known[next] && color[next] != cc) {
                    valid = false;
                }
                if (!vis[next]) {
                    vis[next] = known[next] = true;
                    color[next] = cc;
                    q.push({next, cc});
                }
            }
        }
    }
    return lounges;
}

int two_color(int start) {
    int maybe_lounges = 0, count_seen = 0;
    queue<pii> q({{start, 0}});
    vis[start] = true;
    while (!q.empty()) {
        auto [cn, cc] = q.front();
        q.pop();
        count_seen++;
        maybe_lounges += cc;
        for (int next : adj[cn]) {
            if (known[next] && color[next] == cc) {
                valid = false;
            }
            if (!vis[next]) {
                vis[next] = known[next] = true;
                color[next] = 1 - cc;
                q.push({next, 1 - cc});
            }
        }
    }
    return min(maybe_lounges, count_seen - maybe_lounges);
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    adj.resize(n);
    color.resize(n);
    known.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c, a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        e_reqs[{a, b}] = c;
        e_reqs[{b, a}] = c;
        if (c != 1) {
            if (c == 2) {
                if (known[a] && color[a] == 0 || known[b] && color[b] == 0) {
                    valid = false;
                }
                color[a] = color[b] = 1;
            }
            else {
                if (known[a] && color[a] == 1 || known[b] && color[b] == 1) {
                    valid = false;
                }
            }
            known[a] = known[b] = true;
        }
    }
    int ans = 0;
    vis.resize(n);
    for (int i = 0; i < n; i++) {
        if (!vis[i] && known[i]) {
            ans += propagate_known(i, color[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i] && !known[i]) {
            ans += two_color(i);
        }
    }
    cout << (valid ? to_string(ans) : "impossible") << "\n";
}
