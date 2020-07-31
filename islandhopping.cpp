#include <bits/stdc++.h>

using namespace std;

struct edge {
    int u, v;
    double w;
};

struct edge_cmp {
    inline auto operator() (const edge &e1, const edge &e2) -> bool {
        return e1.w < e2.w;
    }
};

struct Union_Find {
    vector<int> rank, parent;

    Union_Find(int &n) {
        rank.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
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
    cout << fixed << setprecision(14);

    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        vector<pair<double, double>> nodes(m);
        for (int i = 0; i < m; i++) {
            double x, y;
            cin >> x >> y;
            nodes[i] = {x, y};
        }

        vector<edge> edges((m * (m - 1)) / 2);
        int index = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int j = i + 1; j < m; j++) {
                edges[index] = {i, j, hypot(abs(nodes[i].first - nodes[j].first), abs(nodes[i].second - nodes[j].second))};
                index++;
            }
        }
        sort(edges.begin(), edges.end(), edge_cmp());

        Union_Find UF(m);
        double cost = 0;
        for (edge e : edges) {
            if (UF.Find(e.u) != UF.Find(e.v)) {
                cost += e.w;
                UF.Union(e.u, e.v);
            }
        }

        cout << cost << "\n";
    }
}
