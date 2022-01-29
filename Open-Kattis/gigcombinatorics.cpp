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

const int INF = 2e9;
const int MOD = 1e9 + 7;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int ans = 0, used_ones = 0, last_ones = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 1) {
            last_ones++;
        }
        else if (s[i] == 2) {
            if (last_ones > 0) {
                sum = (((sum + last_ones) % MOD) * 2) % MOD;
                used_ones += last_ones;
                last_ones = 0;
            }
            else {
                sum = (2 * sum) % MOD;
            }
        }
        else {
            ans = (ans + sum - used_ones) % MOD;
            if (ans < 0) {
                ans += MOD;
            }
        }
    }
    cout << ans << '\n';
}
