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

    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (k == 1 && n > 1)
    {
        cout << -1 << "\n";
        return 0;
    }

    if (k == 1 && n == 1)
    {
        cout << 1 << "\n";
        return 0;
    }

    // dp[u][c] = min obtainable value for node u when not allowed to be color c
    auto dp = make(INF, n, k);
    auto solve = [&](auto &&solve, int curr, int disallowed_color, int parent) -> int
    {
        if (dp[curr][disallowed_color] < INF)
        {
            return dp[curr][disallowed_color];
        }

        vector<int> color_answers(k);
        for (int c = 0; c < k; c++)
        {
            int local_ans = c;
            for (int child : adj[curr])
            {
                if (child != parent)
                {
                    local_ans += solve(solve, child, c, curr);
                }
            }
            color_answers[c] = local_ans;
        }

        int min_color = 0;
        for (int c = 0; c < k; c++)
        {
            if (color_answers[c] < color_answers[min_color])
            {
                min_color = c;
            }
        }

        int second_min = min_color == 0 ? 1 : 0;
        for (int c = 0; c < k; c++)
        {
            if (c != min_color && color_answers[c] < color_answers[second_min])
            {
                second_min = c;
            }
        }

        for (int temp_disallowed_color = 0; temp_disallowed_color < k; temp_disallowed_color++)
        {
            dp[curr][temp_disallowed_color] = temp_disallowed_color == min_color ? color_answers[second_min] : color_answers[min_color];
        }

        return dp[curr][disallowed_color];
    };

    int ans = INF;
    for (int c = 0; c < k; c++)
    {
        ans = min(ans, solve(solve, 0, c, 0));
    }

    cout << n + ans << "\n";
}
