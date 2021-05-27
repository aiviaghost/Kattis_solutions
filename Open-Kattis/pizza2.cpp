#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using pii = pair<int, int>;
using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(6);

    double r, c;
    cin >> r >> c;

    cout << 100 * (r - c) * (r - c) / (r * r) << "\n";
}
