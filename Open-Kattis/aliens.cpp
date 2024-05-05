#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// #define unordered_map gp_hash_table

#define int ll
#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
#define size(x) (ll)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)

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

typedef uint64_t ull;
struct H {
    ull x; H(ull x = 0) : x(x) {}
    H operator+(H o) { return x + o.x + (x + o.x < x); }
    H operator-(H o) { return *this + ~o.x; }
    H operator*(H o) {
        auto m = (__uint128_t)x * o.x;
        return H((ull)m) + (ull)(m >> 64);
    }
    ull get() const { return x + !~x; }
    bool operator==(H o) const { return get() == o.get(); }
    bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11 + 3; // (order ~ 3e9; random also ok)

struct HashInterval {
    vector<H> ha, pw;
    HashInterval(string& str) : ha(size(str) + 1), pw(ha) {
        pw[0] = 1;
        rep(i, 0, size(str))
            ha[i + 1] = ha[i] * C + str[i],
            pw[i + 1] = pw[i] * C;
    }
    H hashInterval(int a, int b) { // hash [a, b)
        return ha[b] - ha[a] * pw[b - a];
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int m;
    while (cin >> m && m) {
        string s;
        cin >> s;
        HashInterval string_hasher(s);

        auto works = [&](int k) -> pair<bool, int> {
            unordered_map<int, int> counts;
            bool ok = false;
            int start_index = 0;
            for (int i = 0; i < size(s) - k + 1; i++) {
                auto h = string_hasher.hashInterval(i, i + k).get();
                counts[h]++;
                if (counts[h] >= m) {
                    ok = true;
                    start_index = i;
                }
            }
            return { ok, start_index };
            };

        int lo = 1, hi = size(s);
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            auto [ok, _] = works(mid);
            if (ok) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        auto [ok, start_index] = works(lo);
        if (ok) {
            cout << lo << " " << start_index << "\n";
        }
        else {
            cout << "none" << "\n";
        }
    }
}
