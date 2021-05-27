#include <bits/stdc++.h>

using namespace std;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        pair<double, int> MAX = {-1e18, -1};

        for (int i = 1; i <= n; i++) {
            double a, b, c;
            cin >> a >> b >> c;

            auto f = [&] (double R) {
                return -(a * R * R) + b * R + c;
            };

            double sym_x = b / (2 * a);

            double y_max = f(sym_x);

            if (y_max > MAX.first) {
                MAX.first = y_max;
                MAX.second = i;
            }
        }

        cout << MAX.second << "\n";
    }
}
