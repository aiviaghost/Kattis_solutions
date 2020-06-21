#include <bits/stdc++.h>

using namespace std;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<bool> is_pushday(366);
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        is_pushday[d] = true;
    }

    int cleanup_days = 0;
    int dirtiness = 0;
    int pushes = 0;

    int i = 1;
    while (i <= 366) {
        if (dirtiness >= 20) {
            cleanup_days++;
            dirtiness = 0;
            pushes = 0;
            i -= 1;
            continue;
        }

        dirtiness += pushes;

        if (is_pushday[i]) {
            pushes++;
        }

        i++;
    }

    if (dirtiness > 0) {
        cleanup_days++;
    }

    cout << cleanup_days << "\n";

    return 0;
}
