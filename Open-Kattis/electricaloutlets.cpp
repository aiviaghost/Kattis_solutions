#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

const int INF = 2e9;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin >> N;
    while (N--) {
        int K;
        cin >> K;
        int ans = 0;
        for (int i = 0; i < K; i++) {
            int O;
            cin >> O;
            ans += O - 1;
        }
        cout << ans + 1 << "\n";
    }
}
