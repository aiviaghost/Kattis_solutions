#include <bits/stdc++.h>

using namespace std;

using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    double a, b, m, s;
    cin >> a >> b >> m >> s;

    vector<pdd> extreme_points;

    if (m - 1.0 > 1.0 && (s - 1.0) / 2.0 == m - 1.0) {
        extreme_points.push_back({m - 1.0, 1.0});
    }
    else if ((s - 1.0) / 2.0 < m - 1.0 && (s - 1.0) / 2.0 > 1.0 && m - 1.0 <= s - 2.0) {
        extreme_points.push_back({m - 1.0, 1.0});
        extreme_points.push_back({(s - 1.0) / 2.0, 1.0});
        extreme_points.push_back({s - m, 2.0 * m - s});
    }
    else if ((s - 1.0) / 2.0 < m - 1.0 && s - 2.0 < m - 1.0 && s - 2.0 > 1.0) {
        extreme_points.push_back({1.0, m - 1.0});
        extreme_points.push_back({m - 1.0, 1.0});
        extreme_points.push_back({1.0, s - 2.0});
        extreme_points.push_back({(s - 1.0) / 2.0, 1.0});
    }
    else if ((s - 1.0) / 2.0 < m - 1.0 && m - 1.0 > 1.0 && s - 2.0 <= 1.0) {
        extreme_points.push_back({1.0, m - 1.0});
        extreme_points.push_back({m - 1.0, 1.0});
        extreme_points.push_back({1.0, 1.0});
    }
    else {
        extreme_points.push_back({1.0, 1.0});
    }

    auto Z = [&](pdd xy) {
        return a * xy.first + b * xy.second;
    };

    double max_val = -1.0;
    for (pdd point : extreme_points) {
        max_val = max(Z(point), max_val);
    }

    cout << (long long) max_val << "\n";

    return 0;
}
