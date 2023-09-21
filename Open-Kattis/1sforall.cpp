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

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[1] = 1;
    
    for (int x = 2; x <= n; x++) {
        string num = to_string(x);
        int ans = dp[x - 1] + 1;

        // concatenation
        if (size(num) >= 2) {
            for (int i = 1; i < size(num); i++) {
                int left = stoll(num.substr(0, i));
                string rs = num.substr(i);
                if (rs[0] != '0') {
                    int right = stoll(rs);
                    ans = min(ans, dp[left] + dp[right]);
                }
            }
        }

        // multiplication
        for (int div = 2; div * div <= x; div++) {
            if (x % div == 0) {
                ans = min(ans, dp[div] + dp[x / div]);
            }
        }

        // addition
        for (int i = 1; i < x / 2; i++) {
            ans = min(ans, dp[i] + dp[x - i]);
        }

        dp[x] = ans;
    }

    cout << dp[n] << "\n";
}
