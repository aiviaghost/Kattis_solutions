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

const int INF = 1e13;
const int MOD = 1e9 + 7;

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> P(n);
    for (int i = 0; i < n; i++) {
        cin >> P[i];
    }

    auto dp = make(-INF, n, n);
    for (int i = 0; i < n; i++) {
        dp[i][n - 1] = P[n - 1];
    }
    for (int v = 1; v < n; v++) {
        for (int i = n - 1; i >= 0; i--) {
            int res = dp[v - 1][i];
            if (i + v <= n - 1) {
                res = max(res, P[i] + dp[v][i + v]);
            }
            dp[v][i] = res;
        }
    }

    cout << dp[n - 1][0] << "\n";
}
