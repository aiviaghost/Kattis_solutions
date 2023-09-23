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

    int n, m, p;
    cin >> n >> m >> p;
    vector<pii> js(n);
    for (int i = 0; i < n; i++) {
        cin >> js[i].first >> js[i].second;
    }
    vector<pii> ts(m);
    for (int i = 0; i < m; i++) {
        cin >> ts[i].first >> ts[i].second;
    }
    vector<pii> fs(p);
    for (int i = 0; i < p; i++) {
        cin >> fs[i].first >> fs[i].second;
    }

    vector<tuple<double, int, int>> L;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            L.push_back({hypot(js[i].first - ts[j].first, js[i].second - ts[j].second), i, j});
        }
    }

    sort(all(L));

    double ans = 0;
    vector<bool> vj(n), vt(m);
    for (auto [d, i, j] : L) {
        if (!vj[i] && !vt[j]) {
            vj[i] = vt[j] = true;
            ans += d;
        }
    }

    L.clear();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            L.push_back({hypot(js[i].first - fs[j].first, js[i].second - fs[j].second), i, j});
        }
    }

    sort(all(L));

    fill(all(vj), false);
    vector<bool> vf(p);
    for (auto [d, i, j] : L) {
        if (!vj[i] && !vf[j]) {
            vj[i] = vf[j] = true;
            ans += d;
        }
    }

    cout << fixed << setprecision(20) << ans << "\n";
}
