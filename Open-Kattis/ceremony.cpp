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

    int n;
    cin >> n;
    priority_queue<int> hq;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        hq.push(h);
    }
    int ans = min(n, hq.top());
    for (int i = 1; i <= n; i++) {
        hq.pop();
        ans = min(hq.top() + i, ans);
    }
    cout << ans << "\n";
}
