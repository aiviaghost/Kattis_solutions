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

struct Mod
{
    ll x;
    Mod() : x(0) {}
    Mod(ll xx) : x(xx) {}
    Mod operator+(const Mod b) const { return Mod((x + b.x) % MOD); }
    Mod operator-(const Mod b) const { return Mod((x - b.x + MOD) % MOD); }
    Mod operator*(const Mod b) const { return Mod((x * b.x) % MOD); }
};

template <class T, int N>
struct Matrix
{
    typedef Matrix M;
    array<array<T, N>, N> d{};
    M operator*(const M &m) const
    {
        M a;
        rep(i, 0, N) rep(j, 0, N)
            rep(k, 0, N) a.d[i][j] = a.d[i][j] + d[i][k] * m.d[k][j];
        return a;
    }
    array<T, N> operator*(const array<T, N> &vec) const
    {
        array<T, N> ret{};
        rep(i, 0, N) rep(j, 0, N) ret[i] = ret[i] + d[i][j] * vec[j];
        return ret;
    }
    M operator^(ll p) const
    {
        assert(p >= 0);
        M a, b(*this);
        rep(i, 0, N) a.d[i][i] = 1;
        while (p)
        {
            if (p & 1)
                a = a * b;
            b = b * b;
            p >>= 1;
        }
        return a;
    }
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    auto grid_to_idx = [&](int i, int j) -> int
    {
        return i * 8 + j;
    };

    array<array<Mod, 64>, 64> adj;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    if ((k != 0) || (l != 0))
                    {
                        int new_i = i + k;
                        int new_j = j + l;
                        if (0 <= new_i && new_i < 8 && 0 <= new_j && new_j < 8)
                        {
                            adj[grid_to_idx(i, j)][grid_to_idx(new_i, new_j)] = 1;
                        }
                    }
                }
            }
        }
    }

    Matrix<Mod, 64> adj_matrix;
    adj_matrix.d = adj;

    int n;
    cin >> n;

    cout << (adj_matrix ^ n).d[0][63].x << "\n";
}
