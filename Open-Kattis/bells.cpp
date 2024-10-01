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

    int n;
    cin >> n;

    vector<vector<int>> current = {{1}}, next;
    auto solve = [&](auto&& solve, int n) -> void {
        if (n == 1) {
            return;
        }

        solve(solve, n - 1);

        int skip = 0;
        bool forward = true;
        for (auto perm : current) {
            for (int i = 0; i < n; i++) {
                if (forward) {
                    vector<int> next_perm;
                    if (skip == -1) {
                        skip++;
                    }
                    for (int j = 0; j < sz(perm); j++) {
                        if (j == skip) {
                            next_perm.push_back(n);
                        }
                        next_perm.push_back(perm[j]);
                    }
                    if (skip == n - 1) {
                        next_perm.push_back(n);
                    }
                    next.push_back(next_perm);
                    skip++;
                }
                else {
                    vector<int> next_perm;
                    if (skip == 0) {
                        next_perm.push_back(n);
                    }
                    for (int j = 1; j <= sz(perm); j++) {
                        next_perm.push_back(perm[j - 1]);
                        if (j == skip) {
                            next_perm.push_back(n);
                        }
                    }
                    if (skip == n) {
                        next_perm.push_back(n);
                        skip--;
                    }
                    next.push_back(next_perm);
                    skip--;
                }
            }
            forward = !forward;
        }

        current = next;
        next.clear();
    };

    solve(solve, n);

    for (auto perm : current) {
        for (int i : perm) {
            cout << n - i + 1 << " ";
        }
        cout << "\n";
    }
}
