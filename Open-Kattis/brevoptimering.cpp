#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

const int INF = 2e9;

vector<vector<pair<int, double>>> adj;
vector<int> times_visited, ms, parents_to_node;
vector<double> I, U;

auto dfs(int curr, double recieved) -> void {
    I[curr] += recieved;
    times_visited[curr]++;

    if (times_visited[curr] < parents_to_node[curr]) {
        return;
    }
    
    U[curr] = min(I[curr], (double) ms[curr]);

    for (pair<int, double> p : adj[curr]) {
        dfs(p.first, U[curr] * p.second);
    }
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;

    adj.resize(n);
    ms.resize(n);
    parents_to_node.resize(n);
    times_visited.resize(n);
    I.resize(n);
    U.resize(n);

    for (int i = 0; i < n; i++) {
        int m, k;
        cin >> m >> k;
        ms[i] = m;
        adj[i].reserve(k);
        for (int j = 0; j < k; j++) {
            int l;
            double w;
            cin >> l >> w, l--, w /= 100.0;
            adj[i].push_back({l, w});
            parents_to_node[l]++;
        }
    }

    vector<int> roots;
    for (int i = 0; i < n; i++) {
        if (parents_to_node[i] == 0) {
            roots.push_back(i);
        }
    }
    
    for (int root : roots) {
        dfs(root, ms[root]);
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (U[i] == ms[i]) {
            ans.push_back(i + 1);
        }
    }

    cout << ans.front();
    for (int i = 1; i < ans.size(); i++) {
        cout << " " << ans[i];
    }
    cout << "\n";
}
