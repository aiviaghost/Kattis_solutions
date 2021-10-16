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

int cover(double A, double B, vector<pdd>& ints) {
    vector<int> inds(ints.size());
    iota(inds.begin(), inds.end(), 0);
    sort(inds.begin(), inds.end(), [&](int i, int j) {
        return ints[i] < ints[j];
    });
    double rb = A;
    int chosen = 0, i = 0;
    while (rb < B || chosen == 0) {
        pair<double, int> best = {rb, -1};
        while (i < ints.size() && ints[inds[i]].first <= rb) {
            best = max({ints[inds[i]].second, inds[i]}, best);
            i++;
        }
        if (best.second == -1) {
            return -1;
        }
        rb = best.first;
        chosen++;
    }
    return chosen;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    double l, w;
    while (cin >> n >> l >> w) {
        vector<pdd> ints(n);
        for (int i = 0; i < n; i++) {
            double x, r;
            cin >> x >> r;
            if (2 * r < w) {
                continue;
            }
            double a = (M_PI / 2.0) - asin(w / (2.0 * r));
            double d = r * sin(a);
            ints[i] = {x - d, x + d};
        }
        cout << cover(0, l, ints) << "\n";
    }
}
