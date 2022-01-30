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

    int n, m, s, d;
    cin >> n >> m >> s >> d;
    vector<int> slots(s);
    for (int i = 0; i < s; i++) {
        cin >> slots[i];
    }
    vector<int> inds(s);
    iota(all(inds), 0);
    sort(all(inds), [&](int i, int j) {
        return slots[i] < slots[j];
    });
    vector<int> c(s);
    for (int i : inds) {
        c[i] += min(d - slots[i], n);
        n -= min(d - slots[i], n);
        if (n == 0) {
            break;
        }
    }
    bool ok = false;
    int su = 0;
    for (int i = 0; i < s; i++) {
        if (c[i] == 0) {
            su += slots[i];
        }
        if (su >= m) {
            ok = true;
            break;
        }
    }
    if (ok) {
        cout << c[0];
        for (int i = 1; i < s; i++) {
            cout << " " << c[i];
        }
        cout << "\n";
    }
    else {
        cout << "impossible\n";
    }
}
