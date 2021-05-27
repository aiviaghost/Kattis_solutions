#include <bits/stdc++.h>

using namespace std;

set<int> get_primes(int x) { 
    set<int> primes;
    
    bool prime[x + 1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p = 2; p * p <= x; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= x; i += p) {
                prime[i] = false;
            }
        } 
    }

    for (int p = 2; p <= x; p++) {
       if (prime[p]) {
           primes.emplace(p);
       }
    }

    return primes;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    set<int> primes = get_primes(32000);

    while (n--) {
        int x;
        cin >> x;

        vector<pair<int, int>> reps;
        set<int>::iterator itr;
        for (itr = primes.begin(); itr != primes.end(); itr++) {
            if (*itr > x / 2) {
                break;
            }

            if (primes.find(x - *itr) != primes.end()) {
                reps.push_back({*itr, x - *itr});
            }
        }

        cout << x << " has " << reps.size() << " representation(s)\n";
        for (int i = 0; i < reps.size(); i++) {
            cout << reps[i].first << "+" << reps[i].second << "\n";
        }
        
        cout << "\n";
    }

    return 0;
}
