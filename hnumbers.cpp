#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto get_h_primes(int &n) -> vector<int> {
    bool is_h_prime[n + 1];
    memset(is_h_prime, 1, n + 1);

    for (int i = 5; i * i < n + 1; i += 4) {
        if (is_h_prime[i]) {
            for (int j = i * i; j < n + 1; j += i) {
                is_h_prime[j] = false;
            }
        }
    }

    vector<int> h_primes;
    for (int i = 5; i < n + 1; i += 4) {
        if (is_h_prime[i]) {
            h_primes.push_back(i);
        }
    }
    return h_primes;
}

auto get_h_semi_primes(int n) -> vector<int> {
    vector<int> h_primes = get_h_primes(n);
    unordered_set<int> seen;
    vector<int> semi_primes;
    for (int i = 0; i * i < h_primes.size(); i++) {
        for (int j = i; j < h_primes.size(); j++) {
            int semi_prime = h_primes[i] * h_primes[j];
            if (semi_prime <= n && seen.find(semi_prime) == seen.end()) {
                seen.emplace(semi_prime);
                semi_primes.push_back(semi_prime);
            }
            else if (semi_prime > n) {
                break;
            }
        }
    }
    return semi_primes;
}

auto bin_search(vector<int> &h_semi_primes, int &h) -> int {
    int lb = 0, rb = h_semi_primes.size(), mid;
    while (rb - lb > 0) {
        mid = (lb + rb) / 2;
        if (h_semi_primes[mid] > h) {
            rb = mid;
        }
        else {
            lb = mid + 1;
        }
    }
    return lb;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    vector<int> h_semi_primes = get_h_semi_primes(1e6 + 1);
    sort(h_semi_primes.begin(), h_semi_primes.end());
    
    int h;
    while (cin >> h && h != 0) {
        cout << h << " " << bin_search(h_semi_primes, h) << "\n";
    }
}
