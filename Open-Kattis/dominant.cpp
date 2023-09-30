#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define unordered_map gp_hash_table

// #define int ll
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

using u128 = __uint128_t;

constexpr u128 primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };

u128 hash_str(const string& s) {
    u128 res = 1;
    for (char c : s) {
        res *= primes[c - 'a'];
    }
    return res;
}

struct Hasher_u128
{
    size_t operator()(const u128& x) const {
        return x;
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    unordered_map<u128, pair<vector<string>, bool>, Hasher_u128> is_dominated;
    vector<string> strings;

    string s;
    while (cin >> s) {
        strings.push_back(s);
        is_dominated[hash_str(s)].first.push_back(s);
    }

    auto check_divisors = [&](const string& s, u128 acc, int index, int bits_set, auto&& check_divisors) -> void {
        if (bits_set == size(s)) {
            return;
        }
        if (in(is_dominated, acc)) {
            is_dominated[acc].second = true;
        }
        if (index < size(s)) {
            check_divisors(s, acc * primes[s[index] - 'a'], index + 1, bits_set + 1, check_divisors);
            check_divisors(s, acc, index + 1, bits_set, check_divisors);
        }};

    for (string s : strings) {
        check_divisors(s, 1, 0, 0, check_divisors);
    }

    vector<string> ans;
    for (auto [_, p] : is_dominated) {
        auto [xs, is_dominated] = p;
        if (!is_dominated) {
            for (string s : xs) {
                ans.push_back(s);
            }
        }
    }
    sort(all(ans));

    for (string s : ans) {
        cout << s << "\n";
    }
}
