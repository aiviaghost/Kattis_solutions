#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto solve(int b, int n) -> ll {
    int sum = 0;
    while(n > 0) {
        sum += (n % b) * (n % b);
        n /= b;
    }
    return sum;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int p;
    cin >> p;
    while (p--) {
        int k, b, n;
        cin >> k >> b >> n;
        cout << k << " " << solve(b, n) << "\n";
    }
}
