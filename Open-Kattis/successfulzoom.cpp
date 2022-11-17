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

#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
#define size(x) (ll)(x).size()

const int INF = 2e9;
const int MOD = 1e9 + 7;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> xs(n);
    for (int i = 0; i < n; i++) {
        cin >> xs[i];
    }
    int step = 1;
    while (step < n) {
        int curr = step - 1;
        if (curr + step >= n) {
            break;
        }
        bool valid = true;
        while (curr + step < n) {
            int next = curr + step;
            if (xs[curr] >= xs[next]) {
                valid = false;
                break;
            }
            curr += step;
        }
        if (valid) {
            cout << step << "\n";
            return 0;
        }
        step++;
    }
    cout << "ABORT!\n";
}
