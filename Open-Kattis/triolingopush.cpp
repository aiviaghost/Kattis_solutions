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
    Mod(ll xx) : x(xx) {}
    Mod() : x(0) {}
    Mod operator+(const Mod &b) const { return Mod((x + b.x) % MOD); }
    Mod &operator+=(const Mod &b)
    {
        x = (x + b.x) % MOD;
        return *this;
    }
    Mod operator-(const Mod &b) const { return Mod((x - b.x + MOD) % MOD); }
    Mod operator*(const Mod &b) const { return Mod((x * b.x) % MOD); }
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
            rep(k, 0, N) a.d[i][j] += d[i][k] * m.d[k][j];
        return a;
    }
    vector<T> operator*(const vector<T> &vec) const
    {
        vector<T> ret(N);
        rep(i, 0, N) rep(j, 0, N) ret[i] += d[i][j] * vec[j];
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

    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1 << "\n";
        return 0;
    }

    Matrix<Mod, 3> M;
    M.d = {{{{Mod(1), Mod(1), Mod(1)}},
            {{Mod(1), Mod(0), Mod(0)}},
            {{Mod(0), Mod(0), Mod(1)}}}};
    vector<Mod> v = {
        Mod(2),
        Mod(1),
        Mod(1)};

    auto res = (M ^ (n - 1)) * v;

    cout << res[1].x << "\n";
}
