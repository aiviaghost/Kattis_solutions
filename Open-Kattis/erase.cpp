#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    cin.ignore();
    string s1, s2;
    cin >> s1 >> s2;

    bool is_valid = true;
    if ((n & 1) == 1) {
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] == s2[i]) {
                is_valid = false;
                break;
            }
        }
    }
    else {
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                is_valid = false;
                break;
            }
        }
    }

    cout << (is_valid ? "Deletion succeeded" : "Deletion failed") << "\n";
}
