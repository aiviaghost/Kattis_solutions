#include <bits/stdc++.h>

using namespace std;

// (m + k)^2 - m^2 = k(2m + k) = n <=> m = ((n / k) - k) / 2
// test each m and k
auto get_k(int &n) -> int {
    for (int k = 1; k * k <= n; k++) {
        int m = ((n / k) - k) / 2;
        if ((m + k) * (m + k) - m * m == n) {
            return k;
        }
    }
    return -1;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    int k = get_k(n);
    if (k == -1) {
        cout << "impossible\n";
    }
    else {
        int m = ((n / k) - k) / 2;
        cout << m << " " << m + k << "\n";
    }
}
