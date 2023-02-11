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

    int f, b;
    cin >> f >> b;
    vector<int> fs(f);
    for (int i = 0; i < f; i++) {
        cin >> fs[i];
    }
    vector<int> bs(b);
    for (int i = 0; i < b; i++) {
        cin >> bs[i];
    }
    vector<pll> ratios;
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < b; j++) {
            ratios.push_back({fs[i], bs[j]});
        }
    }
    sort(all(ratios), [&](pll & r1, pll & r2) {
        auto [f1, b1] = r1;
        auto [f2, b2] = r2;
        return f1 * b2 < f2 * b1 || (f1 * b2 == f2 * b1 && f1 < f2);
    });

    for (auto [f, b] : ratios) {
        cout << "(" << f << "," << b << ")" << "\n";
    }
}
