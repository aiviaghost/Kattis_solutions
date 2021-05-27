#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    int cost[n];
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    int sum[n][n];
    memset(sum, -1, 4 * n * n);
    sum[1][1] = cost[1];
    queue<pii> q;
    q.push({1, 1});
    while (!q.empty()) {
        pii curr = q.front();
        q.pop();
        int adj[2] = {-curr.second, curr.second + 1};
        for (int i = 0; i < 2; i++) {
            int next = curr.first + adj[i];
            if (0 <= next && next < n && (sum[next][abs(adj[i])] == -1 || sum[next][abs(adj[i])] > sum[curr.first][curr.second] + cost[next])) {
                sum[next][abs(adj[i])] = sum[curr.first][curr.second] + cost[next];
                q.push({next, abs(adj[i])});
            }
        }
    }

    int min_cost = INF;
    for (int i = 0; i < n; i++) {
        min_cost = sum[n - 1][i] != -1 ? min(sum[n - 1][i], min_cost) : min_cost;
    }
    cout << min_cost << "\n";
}
