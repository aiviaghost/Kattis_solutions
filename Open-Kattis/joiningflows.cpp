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

using Tap = tuple<ll, ll, ll>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int k;
    cin >> k;
    vector<Tap> taps(k);
    for (int i = 0; i < k; i++) {
        cin >> get<0>(taps[i]) >> get<1>(taps[i]) >> get<2>(taps[i]);
    }
    int r;
    cin >> r;
    while (r--) {
        int temp_req, flow_req;
        cin >> temp_req >> flow_req;
        bool ok = true;
        double mi = 0;
        ll flow = 0;
        for (auto [t, a, b] : taps) {
            mi += t * a;
            flow += a;
        }
        sort(taps.begin(), taps.end(), [&](Tap & a, Tap & b) {
            return get<0>(a) < get<0>(b);
        });
        for (auto [t, a, b] : taps) {
            ll f = min(b - a, flow_req - flow);
            mi += t * f;
            flow += f;
        }
        mi /= (double) flow;
        if (flow < flow_req || mi > temp_req) {
            ok = false;
        }
        double ma = 0;
        flow = 0;
        for (auto [t, a, b] : taps) {
            ma += t * a;
            flow += a;
        }
        sort(taps.begin(), taps.end(), [&](Tap & a, Tap & b) {
            return get<0>(a) > get<0>(b);
        });
        for (auto [t, a, b] : taps) {
            ll f = min(b - a, flow_req - flow);
            ma += t * f;
            flow += f;
        }
        ma /= (double) flow;
        if (flow < flow_req || ma < temp_req) {
            ok = false;
        }
        cout << (ok ? "yes\n" : "no\n");
    }
}
