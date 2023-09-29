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
    T f(T a, T b) { return a + b; } // (any associative fn)
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int m, r;
        cin >> m >> r;

        Tree st(r + m);
        vector<int> lookup(m);
        for (int i = 0; i < m; i++) {
            lookup[i] = r + i;
            st.update(lookup[i], 1);
        }

        int leftmost_available = r - 1;
        for (int i = 0; i < r; i++) {
            int q;
            cin >> q, q--;
            cout << st.query(0, lookup[q]) << " ";
            st.update(lookup[q], 0);
            lookup[q] = leftmost_available;
            leftmost_available--;
            st.update(lookup[q], 1);
        }

        cout << "\n";
    }
}
