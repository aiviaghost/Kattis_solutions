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

struct Point {
    double x, y, z;
};

Point make_point(double lat, double lon) {
    return {cos(lon * M_PI / 180) * cos(lat * M_PI / 180), sin(lon * M_PI / 180) * cos(lat * M_PI / 180), sin(lat * M_PI / 180)};
}

double vec_len(Point & p) {
    return sqrt(pow(p.x, 2.0) + pow(p.y, 2.0) + pow(p.z, 2.0));
}

double dot_prod(Point & p1, Point & p2) {
    return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
}

double calc_dist(Point & p1, Point & p2) {
    return 2 * 6381 * M_PI * (acos(dot_prod(p1, p2) / (vec_len(p1) * vec_len(p2))) / (2 * M_PI)); // add radious of erath
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    cin.ignore();
    string start, end;
    cin >> start >> end;
    unordered_map<string, Point> points;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        double lat, lon;
        cin >> lat >> lon;
        cin.ignore();
        points[s] = make_point(lat, lon);
    }
    unordered_map<string, vector<pair<string, double>>> adj;
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        double dist = calc_dist(points[a], points[b]);
        adj[a].push_back({b, dist + 100});
        adj[b].push_back({a, dist + 100});
    }
    priority_queue<pair<string, double>, vector<pair<string, double>>, greater<pair<string, double>>> pq;
    pq.push({start, 0});
    unordered_map<string, double> shame_map;
    while (!pq.empty()) {
        auto [curr, shame] = pq.top();
        pq.pop();
        for (auto [next, added_shame] : adj[curr]) {
            double new_shame = shame + added_shame;
            if (!shame_map.count(next) || new_shame < shame_map[next]) {
                shame_map[next] = new_shame;
                pq.push({next, new_shame});
            }
        }
    }
    cout << (shame_map.count(end) ? to_string(shame_map[end]) : "-1") << "\n";
}
