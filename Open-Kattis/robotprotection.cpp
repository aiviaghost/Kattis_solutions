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

auto get_convex_hull(vector<pii> &points) -> vector<pii> {
    auto clockwise = [](pii &a, pii &b, pii &c) {
        pii ab = {b.first - a.first, b.second - a.second};
        pii ac = {c.first - a.first, c.second - a.second};
        return (ab.first * ac.second - ab.second * ac.first) > 0;
    };

    int n = points.size();
    if (n <= 1) {
        return points;
    }

    sort(points.begin(), points.end());
    vector<pii> upper_hull{points[0], points[1]}, lower_hull{points[n - 1], points[n - 2]};
    for (int i = n - 2; i >= 0; i--) {
        while (lower_hull.size() > 1 && !clockwise(points[i], lower_hull[lower_hull.size() - 1], lower_hull[lower_hull.size() - 2])) {
            lower_hull.pop_back();
        }
        lower_hull.push_back(points[i]);
    }

    for (int i = 2; i < n; i++) {
        while (upper_hull.size() > 1 && !clockwise(points[i], upper_hull[upper_hull.size() - 1], upper_hull[upper_hull.size() - 2])) {
            upper_hull.pop_back();
        }
        upper_hull.push_back(points[i]);
    }

    upper_hull.insert(upper_hull.end(), lower_hull.begin() + 1, lower_hull.end() - 1);
    reverse(upper_hull.begin(), upper_hull.end());

    if (upper_hull.front() == upper_hull.back()) {
        upper_hull.erase(upper_hull.begin());
    }
    return upper_hull;
}

double area(const vector<pair<int, int>> &coords) {
    double area = 0;
    int s = coords.size();
    for (int i = 0; i < s; i++) {
        area += (coords[i].first * coords[(i + 1) % s].second) - (coords[(i + 1) % s].first * coords[i].second);
    }
    return abs(area) / 2;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    while (cin >> n && n != 0) {
        vector<pii> pts(n);
        for (auto&& p : pts) {
            cin >> p.first >> p.second;
        }
        cout << area(get_convex_hull(pts)) << "\n";
    }
}
