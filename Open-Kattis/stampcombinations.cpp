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

#define all(x) x.begin(), x.end()
#define in(x, a) (x.find(a) != x.end())

const int INF = 2e9;
const int MOD = 1e9 + 7;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define unordered_map gp_hash_table

bool works(vector<int> & prefix, vector<int> & postfix, int target) {
    int m = prefix.size() - 1;
    for (int i = m; i >= 0; i--) {
        int post = postfix[i];
        if (post == target) {
            return true;
        }
        int lb = 0, rb = i, mid;
        while (rb - lb > 0) {
            mid = lb + (rb - lb) / 2;
            if (prefix[mid] == target || prefix[mid] + post == target) {
                return true;
            }
            else if (prefix[mid] + post > target) {
                rb = mid;
            }
            else {
                lb = mid + 1;
            }
        }
        if (
            prefix[lb] == target || prefix[mid] == target || prefix[rb] == target || 
            prefix[lb] + post == target || prefix[mid] + post == target || prefix[rb] + post == target
        ) {
            return true;
        }
    }
    return false;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int m, n;
    cin >> m >> n;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    vector<int> prefix(m + 1), postfix(m + 1);
    for (int i = 1; i <= m; i++) {
        prefix[i] = prefix[i - 1] + a[i - 1];
        postfix[m - 1 - i] = postfix[m - i] + a[m - i];
    }
    while (n--) {
        int q;
        cin >> q;
        cout << (works(prefix, postfix, q) ? "Yes" : "No") << "\n";
    }
    exit(0);
}
