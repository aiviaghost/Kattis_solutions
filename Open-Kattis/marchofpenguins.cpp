#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// #define unordered_map gp_hash_table

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

struct Dinic
{
    struct Edge
    {
        int to, rev;
        ll c, oc;
        ll flow() { return max(oc - c, 0LL); } // if you need flows
    };
    vi lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
    void addEdge(int a, int b, ll c, ll rcap = 0)
    {
        adj[a].push_back({b, sz(adj[b]), c, c});
        adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
    }
    ll dfs(int v, int t, ll f)
    {
        if (v == t || !f)
            return f;
        for (int &i = ptr[v]; i < sz(adj[v]); i++)
        {
            Edge &e = adj[v][i];
            if (lvl[e.to] == lvl[v] + 1)
                if (ll p = dfs(e.to, t, min(f, e.c)))
                {
                    e.c -= p, adj[e.to][e.rev].c += p;
                    return p;
                }
        }
        return 0;
    }
    ll calc(int s, int t)
    {
        ll flow = 0;
        q[0] = s;
        rep(L, 0, 31) do
        { // 'int L=30' maybe faster for random data
            lvl = ptr = vi(sz(q));
            int qi = 0, qe = lvl[s] = 1;
            while (qi < qe && !lvl[t])
            {
                int v = q[qi++];
                for (Edge e : adj[v])
                    if (!lvl[e.to] && e.c >> (30 - L))
                        q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
            }
            while (ll p = dfs(s, t, LLONG_MAX))
                flow += p;
        }
        while (lvl[t])
            ;
        return flow;
    }
    bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    double D;
    cin >> D;

    struct Ice
    {
        int x, y, num, hp;
        Ice() {}
    };

    int total_penguins = 0;
    vector<Ice> ice(n);
    for (auto &&[x, y, num, hp] : ice)
    {
        cin >> x >> y >> num >> hp;
        total_penguins += num;
    }

    vector<pii> edges;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (hypot(ice[i].x - ice[j].x, ice[i].y - ice[j].y) <= D)
            {
                edges.push_back({i, j});
                edges.push_back({j, i});
            }
        }
    }

    vector<int> ans;
    int start = 2 * n;
    for (int target = 0; target < n; target++)
    {
        Dinic flow(2 * n + 1);

        for (int u = 0; u < n; u++)
        {
            flow.addEdge(start, n + u, ice[u].num);
            flow.addEdge(n + u, u, u != target ? ice[u].hp : INF);
        }

        for (auto [u, v] : edges)
        {
            if (u != target)
            {
                flow.addEdge(u, n + v, ice[u].hp);
            }
        }

        if (flow.calc(start, target) == total_penguins)
        {
            ans.push_back(target);
        }
    }

    if (ans.empty())
    {
        cout << "-1\n";
    }
    else
    {
        for (int a : ans)
        {
            cout << a << " ";
        }
        cout << "\n";
    }
}
