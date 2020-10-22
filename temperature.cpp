#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(7);

    double x, y;
    cin >> x >> y;

    if (x == 0 && y == 1) {
        cout << "ALL GOOD\n";
    }
    else if (y == 1) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        cout << (x / (1 - y)) << "\n";
    }
}
