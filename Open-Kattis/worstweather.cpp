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

struct Tree {
    typedef int T;
    static constexpr T unit = -INF;
    inline T f(T a, T b) { return max(a, b); } // (any associative fn)
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
    while (cin >> n && n) {
        unordered_map<int, int> remap;
        vector<int> years;
        unordered_map<int, int> year_to_rain;
        for (int i = 0; i < n; i++) {
            int y, r;
            cin >> y >> r;
            remap[y] = size(remap);
            years.push_back(y);
            year_to_rain[y] = r;
        }

        Tree st(size(remap));
        for (auto [y, r] : year_to_rain) {
            st.update(remap[y], r);
        }

        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int y, x;
            cin >> y >> x;

            int years_between = x - y - 1;
            bool y_exists = in(remap, y), x_exists = in(remap, x);

            if (!y_exists) {
                y = *lower_bound(all(years), y);
            }

            if (!x_exists) {
                x = *(--lower_bound(all(years), x));
            }

            int years_between_remap = remap[x] - remap[y] - 1;
            int middle_max = years_between_remap > 0 ? st.query(remap[y] + y_exists, remap[x] + !x_exists) : 0;

            if (y_exists && year_to_rain[y] <= middle_max) {
                cout << "false\n";
                continue;
            }

            if (x_exists && year_to_rain[x] <= middle_max) {
                cout << "false\n";
                continue;
            }

            if (x_exists && y_exists && year_to_rain[y] < year_to_rain[x]) {
                cout << "false\n";
                continue;
            }

            if (years_between == years_between_remap && y_exists && x_exists && middle_max < year_to_rain[x] && year_to_rain[x] <= year_to_rain[y]) {
                cout << "true\n";
                continue;
            }

            cout << "maybe\n";
        }
    }
}
