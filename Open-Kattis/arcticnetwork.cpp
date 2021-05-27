#include <bits/stdc++.h>

using namespace std;

#define INF 2e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

struct edge {
    int u, v;
    double w;
};

struct edge_cmp {
    inline auto operator() (edge &e1, edge &e2) -> bool {
        return e1.w < e2.w;
    }
};

struct Union_Find {
    vector<int> repr, sz;

    Union_Find(int &n) {
        sz.resize(n, 1);
        repr.resize(n);
        for (int i = 1; i < n; i++) {
            repr[i] = i;
        }
    }

    auto Find(int &a) -> int {
        if (repr[a] != a) {
            repr[a] = Find(repr[a]);
        }
        return repr[a];
    }

    auto Union(int &a, int &b) -> void {
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

auto get_used_satellites(int &p, vector<edge> &edges, double &test_d) -> int {
    Union_Find UF = Union_Find(p);
    int connected_nodes = 1;
    for (edge e : edges) {
        if (UF.Find(e.u) != UF.Find(e.v) && e.w <= test_d) {
            UF.Union(e.u, e.v);
            connected_nodes++;
        }
    }

    if (connected_nodes == p) {
        return 0;
    }
    else {
        return p - connected_nodes + 1; // we need an extra satellite channel to connect the outposts connected via radio to the outposts connected via satellite
    }
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(2);
    
    int N;
    cin >> N;
    while (N--) {
        int s, p;
        cin >> s >> p;
        pii coords[p];
        for (int i = 0; i < p; i++) {
            int x, y;
            cin >> x >> y;
            coords[i] = {x, y};
        }

        vector<edge> edges;
        for (int i = 0; i < p; i++) {
            for (int j = i + 1; j < p; j++) {
                edges.push_back({i, j, hypot(coords[i].first - coords[j].first, coords[i].second - coords[j].second)});
            }
        }
        sort(edges.begin(), edges.end(), edge_cmp());

        // binary search D by greedily connecting outposts and using satellites used as a predicate function
        double lb = 0, rb = 1e4, mid;
        while (rb - lb > 1e-3) {
            mid = (lb + rb) / 2;
            if (get_used_satellites(p, edges, mid) > s) {
                lb = mid;
            }
            else {
                rb = mid;
            }
        }

        cout << mid << "\n";
    }
}
