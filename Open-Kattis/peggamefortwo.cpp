#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define unordered_map gp_hash_table

#define int ll
#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
#define size(x) (ll)(x).size()

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

const int INF = 2e9;
const int MOD = 1e9 + 7;

const pii dirs[] = {
    {2, 0}, {-2, 0}, {-2, -2}, {0, -2}, {0, 2}, {2, 2}
};
const pii dirs2[] = {
    {1, 0}, {-1, 0}, {-1, -1}, {0, -1}, {0, 1}, {1, 1}
};

const int P = 3397200613, B = 101;

unordered_map<int, int> dp;

int solve(vector<vector<int>>& state, bool player) {
    int hash = 0;
    for (int i = 0; i < size(state); i++) {
        for (int j = 0; j < size(state[i]); j++) {
            hash = (B * hash + state[i][j]) % P;
        }
    }

    if (in(dp, hash)) {
        return dp[hash];
    }

    int ans = player ? -INF : INF;
    int moves = 0;
    for (int row = 0; row < size(state); row++) {
        for (int col = 0; col < size(state[row]); col++) {
            if (state[row][col] != 0) {
                continue;
            }
            for (int i = 0; i < 6; i++) {
                auto [dx, dy] = dirs[i];
                auto [dx2, dy2] = dirs2[i];
                if (0 <= row + dy && row + dy < size(state) && 0 <= col + dx && col + dx < size(state[row + dy]) && state[row + dy2][col + dx2] != 0 && state[row + dy][col + dx] != 0) {
                    moves++;

                    int score = state[row + dy2][col + dx2] * state[row + dy][col + dx];

                    int t1 = state[row][col], t2 = state[row + dy][col + dx], t3 = state[row + dy2][col + dx2];

                    state[row][col] = state[row + dy][col + dx];
                    state[row + dy2][col + dx2] = 0;
                    state[row + dy][col + dx] = 0;

                    int ans2 = solve(state, !player);
                    if (player) {
                        ans = max(ans, score + ans2);
                    }
                    else {
                        ans = min(ans, -score + ans2);
                    }

                    state[row][col] = t1;
                    state[row + dy][col + dx] = t2;
                    state[row + dy2][col + dx2] = t3;
                }
            }
        }
    }

    ans = ans * (moves != 0);

    dp[hash] = ans;

    return ans;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    vector<vector<int>> init_state(5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++) {
            int x;
            cin >> x;
            init_state[i].push_back(x);
        }
    }

    cout << solve(init_state, 1) << "\n";
}
