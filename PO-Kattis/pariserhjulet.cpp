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


inline int read_int() {
    int r = 0, c = getchar_unlocked();
    while (c < '0' || '9' < c) c = getchar_unlocked();
    while ('0' <= c && c <= '9') r = r * 10 + c - '0', c = getchar_unlocked();
    return r;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n = read_int(), m = read_int();
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> waiting;
    for (int i = 0; i < n; i++) {
        int t = read_int();
        if (i < m) {
            pq.push(t * m + i);
        }
        else {
            waiting.push_back(t * m);
        }
    }

    int ans = 0, prev = 0, i = 0;
    while (!pq.empty()) {
        int earliest = pq.top();
        pq.pop();
        ans += earliest - prev;
        if (i < n - m) {
            pq.push(waiting[i] + earliest);
            i++;
        }
        prev = earliest;
    }

    cout << ans << "\n";
}
