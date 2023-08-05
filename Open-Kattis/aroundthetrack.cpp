#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define unordered_map gp_hash_table

#define int ll
#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
#define size(x) (ll)(x).size()

#define rep(i, a, b) for(int i = a; i < (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

const long double INF = numeric_limits<long double>::max();
const int MOD = 1e9 + 7;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
    bool operator!=(P p) const { return !(*this == p); }
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(T d) const { return P(x * d, y * d); }
    P operator/(T d) const { return P(x / d, y / d); }
    T dot(P p) const { return x * p.x + y * p.y; }
    T cross(P p) const { return x * p.y - y * p.x; }
    T cross(P a, P b) const { return (a - *this).cross(b - *this); }
    T dist2() const { return x * x + y * y; }
    long double dist() const { return sqrt((long double)dist2()); }
    // angle to x-axis in interval [-pi, pi]
    long double angle() const { return atan2(y, x); }
    P unit() const { return *this / dist(); } // makes dist()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};
typedef Point<int> P;
namespace std {
    template<> struct hash<P> {
        size_t operator()(const P& p) const noexcept {
            return 10'000 * p.x + p.y;
        }
    };
}

vector<P> get_convex_hull(vector<P> pts) {
    if (size(pts) <= 1) return pts;
    sort(all(pts));
    vector<P> h(size(pts) + 1);
    int s = 0, t = 0;
    for (int it = 2; it--; s = --t, reverse(all(pts)))
        for (P p : pts) {
            while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0) t--;
            h[t++] = p;
        }
    vector<P> res = { h.begin(), h.begin() + t - (t == 2 && h[0] == h[1]) };
    return res;
}

vector<P> inner_poly, outer_poly, inner_hull;

template<class P> bool onSegment(P s, P e, P p) {
    return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

template<class P> vector<P> seg_inter(P a, P b, P c, P d) {
    auto oa = c.cross(d, a), ob = c.cross(d, b),
        oc = a.cross(b, c), od = a.cross(b, d);
    // Checks if intersection is single non-endpoint point.
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
        return { (a * ob - b * oa) / (ob - oa) };
    set<P> s;
    if (onSegment(c, d, a)) s.insert(a);
    if (onSegment(c, d, b)) s.insert(b);
    if (onSegment(a, b, c)) s.insert(c);
    if (onSegment(a, b, d)) s.insert(d);
    return { all(s) };
}

template<class P>
bool in_polygon(vector<P>& p, P a, bool strict = true) {
    int cnt = 0, n = size(p);
    rep(i, 0, n) {
        P q = p[(i + 1) % n];
        if (onSegment(p[i], q, a)) return !strict;
        cnt ^= ((a.y < p[i].y) - (a.y < q.y)) * a.cross(p[i], q) > 0;
    }
    return cnt;
}

bool line_poly_intersect(const vector<P>& poly, P a, P b) {
    int n = size(poly);
    for (int i = 0; i < n; i++) {
        if (a != poly[i] && a != poly[(i + 1) % n] && b != poly[i] && b != poly[(i + 1) % n] && size(seg_inter(a, b, poly[i], poly[(i + 1) % n])) >= 1) {
            return true;
        }
    }
    return false;
}

long double shortest_dist(int a, int b) {
    int start, end;
    for (int i = 0; i < size(inner_poly); i++) {
        if (inner_poly[i] == inner_hull[a]) {
            start = i;
        }
        else if (inner_poly[i] == inner_hull[b]) {
            end = i;
        }
    }
    vector<P> contained_inner;
    for (int i = start; i != end; i = (i + 1) % size(inner_poly)) {
        contained_inner.push_back(inner_poly[i]);
    }
    contained_inner.push_back(inner_poly[end]);

    vector<P> contained_outer;
    for (P p : outer_poly) {
        if (in_polygon(contained_inner, p, false)) {
            contained_outer.push_back(p);
        }
    }

    int n = size(contained_inner), m = size(contained_outer);
    vector<vector<pair<int, long double>>> adj(n + m);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            P mid = (contained_inner[i] + contained_inner[j]) / 2;
            if (!in_polygon(inner_poly, mid) && !line_poly_intersect(inner_poly, contained_inner[i], contained_inner[j]) && !line_poly_intersect(outer_poly, contained_inner[i], contained_inner[j])) {
                long double d = (contained_inner[i] - contained_inner[j]).dist();
                adj[i].push_back({ j, d });
                adj[j].push_back({ i, d });
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!line_poly_intersect(inner_poly, contained_inner[i], contained_outer[j]) && !line_poly_intersect(outer_poly, contained_inner[i], contained_outer[j])) {
                long double d = (contained_inner[i] - contained_outer[j]).dist();
                adj[i].push_back({ n + j, d });
                adj[n + j].push_back({ i, d });
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            P mid = (contained_outer[i] + contained_outer[j]) / 2;
            if (in_polygon(outer_poly, mid, false) && !line_poly_intersect(inner_poly, contained_outer[i], contained_outer[j]) && !line_poly_intersect(outer_poly, contained_outer[i], contained_outer[j])) {
                long double d = (contained_outer[i] - contained_outer[j]).dist();
                adj[n + i].push_back({ n + j, d });
                adj[n + j].push_back({ n + i, d });
            }
        }
    }

    vector<long double> dist(n + m, INF);
    dist[0] = 0;
    priority_queue<pair<long double, int>, vector<pair<long double, int>>, greater<pair<long double, int>>> pq;
    pq.push({ 0, 0 });
    while (!pq.empty()) {
        auto [_, curr] = pq.top();
        pq.pop();
        for (auto [next, w] : adj[curr]) {
            long double new_dist = dist[curr] + w;
            if (new_dist < dist[next]) {
                dist[next] = new_dist;
                pq.push({ new_dist, next });
            }
        }
    }

    return dist[n - 1] / 2;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    inner_poly.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> inner_poly[i].x >> inner_poly[i].y;
        inner_poly[i].x *= 2;
        inner_poly[i].y *= 2;
    }
    int m;
    cin >> m;
    outer_poly.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> outer_poly[i].x >> outer_poly[i].y;
        outer_poly[i].x *= 2;
        outer_poly[i].y *= 2;
    }

    inner_hull = get_convex_hull(inner_poly);

    long double ans = 0;
    for (int i = 0; i < size(inner_hull); i++) {
        ans += shortest_dist(i, (i + 1) % size(inner_hull));
    }
    cout << fixed << setprecision(20) << ans << "\n";
}
