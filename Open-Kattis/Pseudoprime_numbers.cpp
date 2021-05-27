#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

bool is_prime(lli p) {
    for (int i = 2; i <= sqrt(p); i++) {
        if (p % i == 0) {
            return false;
        }
    }
    return true;
}

lli mod_exp(lli base, lli exp, lli mod) {
    lli res = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    lli p, a;
    while (cin >> p >> a) {
        if (p == 0 && a == 0)
            break;
        
        if (is_prime(p)) {
            cout << "no" << "\n";
        }
        else {
            cout << (mod_exp(a, p, p) == a ? "yes" : "no") << "\n";
        }
    }

    return 0;
}
