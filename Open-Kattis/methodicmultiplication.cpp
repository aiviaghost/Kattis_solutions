#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    string s1, s2;
    cin >> s1 >> s2;

    int n1 = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == 'S') {
            n1++;
        }
    }

    int n2 = 0;
    for (int i = 0; i < s2.size(); i++) {
        if (s2[i] == 'S') {
            n2++;
        }
    }

    int res = n1 * n2;

    string out = "";
    for (int i = 0; i < res; i++) {
        out += ")";
    }
    out += "0";
    for (int i = 0; i < res; i++) {
        out += "(S";
    }
    reverse(out.begin(), out.end());
    cout << out << "\n";
}
