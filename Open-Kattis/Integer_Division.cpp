#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, d;
    cin >> n >> d;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = a[i] / d;
    }

    unordered_map<int, lli> count;

    for (int i = 0; i < n; i++) {
        if (count.find(a[i]) != count.end()) {
            count.at(a[i]) = count.at(a[i]) + 1;
        }
        else {
            count.emplace(a[i], 1);
        }
    }
    
    // since this will always be C(n, 2) this can be refactored to n(n-1) / 2
    auto choose = [&](int n, int k) {
        lli combinations = 1;
        
        if (k > n - k)
            k = n - k;
        
        for (int i = 0; i < k; i++) {
            combinations *= (n - i);
            combinations /= (i + 1);
        }

        return combinations;
    };

    lli pairs = 0;

    unordered_map<int, lli>:: iterator itr;
    for (itr = count.begin(); itr != count.end(); itr++) {
        if (itr->second > 1) {
            pairs = pairs + choose(itr->second, 2); 
        } 
    }

    cout << pairs << "\n";

    return 0;
}
