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

inline int get_int()
{
    int r = 0;
    char c = getchar_unlocked();
    while (c < '0' || '9' < c)
    {
        c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9')
    {
        r = 10 * r + c - '0';
        c = getchar_unlocked();
    }
    return r;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n = get_int();
    int ans = 1;
    int prev = 0;
    while (n--)
    {
        int x = get_int();
        ans += (x > prev) * (x - prev + 1);
        prev = x;
    }
    cout << ans << flush;
    _Exit(0);
}
