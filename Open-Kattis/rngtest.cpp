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

int m;

struct Mod
{
    ll x;
    Mod() : x(0) {}
    Mod(ll xx) : x(xx) {}
    Mod operator+(const Mod b) const { return Mod((x + b.x) % m); }
    Mod operator-(const Mod b) const { return Mod((x - b.x + m) % m); }
    Mod operator*(const Mod b) const { return Mod((x * b.x) % m); }
    Mod operator^(int exp) const
    {
        Mod res(1);
        Mod base(x);
        while (exp)
        {
            if (exp & 1)
            {
                res = res * base;
            }
            base = base * base;
            exp >>= 1;
        }
        return res;
    }
};

const Mod ONE(1);

Mod geometric_sum(Mod x, int n)
{
    if (n == 0)
    {
        return ONE;
    }

    if (n == 1)
    {
        return x + ONE;
    }

    if (n & 1)
    {
        return geometric_sum(x, n / 2) * (ONE + (x ^ (1 + n / 2)));
    }
    else
    {
        return geometric_sum(x, n - 1) + (x ^ n);
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    Mod a, b, x_0;
    int n;
    cin >> a.x >> b.x >> x_0.x >> n >> m;

    cout << ((a ^ n) * x_0 + geometric_sum(a, n - 1) * b).x << "\n";
}
