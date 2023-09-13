#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// #define unordered_map gp_hash_table

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

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int d, U;
    cin >> d >> U;

    priority_queue<int, vector<int>, greater<int>> smallest_available;
    for (int i = 1; i <= U; i++) {
        smallest_available.push(i);
    }

    deque<pii> delays;

    int time = 0;

    for (int i = 0; i < U; i++) {
        if (!delays.empty() && delays.front().first == time) {
            smallest_available.push(delays.front().second);
            delays.pop_front();
        }        

        char op;
        cin >> op;
        if (op == 'a') {
            int ans = smallest_available.top();
            smallest_available.pop();
            cout << ans << "\n";
        }
        else {
            int r;
            cin >> r;
            delays.push_back({time + d, r});
        }

        time++;
    }
}
