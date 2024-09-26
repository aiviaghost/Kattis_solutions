#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define unordered_map gp_hash_table

#define int ll
#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
#define sz(x) (ll)(x).size()
#define rep(i, a, b) for (int i = a; i < (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vi = vector<int>;

template <typename T>
vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args>
auto make(T init, size_t first, Args... sizes)
{
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

const int INF = 2e9;
const int MOD = 1e9 + 7;

struct UnionFind
{
    vector<int> repr, size;

    UnionFind(int n) : repr(n), size(n, 1)
    {
        iota(all(repr), 0);
    }

    int find(int a)
    {
        if (repr[a] != a)
        {
            repr[a] = find(repr[a]);
        }
        return repr[a];
    }

    void join(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
        {
            return;
        }
        if (size[b] > size[a])
        {
            swap(a, b);
        }
        repr[b] = a;
        size[a] += size[b];
    }

    bool is_same_component(int a, int b)
    {
        return find(a) == find(b);
    }
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, m, Q;
    cin >> n >> m >> Q;

    vector<unordered_map<int, null_type>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    struct Query
    {
        bool ask;
        int u, v;
        Query() {}
    };

    vector<Query> queries(Q);
    for (auto &&q : queries)
    {
        cin >> q.ask >> q.u >> q.v;
        if (!q.ask)
        {
            adj[q.u].erase(q.v);
            adj[q.v].erase(q.u);
        }
    }

    UnionFind UF(n);
    vector<bool> vis(n);
    queue<int> q;
    for (int start = 0; start < n; start++)
    {
        if (vis[start])
        {
            continue;
        }

        q.push(start);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (int next : adj[curr])
            {
                if (!vis[next])
                {
                    vis[next] = true;
                    UF.join(curr, next);
                    q.push(next);
                }
            }
        }
    }

    vector<string> ans;
    reverse(all(queries));
    for (auto [ask, u, v] : queries)
    {
        if (!ask)
        {
            UF.join(u, v);
            continue;
        }

        ans.push_back(UF.is_same_component(u, v) ? "safe" : "unsafe");
    }

    reverse(all(ans));
    for (auto s : ans)
    {
        cout << s << "\n";
    }
}
