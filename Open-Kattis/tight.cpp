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
#define in(x, a) (x.find(a) != x.end())

const int INF = 2e9;
const int MOD = 1e9 + 7;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define unordered_map gp_hash_table

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    cout << fixed << setprecision(14);

    int k, n;
    while (cin >> k >> n) {
        double div = pow(k + 1, n);
        auto dp = make<double>(0, k + 1, n);
        for (int i = 0; i <= k; i++) {
            dp[i][0] = 1.0 / div;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int s = -1; s <= 1; s++) {
                    if (0 <= j + s && j + s <= k) { 
                        dp[j][i] += dp[j + s][i - 1];
                    }
                }
            }
        }
        double tot = 0;
        for (int i = 0; i <= k; i++) {
            tot += dp[i][n - 1];
        }
        cout << 100 * tot << "\n";
    }
}
