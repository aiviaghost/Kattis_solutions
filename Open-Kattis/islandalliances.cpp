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

struct UF
{
    vector<int> repr;
    vector<vector<int>> distrusted;
    vector<unordered_set<int>> members;

    UF(int n) : repr(n), distrusted(n), members(n)
    {
        iota(all(repr), 0);
        for (int i = 0; i < n; i++)
        {
            members[i].insert(i);
        }
    }

    void add_distrust_relation(int a, int b)
    {
        distrusted[a].push_back(b);
        distrusted[b].push_back(a);
    }

    int find(int x)
    {
        if (repr[x] != x)
        {
            repr[x] = find(repr[x]);
        }
        return repr[x];
    }

    bool trust_each_other(int a, int b)
    {
        if (sz(distrusted[a]) < sz(distrusted[b]))
        {
            swap(a, b);
        }
        for (int x : distrusted[b])
        {
            if (in(members[a], x))
            {
                return false;
            }
        }
        return true;
    }

    bool merge(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (!trust_each_other(a, b))
        {
            return false;
        }

        if (sz(members[a]) < sz(members[b]))
        {
            swap(a, b);
        }
        repr[b] = a;
        members[a].merge(members[b]);

        if (sz(distrusted[a]) < sz(distrusted[b]))
        {
            swap(distrusted[a], distrusted[b]);
        }
        distrusted[a].insert(distrusted[a].end(), all(distrusted[b]));

        return true;
    }
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, m, q;
    cin >> n >> m >> q;

    UF uf(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        uf.add_distrust_relation(u, v);
    }

    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        cout << (uf.merge(u, v) ? "APPROVE" : "REFUSE") << "\n";
    }
}