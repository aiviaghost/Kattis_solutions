#include <bits/stdc++.h>

using namespace std;

using pdd = pair<double, double>;

auto dist(pdd p1, pdd p2) -> double {
    return hypot(abs(p1.first - p2.first), abs(p1.second - p2.second));
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(3);

    double gx, gy, dx, dy;
    cin >> gx >> gy >> dx >> dy;

    vector<pdd> holes;
    double x, y;
    while (cin >> x >> y) {
        holes.push_back({x, y});
    }

    bool can_escape = false;
    for (pdd p : holes) {
        if (dist({dx, dy}, p) >= 2 * dist({gx, gy}, p)) {
            can_escape = true;
            x = p.first;
            y = p.second;
            break;
        }
    }

    if (can_escape) {
        cout << "The gopher can escape through the hole at (" << x << "," << y << ").\n";
    }
    else {
        cout << "The gopher cannot escape.\n";
    }
}
