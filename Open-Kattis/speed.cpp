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
    cout << fixed << setprecision(9);

    int n, t;
    cin >> n >> t;
    vector<pii> segs(n);
    for (int i = 0; i < n; i++) {
        int d, s;
        cin >> d >> s;
        segs[i] = {d, s};
    }
    double lb = -2000, rb = 2e6, mid;
    for (int i = 0; i < 500; i++) {
        mid = lb + (rb - lb) / 2;
        double tt = 0;
        bool ok = true;
        for (auto [d, s] : segs) {
            if (s + mid <= 0) {
                ok = false;
                break;
            }
            tt += d / (s + mid);
        }
        if (ok && 0 < tt && tt < t) {
            rb = mid;
        }
        else {
            lb = mid;
        }
    }
    cout << mid << "\n";
}
