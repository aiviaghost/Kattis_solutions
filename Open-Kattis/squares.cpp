#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

#define all(x) x.begin(), x.end()
#define in(x, a) (x.find(a) != x.end())

const ll INF = 2e9;
const ll MOD = 1e9 + 7;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define unordered_map gp_hash_table

using Poll = pii;
using Dir = pii;

pii mult(const pii & a, const pii & b) {
    pii res = {a.first * b.first, a.second * b.second};
    ll g = __gcd(res.first, res.second);
    res.first /= g;
    res.second /= g;
    return res;
}

pii add(const pii & a, const pii & b) {
    pii res = {a.first * b.second + b.first * a.second, a.second * b.second};
    ll g = __gcd(res.first, res.second);
    res.first /= g;
    res.second /= g;
    return res;
}

pii sub(const pii & a, const pii & b) {
    pii res = {a.first * b.second - b.first * a.second, a.second * b.second};
    ll g = __gcd(res.first, res.second);
    res.first /= g;
    res.second /= g;
    return res;
}

struct Line {
    Poll A;
    Dir dir;
    Line(ll x1, ll y1, ll x2, ll y2) {
        A = {x1, y1};
        dir = {x2 - x1, y2 - y1};
        ll g = __gcd(dir.first, dir.second);
        dir.first /= g;
        dir.second /= g;
        if (dir.first < 0) {
            dir.first *= -1;
            dir.second *= -1;
        }
    }

    pii dist(const Line & other) {
        Dir d = {A.first - other.A.first, A.second - other.A.second};
        pii c = {(d.first * dir.first + d.second * dir.second), (dir.first * dir.first + dir.second * dir.second)};
        pair<pii, pii> x_par = {mult(c, {dir.first, 1}), mult(c, {dir.second, 1})};
        pair<pii, pii> x_perp = {sub({d.first, 1}, x_par.first), sub({d.second, 1}, x_par.second)};
        return add(mult(x_perp.first, x_perp.first), mult(x_perp.second, x_perp.second));
    }
};

Dir calc_perp(const Dir & dir) {
    Dir perp = {-dir.second, dir.first};
    if (perp.first < 0) {
        perp.first *= -1;
        perp.second *= -1;
    }
    return perp;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    map<Dir, vector<Line>> d2l;
    for (ll i = 0; i < n; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Line line = {x1, y1, x2, y2};
        d2l[line.dir].push_back(line);
    }
    map<Dir, map<pii, ll>> d2d;
    for (auto [dir, lines] : d2l) {
        ll len = lines.size();
        for (ll i = 0; i < len; i++) {
            for (ll j = i + 1; j < len; j++) {
                d2d[dir][lines[i].dist(lines[j])]++;
            }
        }
    }
    ll ans = 0;
    set<Dir> seen;
    for (auto [dir, v] : d2d) {
        if (in(seen, dir)) {
            continue;
        }
        seen.emplace(dir);
        Dir perp = calc_perp(dir);
        if (in(d2d, perp)) {
            for (auto [dist, count] : v) {
                if (in(d2d[perp], dist)) {
                    ans += d2d[perp][dist] * count;
                }
            }
        }
    }
    cout << ans / 2 << "\n";
}
