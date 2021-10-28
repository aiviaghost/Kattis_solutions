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

const int INF = 2e9;
const int MOD = 1e9 + 7;

ll get_and_reset(unordered_map<int, ll>& inds, int id, int msg_count) {
    ll res = inds.count(id) ? inds[id] : msg_count;
    inds[id] = 0;
    return res;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;
    ll total_unread = 0;
    unordered_map<int, ll> inds;
    for (int i = 0; i < m; i++) {
        int id;
        cin >> id;
        total_unread += n - 1;
        for (auto& j : inds) {
            if (j.first != id) {
                j.second++;
            }
        }
        total_unread -= get_and_reset(inds, id, i);
        cout << total_unread << "\n";
    }
}
