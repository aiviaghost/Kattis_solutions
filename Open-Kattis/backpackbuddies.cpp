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

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    const int start = 0;
    const int end = n - 1;
    const int start_of_day = 8;
    const int end_of_day = 20;
    const int night_duration = 12;

    auto dr_knight = [&]() -> int {
        vector<int> dist(n, INF);
        dist[start] = start_of_day;

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({dist[start], start});

        while (!pq.empty()) {
            auto [curr_dist, curr] = pq.top();
            pq.pop();

            if (curr_dist > dist[curr]) {
                continue;
            }

            int time_of_day = curr_dist % 24;
            for (auto [next, w] : adj[curr]) {
                
                int new_time;
                if (time_of_day + w <= end_of_day) {
                    new_time = curr_dist + w;
                }
                else {
                    int rest_of_day = end_of_day - time_of_day;
                    new_time = curr_dist + rest_of_day + night_duration + (w - rest_of_day);
                }

                if (new_time < dist[next]) {
                    dist[next] = new_time;
                    pq.push({new_time, next});
                }
            }
        }

        return dist[end];
    };

    auto mr_day = [&]() -> int {
        vector<int> dist(n, INF);
        dist[start] = start_of_day;

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({dist[start], start});

        while (!pq.empty()) {
            auto [curr_dist, curr] = pq.top();
            pq.pop();

            if (curr_dist > dist[curr]) {
                continue;
            }

            int time_of_day = curr_dist % 24;
            for (auto [next, w] : adj[curr]) {
                
                int new_time;
                if (time_of_day + w <= end_of_day) {
                    new_time = curr_dist + w;
                }
                else {
                    int rest_of_day = end_of_day - time_of_day;
                    new_time = curr_dist + rest_of_day + night_duration + w;
                }

                if (new_time < dist[next]) {
                    dist[next] = new_time;
                    pq.push({new_time, next});
                }
            }
        }

        return dist[end];
    };

    cout << mr_day() - dr_knight() << "\n";
}
