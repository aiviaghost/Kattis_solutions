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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define unordered_map gp_hash_table

#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
#define size(x) (ll)(x).size()

const ll INF = 2e9;
const ll MOD = 1e9 + 7;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m, k;
    cin >> n >> m >> k;

    vector<bool> iron(n), coal(n);
    for (ll i = 0; i < m; i++) {
        ll x;
        cin >> x, x--;
        iron[x] = true;
    }
    for (ll i = 0; i < k; i++) {
        ll x;
        cin >> x, x--;
        coal[x] = true;
    }

    vector<vector<ll>> adj(n), inv_adj(n);
    for (ll i = 0; i < n; i++) {
        ll a;
        cin >> a;
        for (ll j = 0; j < a; j++) {
            ll nx;
            cin >> nx, nx--;
            adj[i].push_back(nx);
            inv_adj[nx].push_back(i);
        }
    }

    ll palace = 0;
    vector<ll> dist_from_palace(n, INF);
    dist_from_palace[palace] = 0;

    queue<ll> q({palace});
    while (!q.empty()) {
        ll curr = q.front();
        q.pop();
        for (ll nx : adj[curr]) {
            if (dist_from_palace[nx] == INF) {
                dist_from_palace[nx] = dist_from_palace[curr] + 1;
                q.push(nx);
            }
        }
    }


    vector<ll> dist_to_iron(n, INF);
    for (ll i = 0; i < n; i++) {
        if (iron[i]) {
            dist_to_iron[i] = 0;
            q.push(i);
        }
    }

    while (!q.empty()) {
        ll curr = q.front();
        q.pop();
        for (ll nx : inv_adj[curr]) {
            if (dist_to_iron[nx] == INF) {
                dist_to_iron[nx] = dist_to_iron[curr] + 1;
                q.push(nx);
            }
        }
    }

    
    vector<ll> dist_to_coal(n, INF);
    for (ll i = 0; i < n; i++) {
        if (coal[i]) {
            dist_to_coal[i] = 0;
            q.push(i);
        }
    }

    ll ans = INF;
    while (!q.empty()) {
        ll curr = q.front();
        q.pop();
        ans = min(ans, dist_from_palace[curr] + dist_to_coal[curr] + dist_to_iron[curr]);
        for (ll nx : inv_adj[curr]) {
            if (dist_to_coal[nx] == INF) {
                dist_to_coal[nx] = dist_to_coal[curr] + 1;
                q.push(nx);
            }
        }
    }

    cout << (ans >= INF ? "impossible" : to_string(ans)) << "\n";
}
