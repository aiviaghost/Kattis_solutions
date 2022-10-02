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

#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())

const int INF = 2e9;
const int MOD = 1e9 + 7;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define unordered_map gp_hash_table

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<int> gnomes(m), seen(n);
    for (int i = 0; i < m; i++) {
        cin >> gnomes[i];
        seen[gnomes[i] - 1] = 1;
    }
    vector<int> missing;
    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            missing.push_back(i + 1);
        }
    }
    reverse(all(missing));
    reverse(all(gnomes));
    while (1) {
        if (!missing.empty() && !gnomes.empty()) {
            if (missing.back() < gnomes.back()) {
                cout << missing.back() << "\n";
                missing.pop_back();
            }
            else {
                cout << gnomes.back() << "\n";
                gnomes.pop_back();
            }
        }
        else if (!missing.empty()) {
            cout << missing.back() << "\n";
            missing.pop_back();
        }
        else if (!gnomes.empty()) {
            cout << gnomes.back() << "\n";
            gnomes.pop_back();
        }
        else {
            break;
        }
    }
}
