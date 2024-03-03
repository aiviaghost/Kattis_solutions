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

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> in_deg(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        in_deg[i] += m;
        for (int j = 0; j < m; j++) {
            int d;
            cin >> d, d--;
            adj[d].push_back(i);
        }
    }

    vector<vector<int>> layers;

    vector<int> curr_layer;
    for (int i = 0; i < n; i++) {
        if (in_deg[i] == 0) {
            curr_layer.push_back(i);
        }
    }

    int vc = 0;
    while (!curr_layer.empty()) {
        layers.push_back(curr_layer);

        vector<int> next_layer;
        for (int curr : curr_layer) {
            vc++;
            for (int next : adj[curr]) {
                in_deg[next]--;
                if (in_deg[next] == 0) {
                    next_layer.push_back(next);
                }
            }
        }
        curr_layer = next_layer;
    }

    if (vc < n) {
        cout << "Omogulegt!\n";
    }
    else {
        cout << "Mogulegt!\n";
        cout << size(layers) << "\n";
        for (auto layer : layers) {
            cout << size(layer);
            for (int x : layer) {
                cout << " " << x + 1;
            }
            cout << "\n";
        }
    }
}
