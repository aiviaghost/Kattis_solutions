#include <bits/stdc++.h>

using namespace std;

typedef long long lli;

bool solve(int m, int n, int t) {
    double max_n;
    if (t == 1) {
        if (n > 12)
            return false;

        max_n = 1;
        lli factorial = 1;
        for (lli i = 2; i <= n; i++) {
            factorial = factorial * i;
            if (factorial > m) {
                break;
            }
            max_n++;
        }
    }
    else if (t == 2) {
        max_n = log2(m);
    }
    else if (t == 3) {
        max_n = pow(m, 0.25);
    }
    else if (t == 4) {
        max_n = pow(m, 0.33333333333);
    }
    else if (t == 5) {
        max_n = pow(m, 0.5);
    }
    else if (t == 6) {
        return n * log2(n) <= m + 1e-6;
    }
    else if (t == 7) {
        max_n = m;
    }

    return n <= max_n + 1e-6;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    double m, n, t;
    cin >> m >> n >> t;

    cout << (solve(m, n, t) ? "AC" : "TLE") << "\n";

    return 0;
}
