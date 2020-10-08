#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

int m;
double x;

auto solve() -> pii {
    int best_nom, best_denom;

    best_denom = m / 2;
    double cur_quot = best_denom * x;
    best_nom = best_denom + 0.5;
    cur_quot = (double) best_nom / (double) best_denom;
    double diff = abs(x - cur_quot);
    for (int denom = best_denom + 1; denom <= m; denom++) {
        cur_quot = denom * x;
        int nom = cur_quot + 0.5;
        cur_quot = nom / (double) denom;
        double new_diff = abs(x - cur_quot);
        if (new_diff < diff) {
            best_nom = nom;
            best_denom = denom;
            diff = new_diff;
        }
    }
    int gcd = __gcd(best_nom, best_denom);
    return {best_nom / gcd, best_denom / gcd};
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int p;
    cin >> p;
    while (p--) {
        int k;
        cin >> k >> m >> x;
        pii ans = solve();
        cout << k << " " << ans.first << "/" << ans.second << "\n";
    }
}
