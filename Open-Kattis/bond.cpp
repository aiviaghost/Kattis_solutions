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

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    auto a = make<double>(0, n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j] /= 100.0;
        }
    }
    
    auto dp = make<double>(0, n, 1 << n);
    for (int i = 0; i < n; i++) {
        dp[0][1 << i] = a[0][i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < 1 << n; j++) {
            for (int k = 0; k < n; k++) {
                if (!(1 << k & j)) {
                    dp[i][j | 1 << k] = max(dp[i][j | 1 << k], dp[i - 1][j] * a[i][k]);
                }
            }
        }
    }
    
    cout << setprecision(20) << fixed << 100 * dp[n - 1][(1 << n) - 1] << "\n";
}
