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

vector<int> divisors(int n) {
    vector<int> small, large;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            small.push_back(i);
            large.push_back(n / i);
        }
    }
    reverse(all(large));
    small.insert(small.end(), all(large));
    small.push_back(n);
    return small;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    while (cin >> n && n != 0) {
        n -= 3;
        if (n == 0) {
            cout << "4\n";
            continue;
        }
        else if (n < 4) {
            cout << "No such base\n";
            continue;
        }
        auto divs = divisors(n);
        for (int d : divs) {
            if (d >= 4) {
                cout << d << "\n";
                break;
            }
        }
    }
}
