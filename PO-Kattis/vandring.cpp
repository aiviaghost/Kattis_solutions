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

    int R;
    cin >> R;
    unordered_map<int, set<int>> lookup;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < R; j++) {
            int x;
            cin >> x;
            if (in(lookup, x)) {
                auto it = lookup[x].upper_bound(j);
                if (it != lookup[x].begin()) {
                    cout << "0\n";
                    return 0;
                }
            }
            lookup[x].insert(j);
        }
    }
    cout << "1\n";
}
