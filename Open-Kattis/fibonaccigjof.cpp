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

using ll = unsigned long long;
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

inline int get_int() {
    int r = 0;
    char c = getchar_unlocked();
    while (c < '0' || '9' < c) {
        c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9') {
        r = 10 * r + c - '0';
        c = getchar_unlocked();
    }
    return r;
}

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

    M operator+(const M &m) const
    {
        M a;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                a.d[i][j] = d[i][j] + m.d[i][j];
            }
        }
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

using ModMat = Matrix<Mod, 2>;

ModMat unit, zero, eye;
array<Mod, 2> fib_base({1, 1});

class LazySegTree
{
private:
    int n4;
    vector<int> L, R, lazy;
    vector<ModMat> value;

    void combine(int i)
    {
        value[i] = value[2 * i] + value[2 * i + 1];
    }

    void push(int i)
    {
        if (lazy[i] == 0) {
            return;
        }

        ModMat update = unit ^ lazy[i];
        value[2 * i] = value[2 * i] * update;
        value[2 * i + 1] = value[2 * i + 1] * update;
        
        lazy[2 * i] += lazy[i];
        lazy[2 * i + 1] += lazy[i];
        lazy[i] = 0;
    }

    void setup(int i, int l, int r)
    {
        L[i] = l;
        R[i] = r;
        if (l == r)
        {
            return;
        }

        int mid = (l + r) / 2;
        setup(2 * i, l, mid);
        setup(2 * i + 1, mid + 1, r);
        combine(i);
    }

    void add(int i, int l, int r, int d, const ModMat &m_d)
    {
        if (r < L[i] || R[i] < l)
        {
            return;
        }

        if (l <= L[i] && R[i] <= r)
        {
            value[i] = value[i] * m_d;
            lazy[i] += d;
            return;
        }

        push(i);

        add(2 * i, l, r, d, m_d);
        add(2 * i + 1, l, r, d, m_d);
        combine(i);
    }

    ModMat query(int i, int l, int r)
    {
        if (r < L[i] || R[i] < l)
        {
            return zero;
        }

        if (l <= L[i] && R[i] <= r)
        {
            return value[i];
        }

        push(i);

        return (query(2 * i, l, r) + query(2 * i + 1, l, r));
    }

public:
    LazySegTree(int n) : n4(4 * n), L(n4), R(n4), value(n4, eye), lazy(n4)
    {
        setup(1, 0, n - 1);
    }

    void add(int l, int r, int d)
    {
        add(1, l, r, d, unit ^ d);
    }

    ModMat query(int l, int r)
    {
        return query(1, l, r);
    }
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    unit.d = {{{1, 1},
               {1, 0}}};
    zero.d = {{{0, 0},
               {0, 0}}};
    eye.d = {{{1, 0},
              {0, 1}}};    

    int n = get_int(), m = get_int();

    LazySegTree tree(n);
    for (int i = 0; i < n; i++)
    {
        int x = get_int();
        tree.add(i, i, x - 1);
    }
    
    for (int i = 0; i < m; i++)
    {
        int op = get_int(), l = get_int() - 1, r = get_int() - 1;
        if (op == 1)
        {
            int d = get_int();
            tree.add(l, r, d);
        }
        else
        {
            cout << (tree.query(l, r) * fib_base)[1].x << "\n";
        }
    }
}
