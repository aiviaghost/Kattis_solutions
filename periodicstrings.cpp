#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using pii = pair<int, int>;
using pdd = pair<double, double>;

auto is_k_periodic(string &s, int &k) -> bool {
    int n = s.length();
    string ks = s.substr(0, k);
    
    int index = 0;
    for (int i = 0; i < n / k; i++) {
        for (int j = 0; j < k; j++) {
            if (s[index] != ks[j]) {
                return false;
            }
            index++;
        }
        ks = ks[k - 1] + ks.substr(0, k - 1);
    }

    return true;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin >> s;
    int n = s.length();

    vector<int> divisors, temp;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i != i) {
                temp.push_back(i);
            }
            divisors.push_back(n / i);
        }
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
        divisors.push_back(temp[i]);
    }
    
    int k;
    for (int d : divisors) {
        int potential_k = n / d;
        if (is_k_periodic(s, potential_k)) {
            k = potential_k;
            break;
        }
    }

    cout << k << "\n";
}
