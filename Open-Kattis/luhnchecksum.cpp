#include <bits/stdc++.h>

using namespace std;

int digit_sum(int x) {
    int sum = 0;
    while (x != 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    cin.ignore();

    while (T--) {
        string n;
        getline(cin, n);

        int sum = 0;
        for (int i = n.length() - 1; i >= 0; i--) {
            int digit = n[i] - '0';
            if ((n.length() - i) % 2 == 0) {
                sum += (2 * digit > 9 ? digit_sum(2 * digit) : 2 * digit);
            }
            else {
                sum += digit;
            }
        }

        cout << (sum % 10 == 0 ? "PASS" : "FAIL") << "\n";
    }

    return 0;
}
