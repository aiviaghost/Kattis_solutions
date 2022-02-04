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

    int n, c;
    cin >> n >> c;
    vector<int> ws(n);
    for (int i = 0; i < n; i++) {
        cin >> ws[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int acc = 0, curr = 0;
        for (int j = i; j < n; j++) {
            if (acc + ws[j] <= c) {
                acc += ws[j];
                curr++;
            }
        }
        ans = max(ans, curr);
    }
    cout << ans << "\n";
}
