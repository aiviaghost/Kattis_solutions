#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

vector<int> init_w, req;
vector<vector<int>> adj;

auto dfs(int needed, int curr = 0) -> int {
    if (adj[curr].empty()) {
        if (req[curr] > needed) {
            return req[curr] - init_w[curr];
        }
        else {
            return needed - init_w[curr];
        }
    }

    int to_return = 2 * INF;
    for (int next : adj[curr]) {
        if (req[curr] > needed) {
            to_return = min(min(dfs(req[curr] - init_w[curr], next), req[curr] - init_w[curr]), to_return);
        }
        else {
            to_return = min(min(dfs(needed - init_w[curr], next), needed - init_w[curr]), to_return);
        }
    }

    return to_return;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, w;
    cin >> n >> w;

    init_w.resize(n + 1);
    req.resize(n + 1);
    req[0] = 0;
    init_w[0] = 0;
    adj.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int d, c, u;
        cin >> d >> c >> u;
        adj[d].push_back(i);
        init_w[i] = u;
        req[i] = c;
    }

    cout << min(dfs(w), w) << "\n";
}
