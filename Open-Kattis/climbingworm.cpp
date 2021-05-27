#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using pii = pair<int, int>;
using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int a, b, h;
    cin >> a >> b >> h;

    int ch = 0, count = 0;
    while (1) {
        if (ch >= h) {
            break;
        }
        count++;
        ch += a;
        if (ch >= h) {
            break;
        }
        ch -= b;
    }

    cout << count << "\n";
}
