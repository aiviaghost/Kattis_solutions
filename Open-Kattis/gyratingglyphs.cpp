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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    const int MAX_WIDTH = 15;
    const int POWERS[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768};

    auto get_random_query = []() -> int {
        return uniform_int_distribution<int>(1, MOD - 1)(rng);
    };

    int n;
    cin >> n;

    vector<int> ans(n);

    bool found = false;
    vector<int> valid(MAX_WIDTH);
    vector<int> query(n + 1);
    auto solve_segment = [&](int start_index, int width) -> void {
        while (1) {
            if (found) {
                for (int i = 0; i < width; i++) {
                    query[start_index + 1 + i] = valid[i];
                }
            }
            else {
                for (int i = 0; i < width; i++) {
                    valid[i] = query[start_index + 1 + i] = get_random_query();
                }
            }

            cout << "?";
            for (int a : query) {
                cout << " " << a;
            }
            cout << endl;

            int target;
            cin >> target;

            unordered_map<int, int> seen;
            auto brute = [&](auto&& brute, int curr, int mask, int index) -> void {
                if (index == width) {
                    seen[curr] = mask;
                    return;
                }
                brute(brute, (curr + valid[index]) % MOD, mask, index + 1);
                brute(brute, (curr * valid[index]) % MOD, mask | POWERS[index], index + 1);                
            };

            brute(brute, 0, 0, 0);

            if (size(seen) == POWERS[width]) {
                int mask = seen[target];
                for (int i = 0; i < width; i++) {
                    query[start_index + 1 + i] = ans[start_index + i] = (mask >> i) & 1;
                }
                found = true;
                break;
            }
            found = false;
        }
    };

    int width = min(MAX_WIDTH, n);
    int start_index = n - width;
    while (1) {
        solve_segment(start_index, width);
        width = min(MAX_WIDTH, start_index);
        if (width == 0) {
            break;
        }
        start_index -= width;
    }

    cout << "! ";
    for (int i : ans) {
        cout << (i ? "x" : "+");
    }
    cout << endl;
}
