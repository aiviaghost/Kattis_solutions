#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using pii = pair<int, int>;
using pdd = pair<double, double>;

struct edge {
    int u, v, w;
};

struct edge_sort {
    inline auto operator() (edge &e1, edge &e2) -> bool {
        return e1.w < e2.w;
    }
};

struct Union_Find {
    vector<int> rank, parent;

    Union_Find(int &n) {
        rank.resize(n);
        parent.resize(n);
        for (int i = 1; i < n; i++) {
            parent[i] = i;
        }
    }

    auto Find(int &x) -> int {
        if (parent[x] == x) {
            return x;
        }
        else {
            parent[x] = Find(parent[x]);
            return parent[x];
        }
    }

    auto Union(int &x, int &y) -> void {
        int x_root = Find(x);
        int y_root = Find(y);
        if (rank[x_root] > rank[y_root]) {
            parent[y_root] = x_root;
        }
        else if (rank[x_root] < rank[y_root]) {
            parent[x_root] = y_root;
        }
        else if (x_root != y_root) {
            parent[y_root] = x_root;
            rank[x_root] = rank[x_root] + 1;
        }
    }
};

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<edge> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    sort(edges.begin(), edges.end(), edge_sort());

    int max_w = -1, connected_vertices = 1;
    Union_Find UF(n);
    for (int i = 0; i < m; i++) {
        if (UF.Find(edges[i].u) != UF.Find(edges[i].v)) {
            max_w = max(edges[i].w, max_w);
            UF.Union(edges[i].u, edges[i].v);
            connected_vertices++;
        }
    }

    cout << (connected_vertices == n ? to_string(max_w) : "IMPOSSIBLE") << "\n";
}
