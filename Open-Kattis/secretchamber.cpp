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

const int INF = 1e9;
const int MOD = 1e9 + 7;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int m, n;
    cin >> m >> n;
    auto dist = make<int>(INF, 26, 26);
    for (int i = 0; i < m; i++) {
        char a, b;
        cin >> a >> b;
        dist[a - 'a'][b - 'a'] = 1;
    }
    
    for (int i = 0; i < 26; i++) {
        dist[i][i] = 0;
    }
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        bool yes = a.length() == b.length();
        if (yes) {
            for (int j = 0; j < a.length(); j++) {
                yes &= dist[a[j] - 'a'][b[j] - 'a'] != INF;
            }
        }
        cout << (yes ? "yes" : "no") << "\n";
    }
}
