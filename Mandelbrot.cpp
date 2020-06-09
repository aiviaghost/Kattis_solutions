#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    double x, y;
    int r, t = 1;

    while (cin >> x >> y >> r) {
        int counter = 1;
        double org_x = x, org_y = y;
        while (counter < r && sqrt(x * x + y * y) < 2) {
            double t_x = x;
            x = x * x - y * y + org_x;
            y = 2 * t_x * y + org_y;
            
            counter++;
        }

        cout << "Case " << t << ": " << (sqrt(x * x + y * y) > 2 ? "OUT" : "IN") << "\n";
        t++;
    }

    return 0;
}
