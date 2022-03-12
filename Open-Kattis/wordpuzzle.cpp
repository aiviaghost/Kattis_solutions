#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

#define all(x) x.begin(), x.end()

const int INF = 2e9;
const int MOD = 1e9 + 7;

int solve(string & p, string & s) {
    int n = p.size(), m = s.size();
    auto dp = make<int>(0, n + 1, m + 1);
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (p[i - 1] == s[j - 1]) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    string p, s;
    cin >> p >> s;
    int ans = 0;
    unordered_set<string> seen;
    for (int i = 0; i < s.length(); i++) {
        string new_s = s.back() + s.substr(0, s.size() - 1);
        if (!seen.count(new_s)) {
            ans = (ans + solve(p, new_s)) % MOD;
            s = new_s;
            seen.emplace(new_s);
        }
    }
    cout << ans << "\n";
}
