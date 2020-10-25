#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

struct Union_Find {
    vector<int> repr, sz;
    
    Union_Find(int &n) {
        repr.resize(n);
        sz.resize(n, 1);
        for (int i = 1; i < n; i++) {
            repr[i] = i;
        }
    }

    auto Find(int &a) -> int {
        if (a != repr[a]) {
            repr[a] = Find(repr[a]);
        }
        return repr[a];
    }

    auto Union(int a, int b) -> void {
        a = Find(a);
        b = Find(b);
        if (a == b) {
            return;
        }
        if (sz[b] > sz[a]) {
            swap(a, b);
        }
        repr[b] = a;
        sz[a] += sz[b];
    }
};

struct edge {
    int u, v, w;
};

struct edge_cmp {
    inline auto operator() (edge &e1, edge &e2) -> bool {
        return e1.w < e2.w;
    }
};

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    int grid[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.push_back({i, j, grid[i][j]});
        }
    }
    sort(edges.begin(), edges.end(), edge_cmp());

    Union_Find UF(n);
    vector<edge> final_edges;
    for (edge e : edges) {
        if (UF.Find(e.u) != UF.Find(e.v)) {
            UF.Union(e.u, e.v);
            final_edges.push_back(e);
        }
    }

    for (edge e : final_edges) {
        cout << e.u + 1 << " " << e.v + 1 << "\n";
    }
}