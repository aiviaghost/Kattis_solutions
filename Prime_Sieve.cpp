#include <bits/stdc++.h>

#define lli long long int // might need this

using namespace std;

void standard_sieve(int &limit, vector<int> &primes, map<int, int> &primemap){
    bool mark[limit + 1];
    memset(mark, true, sizeof(mark));

    for (int i = 2; i * i < limit; i++) {
        if (mark[i]) {
            for (int j = i * i; j < limit; j += i) {
                mark[j] = false;
            }
        }
    }

    for (int i = 2; i < limit; i++) { 
        if (mark[i]) { 
            primes.push_back(i);
            if (primemap.find(i) != primemap.end()) {
                primemap[i] = 1;
            }
        } 
    } 
}


void segmented_sieve(int &n, map<int, int> &primemap, int &prime_count){
    vector<int> primes;
    int limit = floor(sqrt(n)) + 1;
    standard_sieve(limit, primes, primemap);

    prime_count += primes.size();

    int lower = limit;
    int higher = 2 * limit;

    while (lower < n) {
        if (higher >= n) {
            higher = n;
        }

        bool mark[limit + 1];
        memset(mark, true, sizeof(mark));

        for (int i = 0; i < primes.size(); i++) {
            int lower_limit = floor((lower / primes[i])) * primes[i];
            if (lower_limit < lower) {
                lower_limit += primes[i];
            }

            for (int j = lower_limit; j < higher; j += primes[i]) {
                mark[j - lower] = false;
            }
        }

        for (int i = lower; i < higher; i++){
            if (mark[i - lower]) {
                prime_count++;
                if (primemap.find(i) != primemap.end()) {
                    primemap[i] = 1;
                }
            }
        }

        lower += limit;
        higher += limit;
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    
    n += 1;
    
    map<int, int> primemap;
    int x;
    for (int i = 0; i < q; i++) {
        cin >> x;
        primemap.emplace(x, 0);
    }

    int prime_count = 0;
    segmented_sieve(n, primemap, prime_count);

    cout << prime_count << "\n";

    for (pair<int, int> x : primemap) {
        cout << x.second << "\n"; 
    }

    return 0;
}
