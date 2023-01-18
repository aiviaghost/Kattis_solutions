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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define unordered_map gp_hash_table

#define int ll
#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
#define size(x) (ll)(x).size()

const int INF = 2e9;
const int MOD = 1e9 + 7;

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<pii> ps(n);
    for (int i = 0; i < n; i++) {
        cin >> ps[i].first >> ps[i].second;
    }

    /*
    y = x + a
    (-1)x + y + -a' = 0
    a = -1, b = 1, c = -a'
    */

    auto query = [&](double at) {
        double tot = 0;
        double a = -1, b = 1, c = -at;
        for (auto [x0, y0] : ps) {
            tot += pow(a * x0 + b * y0 + c, 2) / 2.0;
        }
        return tot;
    };

    double lb = -1e7, rb = 1e7;
    while (rb - lb > 1e-4) {
        double r = rb - lb;
        double b1 = lb + (r / 3.0);
        double b2 = rb - (r / 3.0);
        double a1 = query(b1);
        double a2 = query(b2);

        if (a1 < a2) {
            rb = b2;
        }
        else {
            lb = b1;
        }
    }

    cout << fixed << setprecision(20) << lb << "\n";
}
