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

vector<vector<int>> adj;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    adj.resize(n);
    vector<int> in_deg(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b, a--, b--;
        adj[a].push_back(b);
        in_deg[b]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in_deg[i] == 0) {
            q.push(i);
        }
    }
    vector<int> order;
    while (!q.empty()) {
        int curr = q.front(); 
        q.pop();
        order.push_back(curr);
        for (int next : adj[curr]) {
            in_deg[next]--;
            if (in_deg[next] == 0) {
                q.push(next);
            }
        }
    }
    if (order.size() != n) {
        cout << "IMPOSSIBLE\n";
    }
    for (int i : order) {
        cout << i + 1 << "\n";
    }
}
