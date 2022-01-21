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

    int T;
    cin >> T;
    while (T--) {
        int price, n;
        cin >> price >> n;
        vector<int> vs(n + 1);
        int max_s = 0;
        for (int i = 1; i <= n; i++) {
            cin >> vs[i];
            max_s += vs[i];
        }
        auto cs = make<int>(INF, n + 1, max_s + 1);
        for (int i = 0; i <= n; i++) {
            cs[i][0] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= max_s; j++) {
                if (j >= vs[i]) {
                    cs[i][j] = min(cs[i - 1][j], cs[i - 1][j - vs[i]] + 1);
                }
                else {
                    cs[i][j] = cs[i - 1][j];
                }
            }
        }
        for (int v = price; v <= max_s; v++) {
            if (cs[n][v] != INF) {
                cout << v << " " << cs[n][v] << "\n";
                break;
            }
        }
    }
}
