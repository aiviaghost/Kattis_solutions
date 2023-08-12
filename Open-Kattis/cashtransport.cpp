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

inline int get_int() {
    int r = 0;
    char c = getchar_unlocked();
    while (c < '0' || '9' < c) {
        c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9') {
        r = 10 * r + c - '0';
        c = getchar_unlocked();
    }
    return r;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n = get_int(), m = get_int(), k = get_int();
    vector<vector<int>> waiting(n);
    vector<int> banks(n);
    for (int i = 0; i < n; i++) {
        banks[i] = get_int();
    }
    for (int i = 0; i < m; i++) {
        int a = get_int(), b = get_int();
        int tot = 0;
        while (!waiting[a].empty()) {
            tot += waiting[a].back();
            waiting[a].pop_back();
        }
        tot += banks[a];
        banks[a] = 0;
        waiting[b].push_back(tot);
    }
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        for (int w : waiting[i]) {
            pq.push(w);
        }
    }
    int ans = 0;
    for (int i = 0; i < k && !pq.empty(); i++) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << "\n";
}
