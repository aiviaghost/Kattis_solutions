#include <bits/stdc++.h>

using namespace std;

int solve(int &x) {
    int prod = 1;
    while (x != 0) {
        int last_digit = x % 10;
        if (last_digit != 0) {
            prod *= last_digit;
        }
        x /= 10;
    }
    return prod;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int x;
    cin >> x;

    while (x >= 10) {
        x = solve(x);
    }

    cout << x << "\n";
}
