#include <bits/stdc++.h>

using namespace std;

const double PI = 4 * atan(1);

auto area(double r, int itr) -> double {
    if (itr == 1) {
        return r * r;
    }
    else {
        return area(r, itr - 1) + 4 * pow(3, itr - 2) * pow(r / pow(2, itr - 1), 2);
    }
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(8);

    int T;
    cin >> T;
    
    while (T--) {
        int r, itr;
        cin >> r >> itr;

        cout << to_string(area(r, itr) * PI) << "\n";
    }

    return 0;
}
