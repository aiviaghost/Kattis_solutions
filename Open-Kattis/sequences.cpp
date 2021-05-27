#include <bits/stdc++.h>

using namespace std;

#define INF 2e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

#define MOD (ll) (1e9 + 7)

auto bin_exp(ll base, ll exp) -> ll {
    ll res = 1;
    while (exp > 0) {
        if ((exp & 1) == 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin >> s;

    pair<ll, ll> prefix_sum[s.length()];
    for (int i = 1; i < s.length(); i++) {
        prefix_sum[i].first += prefix_sum[i - 1].first;
        prefix_sum[i].second += prefix_sum[i - 1].second;

        if (s[i - 1] == '0') {
            prefix_sum[i].first++;
        }
        else if (s[i - 1] == '?') {
            prefix_sum[i].second++;
        }
    }

    ll inversions = 0;
    for (ll i = 1; i < s.length(); i++) {
        if (s[i] == '?' || s[i] == '0') {
            if (s[i] == '?') inversions = (2 * inversions) % MOD;
            if (prefix_sum[i].second > 0) {
                ll d = i - prefix_sum[i].first;
                ll nk = bin_exp(2, prefix_sum[i].second - 1);
                ll inversions_at_index = nk * (2 * d - prefix_sum[i].second) % MOD;
                inversions = (inversions + inversions_at_index) % MOD;
            }
            else {
                inversions = (inversions + i - prefix_sum[i].first) % MOD;
            }
        }
    }

    cout << inversions << "\n";
}
