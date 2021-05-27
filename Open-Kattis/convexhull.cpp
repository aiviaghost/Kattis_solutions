#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto get_convex_hull(vector<pii> &points) -> vector<pii> {
    /*
    * Cross product:
    * Normally the cross product can be computed by computing the following determinant:
    * | i  j  k  |
    * | x1 y1 z1 | = (y1 * z2 - z1 * y2)i - (x1 * z2 - z1 * x2)j + (x1 * y2 - y1 * x2)k
    * | x2 y2 z2 |
    * But since we are in 2d-space we set z1 = z2 = 0 => Determinant = (x1 * y2 - y1 * x2)k.
    * k is formally a basis vector but that is not terribly important here, we really only care about the coordinates.
    * Furthermore the vectors (x1, y1) and (x2, y2) are just (b - a) and (c - a). The represent the two vectors
    * involved in the geometric interpretation of the cross product. That is the vectors (x1, y1) and (x2, y2) are
    * the two vectors extracted from the three points we are given, both "starting" from the point "a".
    * See https://en.wikipedia.org/wiki/Cross_product to find out why this tells us the orientation (clockwise/ not clockwise).
    */
    auto clockwise = [](pii &a, pii &b, pii &c) {
        pii ab = {b.first - a.first, b.second - a.second};
        pii ac = {c.first - a.first, c.second - a.second};
        return (ab.first * ac.second - ab.second * ac.first) > 0;
    };

    int n = points.size();
    if (n <= 1) {
        return points;
    }

    sort(points.begin(), points.end());
    vector<pii> upper_hull{points[0], points[1]}, lower_hull{points[n - 1], points[n - 2]};
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

    int n;
    while (cin >> n && n != 0) {
        vector<pii> points(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            points[i] = {x, y};
        }

        vector<pii> convex_hull = get_convex_hull(points);

        cout << convex_hull.size() << "\n";
        for (pii p : convex_hull) {
            cout << p.first << " " << p.second << "\n";
        }
    }
}
