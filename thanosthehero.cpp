#include <bits/stdc++.h>

using namespace std;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> pops(n);

    for (int i = 0; i < n; i++) {
        cin >> pops[i];
    }

    bool should_kill_self = false;
    long long kill_count = 0;

    for (int i = n - 2; i >= 0; i--) {
        if (pops[i] >= pops[i + 1]) {
            int to_kill = pops[i] - pops[i + 1] + 1;
            if (pops[i] - to_kill < 0) {
                should_kill_self = true;
                break;
            }
            else {
                pops[i] -= to_kill;
                kill_count += to_kill;
            }
        }
    }

    cout << (!should_kill_self ? to_string(kill_count) : "1") << "\n";

    return 0;
}
