#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T, N;
    cin >> T;

    auto mod_fac = [&](int n) {
        int sum = 1;
        for (int i = 2; i <= n; i++)
            sum = ((sum % 10) * (i % 10)) % 10;
        return sum; 
    };

    while (T--) {
        cin >> N;
        cout << mod_fac(N) << "\n";
    }

    return 0;
}
