#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// #define unordered_map gp_hash_table

#define int ll
#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
#define size(x) (ll)(x).size()

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

const int INF = 2e9;
const int MOD = 1e9 + 7;

vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    for (int p = 2; p <= n; p++) {
        if (is_prime[p]) {
            for (int pp = p * p; pp <= n; pp += p) {
                is_prime[pp] = false;
            }
        }
    }
    vector<int> primes;
    for (int p = 2; p <= n; p++) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
    return primes;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    auto primes = sieve(1 << 16);

    int x;
    while (cin >> x && x) {
        int ans = -1;
        bool is_negative = x < 0;
        bool is_large_prime = true;
        for (int p : primes) {
            if (x == 1) {
                break;
            }
            if (x % p == 0) {
                is_large_prime = false;
                int exp = 0;
                while (x % p == 0) {
                    x /= p;
                    exp++;
                }
                ans = ans == -1 ? exp : gcd(ans, exp);
            }
        }
        if (is_negative) {
            while (ans % 2 == 0) {
                ans /= 2;
            }
        }
        cout << (is_large_prime ? 1 : ans) << "\n";
    }
}
