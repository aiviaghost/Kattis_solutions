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

struct Tree {
    typedef int T;
    static constexpr T unit = 0;
    inline T f(T a, T b) { return a + b; } // (any associative fn)
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(n << 1, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos >>= 1;)
            s[pos] = f(s[pos << 1], s[(pos << 1) + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b >>= 1, e >>= 1) {
            if (b & 1) ra = f(ra, s[b++]);
            if (e & 1) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> counts(n);

    vector<int> inds(n);
    iota(all(inds), 0);
    
    {
        Tree st(n);
        sort(all(inds), [&](int i, int j) {
            return nums[i] < nums[j] || (nums[i] == nums[j] && i < j);
        });
        for (int i : inds) {
            counts[i] = st.query(i, n);
            st.update(i, 1);
        }
    }
    {
        Tree st(n);
        sort(all(inds), [&](int i, int j) {
            return nums[i] > nums[j] || (nums[i] == nums[j] && i > j);
        });
        for (int i : inds) {
            counts[i] *= st.query(0, i);
            st.update(i, 1);
        }
    }

    int ans = 0;
    for (int i : counts) {
        ans += i;
    }

    cout << ans << "\n";
}
