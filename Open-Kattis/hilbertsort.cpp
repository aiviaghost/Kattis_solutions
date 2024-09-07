#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// #define unordered_map gp_hash_table

#define int ll
#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
#define size(x) (ll)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)

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

int get_quadrant(double x, double y, double s) {
    return x < s / 2 ? y < s / 2 ? 1 : 2 : y > s / 2 ? 3 : 4;
}

double flip_vertically(double y, double yt) {
    return yt + (yt - y);
}

bool hilbert_cmp(double x1, double y1, double x2, double y2, double s) {
    int q1 = get_quadrant(x1, y1, s);
    int q2 = get_quadrant(x2, y2, s);
    if (q1 != q2) {
        return q1 < q2;
    }

    if (q1 == 1) {
        y1 = flip_vertically(y1, s / 4);
        y2 = flip_vertically(y2, s / 4);

        return hilbert_cmp(
            -y1 + s / 2,
            x1,
            -y2 + s / 2,
            x2,
            s / 2
        );
    }
    else if (q1 == 2) {
        return hilbert_cmp(
            x1,
            y1 - s / 2,
            x2,
            y2 - s / 2,
            s / 2
        );
    }
    else if (q1 == 3) {
        return hilbert_cmp(
            x1 - s / 2,
            y1 - s / 2,
            x2 - s / 2,
            y2 - s / 2,
            s / 2
        );
    }
    else {
        y1 = flip_vertically(y1, s / 4);
        y2 = flip_vertically(y2, s / 4);

        return hilbert_cmp(
            y1,
            -x1 + s,
            y2,
            -x2 + s,
            s / 2
        );
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    double s;
    cin >> s;
    vector<pii> ps(n);
    for (auto&& p : ps) {
        cin >> p.first >> p.second;
    }

    sort(all(ps), [&](pdd a, pdd b) {
        return hilbert_cmp(a.first, a.second, b.first, b.second, s);
        });

    for (auto p : ps) {
        cout << p.first << " " << p.second << "\n";
    }
}
