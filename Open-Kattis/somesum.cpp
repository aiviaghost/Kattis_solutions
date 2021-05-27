#include <bits/stdc++.h>

using namespace std;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    string out;
    if (n == 1) {
        out = "Either";
    }
    else if (n == 2) {
        out = "Odd";
    }
    else if (((n & 1) == 0) && (((n / 2) & 1) == 0)) {
        out = "Even";
    }
    else if ((n & 1) == 0) {
        out = "Odd";
    }
    else {
        out = "Either";
    }
    cout << out << "\n";

    return 0;
}
