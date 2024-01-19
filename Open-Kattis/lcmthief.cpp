#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define unordered_map gp_hash_table

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

inline int get_int() {
    int r = 0;
    char c = getchar_unlocked();
    while (c < '0' || '9' < c) {
        c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9') {
        r = 10 * r + c - '0';
        c = getchar_unlocked();
    }
    return r;
}

inline vector<int> sieve(int n) {
    vector<bool> is_prime(n, true);

    for (int p = 2; p * p <= n; p++) {
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

    vector<int> primes = sieve(1e3);
    auto factor = [&](int x) {
        unordered_map<int, int> exps;
        for (int p : primes) {
            while (x % p == 0) {
                x /= p;
                exps[p]++;
            }
        }
        if (x != 1) {
            exps[x]++;
        }
        return exps;
        };

    unordered_map<int, int> lcm;
    unordered_map<int, pii> exp_count;
    unordered_map<int, set<int>> possible_exps;

    vector<int> raw_nums;
    vector<unordered_map<int, int>> factored_nums;

    int n = get_int();
    for (int i = 0; i < n; i++) {
        int x = get_int();
        raw_nums.push_back(x);
        auto factored = factor(x);
        factored_nums.push_back(factored);

        for (auto [p, exp] : factored) {
            possible_exps[p].insert(exp);

            if (exp_count[p].first < exp) {
                exp_count[p].first = exp;
                exp_count[p].second = 1;
            }
            else if (exp_count[p].first == exp) {
                exp_count[p].second++;
            }

            lcm[p] = max(lcm[p], exp);
        }
    }

    int smallest_div = INF;
    int ans = -1;

    vector<int> order(n);
    iota(all(order), 0);
    sort(all(order), [&](int i, int j) {
        return raw_nums[i] < raw_nums[j];
        });

    for (int i : order) {
        int curr_div = 1;

        for (auto [p, exp] : factored_nums[i]) {
            if (exp_count[p].first == exp && exp_count[p].second == 1) {
                auto next = possible_exps[p].lower_bound(exp);
                int div_exp = next != possible_exps[p].begin() ? exp - *(--next) : exp;
                int div = pow(p, div_exp);
                curr_div *= div;
            }
        }

        if (curr_div < smallest_div) {
            smallest_div = curr_div;
            ans = raw_nums[i];
        }
    }

    cout << ans << "\n";
}
