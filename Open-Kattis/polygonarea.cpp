#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// #define unordered_map gp_hash_table

#define int ll
#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
#define sz(x) (ll)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vi = vector<int>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

const int INF = 2e9;
const int MOD = 1e9 + 7;

void area(vector<pair<int, int>> &coords) {
    double area = 0;
    int s = coords.size();
    for (int i = 0; i < s; i++) {
        area += (coords[i].first * coords[(i + 1) % s].second) - (coords[(i + 1) % s].first * coords[i].second);
    }
    cout << (area > 0 ? "CCW" : "CW") << " " << abs(area) / 2 << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    cout << fixed << setprecision(1);

    int n;
    while (cin >> n && n != 0) {
        vector<pair<int, int>> coords;
        while (n--) {
            int x, y;
            cin >> x >> y;
            coords.push_back({x, y});
        }
        area(coords);
    }
}
