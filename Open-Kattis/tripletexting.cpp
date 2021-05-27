#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    string text;
    cin >> text;
    int n = text.length() / 3;

    string res = "";
    for (int i = 0; i < n; i++) {
        char c1 = text[i], c2 = text[i + n], c3 = text[i + 2 * n];
        int not_res = c1 ^ c2 ^ c3;
        res += c1 != not_res ? c1 : c2;
    }
    cout << res << "\n";
}
