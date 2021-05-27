#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto rotate_point(pdd p, pdd center, double &angle) -> pdd {
    p.first -= center.first;
    p.second -= center.second;

    double new_x = p.first * cos(angle) - p.second * sin(angle);
    double new_y = p.first * sin(angle) + p.second * cos(angle);

    return {new_x + center.first, new_y + center.second};
}

auto area(vector<pdd> points) -> double {
    int n = points.size();
    double area = 0;
    for (int i = 0; i < n; i++) {
        area += points[i].first * points[(i + 1) % n].second - points[i].second * points[(i + 1) % n].first;
    }
    return abs(area) / 2.0;
}

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

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(1);

    int N;
    cin >> N;
    while (N--) {
        int n;
        cin >> n;
        double board_area = 0;
        vector<pdd> points(4 * n);
        for (int i = 0; i < 4 * n; i += 4) {
            double x, y, w, h, v;
            cin >> x >> y >> w >> h >> v, v = ((360 - v) * M_PI) / 180.0;
            board_area += w * h;
            pdd center = {x, y}, 
                p1 = rotate_point({x + w / 2.0, y + h / 2.0}, center, v), 
                p2 = rotate_point({x + w / 2.0, y - h / 2.0}, center, v),
                p3 = rotate_point({x - w / 2.0, y - h / 2.0}, center, v), 
                p4 = rotate_point({x - w / 2.0, y + h / 2.0}, center, v); 
            points[i] = p1;
            points[i + 1] = p2;
            points[i + 2] = p3;
            points[i + 3] = p4;
        }
        
        cout << (100.0 * board_area) / area(get_convex_hull(points)) << " %\n";
    }
}
