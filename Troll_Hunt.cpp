#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int b, k, g;
    cin >> b >> k >> g;

    int trolls_per_day = k / g;

    int day_count = 0;

    while (b > 1) {
        day_count++;
        b = b - trolls_per_day;
    }

    cout << day_count << "\n";

    return 0;
}
