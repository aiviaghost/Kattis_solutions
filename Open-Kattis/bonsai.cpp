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

template <typename T>
vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args>
auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

const int INF = 2e9;
const int MOD = 1e9 + 7;

struct Node
{
    unordered_map<int, null_type> adj;
    vector<int> leaves;
    Node() {};
};

inline int read_int() {
    int r = 0, c = getchar_unlocked();
    while (c < '0' || '9' < c) c = getchar_unlocked();
    while ('0' <= c && c <= '9') r = r * 10 + c - '0', c = getchar_unlocked();
    return r;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n = read_int();
    vector<Node> nodes(n);
    vector<int> q;
    for (int u = 0; u < n; u++) {
        int m = read_int();
        for (int i = 0; i < m; i++) {
            int v = read_int();
            nodes[u].adj.insert(v);
            if (m == 1) {
                nodes[v].leaves.push_back(u);
                if (size(nodes[v].leaves) == 1) {
                    q.push_back(v);
                }
            }
        }
    }

    int ans = 0;
    while (!q.empty()) {
        vector<int> next_q;
        for (int curr : q) {
            int leaf = nodes[curr].leaves.back();
            nodes[curr].leaves.pop_back();
            nodes[curr].adj.erase(leaf);
            if (size(nodes[curr].adj) == 1) {
                int par = *nodes[curr].adj.begin();
                nodes[par].leaves.push_back(curr);
                if (size(nodes[par].leaves) == 1) {
                    next_q.push_back(par);
                }
            }
            else if (size(nodes[curr].leaves) > 0) {
                next_q.push_back(curr);
            }
        }
        ans++;
        swap(q, next_q);
    }

    cout << ans << "\n";
}
