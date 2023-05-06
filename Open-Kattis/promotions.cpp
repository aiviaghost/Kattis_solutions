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

const int MAX_N = 5000;

vector<int> count_descendants(const vector<vector<int>> & adj) {
    int n = size(adj);
    vector<bitset<MAX_N>> descendants(n);

    vector<int> in_deg(n);
    for (int i = 0; i < n; i++) {
        descendants[i][i] = 1;
        for (int next : adj[i]) {
            in_deg[next]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in_deg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int next : adj[curr]) {
            descendants[next] |= descendants[curr];
            in_deg[next]--;
            if (in_deg[next] == 0) {
                q.push(next);
            }
        }
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = descendants[i].count();
    }
    return ans;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int A, B, E, P;
    cin >> A >> B >> E >> P;
    vector<vector<int>> adj(E), inv_adj(E);
    for (int i = 0; i < P; i++) {
        int x, y;
        cin >> x >> y;
        adj[y].push_back(x);
        inv_adj[x].push_back(y);
    }

    vector<int> dc = count_descendants(inv_adj);
    vector<int> dc_inv = count_descendants(adj);

    int ans_1 = 0, ans_2 = 0;
    for (int i = 0; i < E; i++) {
        ans_1 += E - dc_inv[i] < A;
        ans_2 += E - dc_inv[i] < B;
    }
    cout << ans_1 << "\n";
    cout << ans_2 << "\n";

    int ans_3 = 0;
    for (int i = 0; i < E; i++) {
        ans_3 += dc[i] > B;
    }
    cout << ans_3 << "\n";
}
