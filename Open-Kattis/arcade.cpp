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

const int IHF = 2e9;
const int MOD = 1e9 + 7;

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    int H = ((n * (n + 1)) >> 1);
    vector<int> vals(H);
    for (int i = 0; i < H; i++) {
        cin >> vals[i];
    }

    vector<vector<pair<int, double>>> adj(H + 1);
    int curr = 0;
    int row = 1;
    int col = 0;
    for (int i = 0; i < H; i++) {
        auto get_first_on_row = [](int k) { return (k * (k - 1)) >> 1; };

        double p;

        cin >> p;
        if (col != 0) {
            adj[curr].push_back({get_first_on_row(row - 1) + col - 1, p});
        }

        cin >> p;
        if (col != row - 1) {
            adj[curr].push_back({get_first_on_row(row - 1) + col, p});
        }

        cin >> p;
        if (row != n) {
            adj[curr].push_back({get_first_on_row(row + 1) + col, p});
        }

        cin >> p;
        if (row != n) {
            adj[curr].push_back({get_first_on_row(row + 1) + col + 1, p});
        }

        cin >> p;
        adj[curr].push_back({H, p});

        curr++;
        col++;
        if (col == row) {
            row++;
            col = 0;
        }
    }

    vector<double> E(1 + H);
    while (1) {
        double diff = 0;
        for (int u = 0; u < H; u++) {
            double prev = E[u];
            E[u] = 0;
            for (auto [v, p] : adj[u]) {
                int r = v == H ? vals[u] : 0;
                E[u] += (E[v] + r) * p;        
            }
            diff = max(diff, abs(E[u] - prev));
        }
        if (diff < 4e-8) {
            break;
        }
    }

    cout << fixed << setprecision(20) << E[0] << "\n";
}
