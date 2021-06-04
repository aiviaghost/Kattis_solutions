#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

const int INF = 2e9;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c, a--, b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vector<int> singles_used(n, INF);
    singles_used[0] = 0;
    vector<bool> vis(n);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        pii curr = pq.top();
        pq.pop();

        if (vis[curr.second]) {
            continue;
        }
        vis[curr.second] = true;

        for (pii next : adj[curr.second]) {
            int alt_singles_used = singles_used[curr.second] + next.second;
            singles_used[next.first] = min(alt_singles_used, singles_used[next.first]);
            pq.push({singles_used[next.first], next.first});
        }
    }

    cout << singles_used[n - 1] << "\n";
}
