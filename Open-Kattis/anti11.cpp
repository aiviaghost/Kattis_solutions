#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int a = 2, b = 3;
        for (int i = 1; i < n; i++) {
            int c = b;
            b = (a % MOD + b % MOD) % MOD;
            a = c;
        }
        
        cout << a << "\n";
    }

    return 0;
}
