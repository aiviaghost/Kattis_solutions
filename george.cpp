#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

struct edge {
    int vertex, w, block_start, block_end;
};

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, A, B, k, g;
    cin >> n >> m >> A >> B >> k >> g;

    vector<int> georges_path(g);
    for (int i = 0; i < g; i++) {
        cin >> georges_path[i];
        georges_path[i] -= 1;
    }

    unordered_map<int, vector<edge>> adj;
    while (m--) {
        int a, b, L;
        adj[a - 1].push_back({b - 1, L, -1, -1});
        adj[b - 1].push_back({a - 1, L, -1, -1});
    }


}
