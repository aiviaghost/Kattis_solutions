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

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<pii> rs(n);
    for (int i = 0; i < n; i++) {
        int a, s;
        cin >> a >> s;
        rs[i] = {a, s};
    }
    sort(rs.begin(), rs.end());
    priority_queue<pii, vector<pii>, greater<pii>> machines;
    int unlocks = 0;
    for (auto [a, s] : rs) {
        bool already_unlocked = false;
        while (!machines.empty()) {
            auto [start, stop] = machines.top();
            if (start > a) {
                break;
            }
            if (start <= a && a <= stop) {
                machines.pop();
                machines.push({a + s, a + s + m});
                already_unlocked = true;
                break;
            }
            machines.pop();
        }
        if (!already_unlocked) {
            machines.push({a + s, a + s + m});
            unlocks++;
        }
    }
    cout << n - unlocks << "\n";
}
