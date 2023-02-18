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

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    int s, k;
    cin >> n >> s >> k;
    vector<int> xs(n);
    for (int i = 0; i < n; i++) {
        cin >> xs[i];
    }

    sort(all(xs));

    for (int i = 0; i < n - 1; i++) {
        if (xs[i + 1] - xs[i] < s) {
            cout << "-1\n";
            return 0;
        }
    }

    vector<int> choices(n, - 1);
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        int choice = min(k, min(i > 0 ? 2 * (xs[i] - xs[i - 1]) - s : INF, i < n - 1 ? 2 * (xs[i + 1] - xs[i]) - s : INF));

        if (i > 0 && choices[i - 1] != -1) {
            choice = min(choice, 2 * (xs[i] - xs[i - 1]) - choices[i - 1]);
        }

        if (i < n - 1 && choices[i + 1] != -1) {
            choice = min(choice, 2 * (xs[i + 1] - xs[i]) - choices[i + 1]);
        }

        tot += choice;
        choices[i] = choice;
    }

    cout << tot << "\n";
}
