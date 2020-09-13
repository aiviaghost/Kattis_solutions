#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using pii = pair<int, int>;
using pdd = pair<double, double>;

struct point {
    double x, y, z;
};

// euclidean distance in 3D-space
auto dist(point &p1, point &p2) -> double {
    return sqrt(pow(abs(p1.x - p2.x), 2.0) + pow(abs(p1.y - p2.y), 2.0) + pow(abs(p1.z - p2.z), 2.0));
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(2);
    
    int n;
    while (cin >> n) {
        pdd coords[n];
        point points[n];
        for (int i = 0; i < n; i++) {
            double lat, lon;
            cin >> lat >> lon;
            coords[i] = {lat, lon};
            points[i] = {cos(lon * M_PI / 180) * cos(lat * M_PI / 180), sin(lon * M_PI / 180) * cos(lat * M_PI / 180), sin(lat * M_PI / 180)};
        }

        vector<double> adj[n];
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                double dp = dist(points[i], points[j]);
                double alpha = ((2.0 * asin(dp / 2.0)) * 180.0) / M_PI;
                double dist = (M_PI * alpha) / 180.0;
                adj[i].push_back(dist);
                adj[j].push_back(dist);
            }
        }

        pair<double, pdd> ans = {INF, {INF, INF}};
        for (int i = n - 1; i >= 0; i--) {
            double max_dist = -INF;
            for (double dist : adj[i]) {
                max_dist = max(dist, max_dist);
            }

            if (max_dist < ans.first) {
                ans.first = max_dist;
                ans.second = coords[i];
            }
        }
        
        cout << ans.second.first << " " << ans.second.second << "\n";
    }
}
