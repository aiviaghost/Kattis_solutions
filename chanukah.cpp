#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto solve(int &n) -> ll {
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i + 1;
    }
    return sum;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int p;
    cin >> p;
    while (p--) {
        int k, n;
        cin >> k >> n;
        cout << k << " " << solve(n) << "\n";
    }
}
