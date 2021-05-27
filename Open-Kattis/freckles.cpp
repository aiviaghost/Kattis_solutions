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

    Union_Find(int n) {
        rank.resize(n);
        parent.resize(n);
        for (int i = 1; i < n; i++) {
            parent[i] = i;
        }
    }

    auto Find(int x) -> int {
        if (parent[x] == x) {
            return x;
        }
        else {
            parent[x] = Find(parent[x]);
            return parent[x];
        }
    }

    auto Union(int x, int y) -> void {
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
    cout << fixed << setprecision(2);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        if (t != 0) {
            cout << "\n";
        }

        int n;
        cin >> n;

        pair<double, double> points[n];
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            points[i] = {x, y};
        }

        vector<edge> edges((n * (n - 1)) / 2);
        int index = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                edges[index] = {i, j, hypot(abs(points[i].first - points[j].first), abs(points[i].second - points[j].second))};
                index++;
            }
        }
        sort(edges.begin(), edges.end(), edge_cmp());

        Union_Find UF(n);
        double min_dist = 0;
        for (edge e : edges) {
            if (UF.Find(e.u) != UF.Find(e.v)) {
                min_dist += e.w;
                UF.Union(e.u, e.v);
            }
        }
        cout << min_dist << "\n";
    }
}
