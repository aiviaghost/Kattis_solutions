#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto is_jolly(int &n, int seq[]) -> bool {
    if (n == 1) {
        return true;
    }

    bool seen[n - 1];
    memset(seen, 0, n - 1);

    for (int i = 0; i < n - 1; i++) {
        int diff = abs(seq[i] - seq[i + 1]);
        if (1 <= diff && diff <= n - 1) {
            seen[diff - 1] = true;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (!seen[i]) {
            return false;
        }
    }
    return true;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    while (cin >> n) {
        int seq[n];
        for (int i = 0; i < n; i++) {
            cin >> seq[i];
        }
        cout << (is_jolly(n, seq) ? "Jolly" : "Not jolly") << "\n";
    }
}
