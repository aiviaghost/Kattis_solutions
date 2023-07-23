#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define unordered_map gp_hash_table

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

const int INF = 1e18;
const int MOD = 1e9 + 7;

struct City {
    int index, y, d, r;
};

int get_int() {
    int r = 0, c = getchar_unlocked();
    while (c < '0' || '9' < c) {
        c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9') {
        r = 10 * r + c - '0';
        c = getchar_unlocked();
    }
    return r;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n = get_int();
    vector<City> cities;
    for (int i = 0; i < n; i++) {
        int y = get_int(), d = get_int(), r = get_int();
        cities.push_back({i, y, d, r});
    }

    sort(all(cities), [&](City & c1, City & c2) {
        return c1.y < c2.y;
    });
    vector<int> lookup(n);
    for (int i = 0; i < n; i++) {
        lookup[cities[i].index] = i;
    }
    vector<City> revved = cities;
    reverse(all(revved));

    vector<vector<pii>> adj(3 * n);    
    for (int i = n; i < 2 * n; i++) {
        adj[i].push_back({i - n, 0});
        if (i + 1 < 2 * n) { 
            adj[i].push_back({i + 1, cities[i + 1 - n].y - cities[i - n].y});
        }
    }
    for (int i = 2 * n; i < 3 * n; i++) {
        adj[i].push_back({i - 2 * n, 0});
        if (i + 1 < 3 * n) {
            adj[i + 1].push_back({i, cities[i + 1 - 2 * n].y - cities[i - 2 * n].y});
        }
    }
    
    for (int i = 0; i < n; i++) {
        auto right = lower_bound(cities.begin() + i + 1, cities.end(), cities[i].y + cities[i].d, [](City & c, int val) {
            return c.y < val;
        });
        if (right != cities.end()) {
            int nr = right - cities.begin();
            adj[i].push_back({n + nr, cities[i].r + cities[nr].y - cities[i].y});
        }
        int rev_i = n - 1 - i;
        auto left = lower_bound(revved.begin() + rev_i + 1, revved.end(), cities[i].y - cities[i].d, [](City & c, int val) {
            return c.y > val;
        });
        if (left != revved.end()) {
            int nl = n - 1 - (left - revved.begin());
            adj[i].push_back({2 * n + nl, cities[i].r + abs(cities[nl].y - cities[i].y)});
        }
    }

    vector<int> dist(3 * n, INF);
    dist[lookup[0]] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, lookup[0]});
    while (!pq.empty()) {
        auto [cw, curr] = pq.top();
        pq.pop();
        if (cw > dist[curr]) {
            continue;
        }
        for (auto [next, w] : adj[curr]) {
            int nw = dist[curr] + w;
            if (nw < dist[next]) {
                dist[next] = nw;
                pq.push({nw, next});
            }
        }
    }

    for (int i = 1; i < n; i++) {
        cout << (dist[lookup[i]] == INF ? -1 : dist[lookup[i]]) << "\n";
    }
}
