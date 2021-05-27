#include <bits/stdc++.h>

using namespace std;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        unordered_set<int> seen;
        int overlap = 0;
        for (int i = 0; i < n + m; i++) {
            int cd;
            cin >> cd;
            if (seen.find(cd) != seen.end()) {
                overlap++;
            }
            seen.emplace(cd);
        }
        cout << overlap << "\n";
    }
}
