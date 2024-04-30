#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// #define unordered_map gp_hash_table

#define int ll
#define all(xs) xs.begin(), xs.end()
// #define in(xs, a) (xs.find(a) != xs.end())
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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
    int n = size(a), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1);  // (^ 10% faster if double)
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n); rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        rep(i, k, 2 * k) rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
    }
    vi rev(n);
    rep(i, 0, n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i, 0, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k) rep(j, 0, k) {
            // C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
            auto x = (double*)&rt[j + k], y = (double*)&a[i + j + k];        /// exclude-line
            C z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);           /// exclude-line
            a[i + j + k] = a[i + j] - z;
            a[i + j] += z;
        }
}
vd conv(const vd& a, const vd& b) {
    if (a.empty() || b.empty()) return {};
    vd res(size(a) + size(b) - 1);
    int L = 32 - __builtin_clz(size(res)), n = 1 << L;
    vector<C> in(n), out(n);
    copy(all(a), begin(in));
    rep(i, 0, size(b)) in[i].imag(b[i]);
    fft(in);
    for (C& x : in) x *= x;
    rep(i, 0, n) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    rep(i, 0, size(res)) res[i] = imag(out[i]) / (4 * n);
    return res;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<double> squares(n);
    for (int a = 1; a < n; a++) {
        squares[a * a % n]++;
    }

    auto squared = conv(squares, squares);
    vector<int> res(size(squared));
    for (int i = 0; i < size(res); i++) {
        res[i % n] += lround(squared[i]);
    }

    for (int a = 1; a < n; a++) {
        res[2 * a * a % n]--;
    }
    for (int i = 0; i < size(res); i++) {
        res[i] /= 2;
    }
    for (int a = 1; a < n; a++) {
        res[2 * a * a % n]++;
    }

    int ans = 0;
    for (int c = 1; c < n; c++) {
        ans += res[c * c % n];
    }
    cout << ans << "\n";
}
