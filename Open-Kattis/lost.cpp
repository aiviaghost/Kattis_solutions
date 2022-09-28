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
#define in(xs, a) (xs.find(a) != xs.end())

const int INF = 2e9;
const int MOD = 1e9 + 7;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define unordered_map gp_hash_table

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    unordered_map<string, vector<pair<string, int>>> adj;
    vector<string> targets;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        targets.push_back(s);
    }
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        int c;
        cin >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    string eng = "English";
    queue<string> q({eng});
    unordered_map<string, int> dist;
    dist[eng] = 0;
    unordered_map<string, pair<string, int>> par;
    par[eng] = {"", 0};
    while (!q.empty()) {
        string curr = q.front();
        q.pop();
        for (auto [next, c] : adj[curr]) {
            int new_dist = dist[curr] + 1;
            if (!in(dist, next)) {
                dist[next] = new_dist;
                par[next] = {curr, c};
                q.push(next);
            }
            else {
                if (new_dist == dist[next] && c < par[next].second) {
                    par[next] = {curr, c};
                }
            }
        }
    }
    bool possible = true;
    int total = 0;
    for (string start : targets) {
        if (!in(par, start)) {
            possible = false;
            break;
        }
        auto [_, c] = par[start];
        total += c;    
    }
    cout << (possible ? to_string(total) : "Impossible") << "\n";
}
