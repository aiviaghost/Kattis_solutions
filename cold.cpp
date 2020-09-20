#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    int ans = 0;
    while (n--) {
        int t;
        cin >> t;
        ans += t < 0;
    }

    cout << ans << "\n";
}
