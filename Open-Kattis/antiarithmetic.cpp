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
    int n;
    while (scanf("%d:", &n) && n) {
        vector<int> nums(n), where(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            where[nums[i]] = i;
        }
        bool is_antiarithmetic = true;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff = nums[j] - nums[i];
                if (0 <= nums[i] - diff && nums[i] - diff < n && where[nums[i] - diff] < i) {
                    is_antiarithmetic = false;
                    i = j = n;
                }
            }
        }
        printf(is_antiarithmetic ? "yes\n" : "no\n");
    }
}
