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

const int INF = 2e9;
const int MOD = 1e9 + 7;

vector<double> probs;
vector<vector<double>> E;

double dfs(int n, int m) {
    if (n == 0 || m == 0) {
        return 0;
    }

    if (E[n][m] != -1) {
        return E[n][m];
    }

    E[n][m] = 0;
    E[n][m] += (dfs(n, m - 1) + (m - 1 == 0 ? 1 : 0)) * probs[n + m - 2];
    E[n][m] += (dfs(n - 1, m) + 0) * (1 - probs[n + m - 2]);
    
    return E[n][m];
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    probs.resize(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        cin >> probs[i];
    }
    reverse(all(probs));

    E = make(-1.0, n + 1, m + 1);

    cout << fixed << setprecision(20) << dfs(n, m) << "\n";
}
