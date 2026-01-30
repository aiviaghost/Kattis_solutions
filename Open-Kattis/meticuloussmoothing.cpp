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

int get_int()
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

int solve_seq(const vector<int> &hs)
{
    int n = hs.size();
    vector<int> valid_heights(n, INF);
    valid_heights[0] = hs[0];

    for (int i = 1; i < n; i++)
    {
        valid_heights[i] = min(hs[i], valid_heights[i - 1] + 1);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        valid_heights[i] = min(valid_heights[i], valid_heights[i + 1] + 1);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += hs[i] - valid_heights[i];
    }

    return ans;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n = get_int();
    vector<int> hs(n);
    for (auto &&h : hs)
    {
        h = get_int();
    }

    int min_index = 0;
    for (int i = 1; i < n; i++)
    {
        if (hs[i] < hs[min_index])
        {
            min_index = i;
        }
    }

    auto seq_1 = vector<int>(hs.begin() + min_index, hs.end());

    auto seq_2 = vector<int>{hs[min_index]};
    seq_2.insert(seq_2.end(), hs.begin(), hs.begin() + min_index);
    reverse(seq_2.begin() + 1, seq_2.end());

    int ans = solve_seq(seq_1) + solve_seq(seq_2);

    cout << ans << "\n";
}
