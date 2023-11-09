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

struct Pipe {
    P well, end;

    bool intersects(Pipe other) {
        return size(seg_inter(well, end, other.well, other.end)) > 0;
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int w, p;
    cin >> w >> p;
    vector<P> wells(w);
    for (int i = 0; i < w; i++) {
        int x, y;
        cin >> x >> y;
        wells[i] = P(x, y);
    }
    vector<Pipe> pipes;
    for (int i = 0; i < p; i++) {
        int s, x, y;
        cin >> s >> x >> y, s--;
        pipes.push_back({wells[s], P(x, y)});
    }

    vector<vector<int>> adj(p);
    for (int i = 0; i < p; i++) {
        for (int j = i + 1; j < p; j++) {
            if (pipes[i].well == pipes[j].well) {
                continue;
            }
            if (pipes[i].intersects(pipes[j])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    bool is_bipartite = true;
    vector<int> color(p, -1);
    auto dfs = [&](auto&& dfs, int curr, int curr_color) -> void {
        color[curr] = curr_color;
        for (int next : adj[curr]) {
            if (color[next] == -1) {
                dfs(dfs, next, 1 - curr_color);
            }
            else if (color[next] == curr_color) {
                is_bipartite = false;
                return;
            }

        }
    };

    for (int i = 0; i < p; i++) {
        if (color[i] == -1) {
            dfs(dfs, i, 0);
        }
    }

    cout << (is_bipartite ? "possible" : "impossible") << "\n";
}
