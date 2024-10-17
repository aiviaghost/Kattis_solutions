#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// #define unordered_map gp_hash_table

#define int ll
#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
#define sz(x) (ll)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vi = vector<int>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

const int INF = 2e9;
const int MOD = 1e9 + 7;

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<int> dists(n);
        int max_h = 0;
        for (int i = 0; i < n; i++) {
            cin >> dists[i];
            max_h += dists[i];
        }
        max_h = max_h / 2 + 1;
        auto dp = make(INF, n + 1, max_h);
        dp[0][0] = 0;
        unordered_set<int> active_heights = {0};
        auto go_to = make(0, n + 1, max_h);
        for (int i = 0; i < n; i++) {
            unordered_set<int> next_heights;
            for (int h : active_heights) {
                int new_h = h + dists[i];
                int new_val = max(dp[i][h], h + dists[i]);
                if (new_h < max_h && new_val < dp[i + 1][new_h]) {
                    go_to[i + 1][new_h] = h;
                    dp[i + 1][new_h] = new_val;
                    next_heights.insert(new_h);
                }

                new_h = h - dists[i];
                new_val = max(dp[i][h], h - dists[i]);
                if (0 <= new_h && new_h < max_h && new_val < dp[i + 1][new_h]) {
                    go_to[i + 1][new_h] = h;
                    dp[i + 1][new_h] = new_val;
                    next_heights.insert(new_h);
                }
            }
            active_heights.swap(next_heights);
        }

        if (dp[n][0] == INF) {
            cout << "IMPOSSIBLE" << "\n";
        }
        else {
            vector<char> ans;
            int curr_h = 0;
            for (int i = n; i >= 1; i--) {
                ans.push_back(go_to[i][curr_h] < curr_h ? 'U' : 'D');
                curr_h = go_to[i][curr_h];
            }
            reverse(all(ans));
            for (char c : ans) {
                cout << c;
            }
            cout << "\n";
        }
    }
}
