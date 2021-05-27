#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, t = 0;
    while (cin >> n && n != 0) {
        if (t > 0) {
            cout << "\n";
        }
        t++;

        vector<int> a1(n), cp_a1(n), a2(n);
        for (int i = 0; i < n; i++) {
            cin >> a1[i];
            cp_a1[i] = a1[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> a2[i];
        }

        sort(cp_a1.begin(), cp_a1.end());
        sort(a2.begin(), a2.end());

        unordered_map<int, int> kv;
        for (int i = 0; i < n; i++) {
            kv[cp_a1[i]] = a2[i];
        }

        for (int i = 0; i < n; i++) {
            cout << kv[a1[i]] << "\n";
        }
    }
}
