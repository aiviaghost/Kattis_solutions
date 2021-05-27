#include <bits/stdc++.h>

using namespace std;

int prime_sieve(int n, int k) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    vector<int> count(n + 1, -1);

    int counter = 0;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            counter++;
            count[p] = counter;

            for (int i = p * p; i <= n; i += p) {
                if (prime[i]) {
                    counter++;
                    count[i] = counter;
                }

                prime[i] = false;
            }
        }
    }
    
    for (int i = 2; i <= n; i++) {
        if (count[i] == -1) {
            counter++;
            count[i] = counter;
        }

        if (count[i] == k) {
            return i;
        }
    }
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    cout << prime_sieve(n, k) << "\n";    

    return 0;
}
