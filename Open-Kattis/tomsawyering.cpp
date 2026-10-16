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

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<pii> nums(n);
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        nums[i] = {h, i};
    }

    sort(all(nums));
    reverse(all(nums));

    int ans = 0;
    int leftmost = INF;
    int rightmost = -INF;
    for (auto [h, x] : nums)
    {
        if (x < rightmost)
        {
            ans = max(ans, h * (rightmost - x));
        }

        if (x > leftmost)
        {
            ans = max(ans, h * (x - leftmost));
        }

        leftmost = min(leftmost, x);
        rightmost = max(rightmost, x);
    }

    cout << ans << "\n";
}