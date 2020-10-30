#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto validate(string &s) -> int {
    int changes = 0;
    for (int i = s.length() / 2 - 1; i >= 0; i--) {
        if (s[i] != s[s.length() - i - 1]) {
            changes++;
        }
    }
    return changes;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    string name;
    cin >> name;
    int n = name.length();

    int best = INF;
    for (int i = 0; i < n; i++) {
        best = min(validate(name), best);
        name += " ";
    }

    cout << best << "\n";
}
