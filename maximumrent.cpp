#include <bits/stdc++.h>

using namespace std;

using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    double a, b, m, s;
    cin >> a >> b >> m >> s;

    vector<pdd> extreme_points;

    if ((s - 1) / 2 < m - 1 && s - 2 < m - 1) {
        extreme_points.push_back({1, m - 1});
        extreme_points.push_back({m - 1, 1});
        extreme_points.push_back({1, s - 2});
        extreme_points.push_back({(s - 1) / 2, 1});
    }
    else if ((s - 1) / 2 < m - 1 && s - 2 > 1) {
        extreme_points.push_back({m - 1, 1});
        extreme_points.push_back({(s - 1) / 2, 1});
        extreme_points.push_back({s - m, 2 * m - s});
    }
    else if ((s - 1) / 2 < m - 1 && m - 1 > 1) {
        extreme_points.push_back({1, m - 1});
        extreme_points.push_back({m - 1, 1});
        extreme_points.push_back({1, 1});
    }
    else if (m - 1 > 1) {
        extreme_points.push_back({m - 1, 1});
    }
    else {
        extreme_points.push_back({1, 1});
    }

    auto Z = [&](pdd xy) {
        return a * xy.first + b * xy.second;
    };

    double max_val = -1;
    for (pdd point : extreme_points) {
        max_val = max(Z(point), max_val);
    }

    cout << max_val << "\n";

    return 0;
}
