#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

struct edge {
    int u, v, w;
};

struct edge_weight_comparator {
    inline bool operator() (const edge &e1, const edge &e2) {
        return e1.w < e2.w;
    }
};

struct node_comparator {
    inline bool operator() (const pii &n1, const pii &n2) {
        return n1.first < n2.first;
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

    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }

        vector<edge> edges(m);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges[i] = {u, v, w};
        }
        sort(edges.begin(), edges.end(), edge_weight_comparator());

        Union_Find UF(n);
        vector<pii> mst;
        int cost = 0;
        for (edge e : edges) {
            if (UF.Find(e.u) != UF.Find(e.v)) {
                mst.push_back({min(e.u, e.v), max(e.u, e.v)});
                cost += e.w;
                UF.Union(e.u, e.v);
            }
        }
        
        if (mst.size() != n - 1) {
            cout << "Impossible\n";
        }
        else {
            cout << cost << "\n";
            sort(mst.begin(), mst.end(), node_comparator());
            for (pii e : mst) {
                cout << e.first << " " << e.second << "\n";
            }
        }
    }
}
