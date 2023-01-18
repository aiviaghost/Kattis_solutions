#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define unordered_map gp_hash_table

#define int ll
#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
#define size(x) (ll)(x).size()

const int INF = 2e9;
const int MOD = 1e9 + 7;

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> inds(n);
    iota(all(inds), 0);
    sort(all(inds), [&](int i, int j) {
        return nums[i] < nums[j];
    });

    vector<pii> adj;
    for (int i = 0; i < n; i++) {
        adj.push_back({i - 1, i + 1});
    }

    ll ans = 0;
    vector<bool> valid(n, true);
    for (int j = 0; j < n - 1; j++) {
        int i = inds[j];
        if (valid[i]) {
            int left = adj[i].first >= 0 ? nums[adj[i].first] : INF;
            int right = adj[i].second < n ? nums[adj[i].second] : INF;
            valid[i] = false;
            if (left < right) {
                ans += left;
                adj[adj[i].first].second = adj[i].second;
                if (adj[i].second < n) {
                    adj[adj[i].second].first = adj[i].first;
                }
            }
            else {
                ans += right;
                adj[adj[i].second].first = adj[i].first;
                if (adj[i].first >= 0) {
                    adj[adj[i].first].second = adj[i].second;
                }
            }
        }
    }

    cout << ans << "\n";
}
