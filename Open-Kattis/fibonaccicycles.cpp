#include <bits/stdc++.h>

using namespace std;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int q;
    cin >> q;

    while (q--) {
        int k;
        cin >> k;

        int a = 1, b = 1;

        unordered_map<int, int> seen; // map (fib(n) mod k : n)
        int index = 0;
        while (1) {
            int c = b;
            b = (a + b) % k;
            a = c;
            index++;

            if (seen.find(a) != seen.end()) {
                cout << seen.at(a) << "\n";
                break;
            }
            else if (index >= 2) {
                seen.emplace(a, index);
            }
        }
    }
}
