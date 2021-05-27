#include <bits/stdc++.h>

using namespace std;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    string pattern;
    while (getline(cin, pattern)) {
        if (pattern == "END") {
            break;
        }

        bool is_even = true;
        int delta = -1, last_seen = 0;
        for (int i = 1; i <= pattern.length(); i++) {
            if (pattern[i] == '*') {
                if (delta != -1 && delta != i - last_seen) {
                    is_even = false;
                    break;
                }
                delta = i - last_seen;
                last_seen = i;
            }
        }

        cout << t << " " << (is_even ? "EVEN" : "NOT EVEN") << "\n";

        t++;
    }

    return 0;
}
