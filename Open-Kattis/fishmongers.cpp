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

    ll n, m;
    cin >> n >> m;
    vector<ll> wf(n);
    for (int i = 0; i < n; i++) {
        cin >> wf[i];
    }
    sort(wf.begin(), wf.end(), greater<ll>());
    vector<pll> mo(m);
    for (int i = 0; i < m; i++) {
        int x, p;
        cin >> x >> p;
        mo[i] = {x, p};
    }
    sort(mo.begin(), mo.end(), [&](pll& p1, pll& p2) {
        return p1.second > p2.second || (p1.second == p2.second && p1.first > p2.first);
    });
    vector<ll> prefix_sum(n);
    prefix_sum[0] = wf[0];
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + wf[i];
    }
    ll ans = 0;
    int fi = 0, mi = 0;
    while (fi < n && mi < m) {
        ans += fi > 0 ? mo[mi].second * (prefix_sum[min(fi + mo[mi].first - 1, n - 1)] - prefix_sum[fi - 1]) : 
                        mo[mi].second * prefix_sum[min(fi + mo[mi].first - 1, n - 1)];
        fi += mo[mi].first;
        mi++;
    }
    cout << ans << "\n";
}
