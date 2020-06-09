#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli mod_inv (lli &a, lli n) {
    lli t = 0, new_t = 1, r = n, new_r = a;

    while (new_r != 0) {
        lli q = r / new_r;
        
        lli temp_t = t;
        t = new_t;
        new_t = temp_t - q * new_t;

        lli temp_r = r;
        r = new_r;
        new_r = temp_r - q * new_r;
    }

    if (r > 1) {
        return -1;
    }
    else if (t < 0) {
        return t + n;
    }
    else {
        return t;
    }
}

vector<int> get_primes(lli &n) {
    vector<int> primes;

    if ((n & 1) == 0) {
        primes.push_back(2);
        primes.push_back(n / 2);
        return primes;
    }

    for (int i = 3; i < sqrt(n); i += 2) {
        if (n % i == 0) {
            primes.push_back(i);
            primes.push_back(n / i);
            return primes;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        lli n, e;
        cin >> n >> e;

        vector<int> primes = get_primes(n);

        lli phi = (primes[0] - 1) * (primes[1] - 1);

        cout << mod_inv(e, phi) << "\n";
    }

    return 0;
}
