#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

bool is_prime(int &m) {
    if (m == 1)
        return false;

    for (int i = 2; i <= sqrt(m); i++) {
        if (m % i == 0) {
            return false;
        }
    }
    return true;
}

bool solve(set<lli> &seen, lli m) {
    if (m == 1) {
        return true;
    }
    else if (seen.find(m) != seen.end()) {
        return false;
    }

    seen.emplace(m);

    lli sum = 0;
    while (m != 0) {
        sum = sum + pow(m % 10, 2);
        m = m / 10;
    }

    return solve(seen, sum);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int p, k, m;
    cin >> p;

    while (p--) {
        cin >> k >> m;
        
        set<lli> seen;
        if (is_prime(m)) {
            cout << k << " " << m << " " << (solve(seen, m) ? "YES" : "NO");
        }
        else {
            cout << k << " " << m << " " << "NO";
        }
        cout << "\n";
    }

    return 0;
}
