#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto get_convex_hull(vector<pdd> &points) -> vector<pdd> {
    auto clockwise = [](pdd &a, pdd &b, pdd &c) {
        pdd ab = {b.first - a.first, b.second - a.second};
        pdd ac = {c.first - a.first, c.second - a.second};
        return (ab.first * ac.second - ab.second * ac.first) > 0;
    };

    int n = points.size();
    if (n <= 1) {
        return points;
    }

    sort(points.begin(), points.end());
    vector<pdd> upper_hull{points[0], points[1]}, lower_hull{points[n - 1], points[n - 2]};
    for (int i = n - 2; i >= 0; i--) {
        while (lower_hull.size() > 1 && !clockwise(points[i], lower_hull[lower_hull.size() - 1], lower_hull[lower_hull.size() - 2])) {
            lower_hull.pop_back();
        }
        lower_hull.push_back(points[i]);
    }

    for (int i = 2; i < n; i++) {
        while (upper_hull.size() > 1 && !clockwise(points[i], upper_hull[upper_hull.size() - 1], upper_hull[upper_hull.size() - 2])) {
            upper_hull.pop_back();
        }
        upper_hull.push_back(points[i]);
    }

    upper_hull.insert(upper_hull.end(), lower_hull.begin() + 1, lower_hull.end() - 1);
    reverse(upper_hull.begin(), upper_hull.end());

    if (upper_hull.front() == upper_hull.back()) {
        upper_hull.erase(upper_hull.begin());
    }
    return upper_hull;
}

double area(pdd a, pdd b, pdd c) {
    return abs((b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first));
}

double diameter(const vector<pdd> &h) {
    int m = h.size();
    if (m == 1) { return 0; }
    if (m == 2) { return hypot(h[0].first - h[1].first, h[0].second - h[1].second); }
    
    int k = 1;
    while (area(h[m - 1], h[0], h[(k + 1) % m]) > area(h[m - 1], h[0], h[k])) {
        ++k;
    }
    
    double res = 0;
    for (int i = 0, j = k; i <= k && j < m; i++) {
        res = max(res, hypot(h[i].first - h[j].first, h[i].second - h[j].second));
        while (j < m && area(h[i], h[(i + 1) % m], h[(j + 1) % m]) > area(h[i], h[(i + 1) % m], h[j])) {
            res = max(res, hypot(h[i].first - h[(j + 1) % m].first, h[i].second - h[(j + 1) % m].second));
            j++;
        }
    }

    return res;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(7);

    int C;
    cin >> C;
    vector<pdd> shots(C);
    for (int i = 0; i < C; i++) {
        double x, y;
        cin >> x >> y;
        shots[i] = {x, y};
    }

    vector<pdd> convex_hull = get_convex_hull(shots);

    cout << diameter(convex_hull) << "\n";
}
