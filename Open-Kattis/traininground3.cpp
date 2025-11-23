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

ll euclid(ll a, ll b, ll &x, ll &y)
{
    if (!b)
        return x = 1, y = 0, a;
    ll d = euclid(b, a % b, y, x);
    return y -= a / b * x, d;
}

const ll mod = 998244353;
struct Mod
{
    ll x;
    Mod() : x(0) {}
    Mod(ll xx) : x(xx) {}
    Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
    Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
    Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
    Mod operator/(Mod b) { return *this * invert(b); }
    Mod invert(Mod a)
    {
        ll x, y, g = euclid(a.x, mod, x, y);
        assert(g == 1);
        return Mod((x + mod) % mod);
    }
    Mod operator^(ll e)
    {
        if (!e)
            return Mod(1);
        Mod r = *this ^ (e / 2);
        r = r * r;
        return e & 1 ? *this * r : r;
    }
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, K, P;
    cin >> N >> K >> P;

    if (N < K * P)
    {
        cout << "1\n";
        return 0;
    }

    vector<Mod> factorials(N + 1);
    factorials[0] = Mod(1);
    for (int i = 1; i <= N; i++)
    {
        factorials[i] = factorials[i - 1] * Mod(i);
    }
    vector<Mod> inverse_factorials(N + 1);
    inverse_factorials[N] = Mod(1) / factorials[N];
    for (int i = N; i > 0; i--)
    {
        inverse_factorials[i - 1] = inverse_factorials[i] * Mod(i);
    }

    auto n_choose_k = [&](int n, int k)
    {
        return factorials[n] * inverse_factorials[k] * inverse_factorials[n - k];
    };

    Mod res(1);
    for (int i = 0; i < K; i++)
    {
        res = res * n_choose_k(N - i * P, P);
    }

    Mod all_ways = n_choose_k(N, P) ^ K;

    Mod ans = Mod(1) - (res / all_ways);

    cout << ans.x << "\n";
}
