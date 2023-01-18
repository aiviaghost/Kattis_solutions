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

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void solve(double w, double g, double h, double r) {

    auto query = [&](double x) {
        return dist(0, g, x, r) + dist(x, r, w, h);
    };

    double lb = 0, rb = w;
    while (rb - lb > 1e-9) {
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

    cout << fixed << setprecision(20) << dist(0, g, w, h) << " " << query(lb) << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    while (n--) {
        int w, g, h, r;
        cin >> w >> g >> h >> r;
        solve(w, g, h, r);
    }
}
