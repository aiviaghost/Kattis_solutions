#include <bits/stdc++.h>

using namespace std;

using pid = pair<int, double>;

vector<int> ranks, parents;

int Find(int x) {
    if (parents[x] == x) {
        return x;
    }
    else {
        parents[x] = Find(parents[x]);
        return parents[x];
    }
}

void Union(int x, int y) {
    int xRoot = Find(x);
    int yRoot = Find(y);

    if (ranks[xRoot] > ranks[yRoot]) {
        parents[yRoot] = xRoot;
    }
    else if (ranks[xRoot] < ranks[yRoot]) {
        parents[xRoot] = yRoot;
    }
    else if (xRoot != yRoot) {
        parents[yRoot] = xRoot;
        ranks[xRoot] = ranks[xRoot] + 1;
    }
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    while (n--) {
        int m;
        cin >> m;

        vector<pair<double, double>> points(m);
        for (int i = 0; i < m; i++) {
            double x, y;
            cin >> x >> y;
            points.push_back({x, y});
        }

        auto euclid_dist = [&](double x1, double y1, double x2, double y2) {
            return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
        };

        unordered_map<int, vector<pid>> adj;
        for (int i = 0; i < m - 1; i++) {
            for (int j = i + 1; j < m; j++) {
                double dist = euclid_dist(points[i].first, points[i].second, points[j].first, points[j].second);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        ranks.resize(m);
        parents.resize(m);
        for (int i = 0; i < m; i++) {
            parents[i] = i;
        }

        
    }

    return 0;
}
