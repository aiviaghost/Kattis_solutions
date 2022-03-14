#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

#define all(x) x.begin(), x.end()

const ll INF = 2e9;
const ll MOD = 1e9 + 7;

#define rep(i, a, b) for (ll i = a; i < b; i++)
#define sz(x) x.size()

typedef complex<double> C;
typedef vector<double> vd;
typedef vector<ll> vi;
void fft(vector<C>& a) {
    ll n = sz(a), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1);  // (^ 10% faster if double)
    for (static ll k = 2; k < n; k *= 2) {
        R.resize(n); rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
    }
    vi rev(n);
    rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (ll k = 1; k < n; k *= 2)
        for (ll i = 0; i < n; i += 2 * k) rep(j,0,k) {
            // C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
            auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
            C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
            a[i + j + k] = a[i + j] - z;
            a[i + j] += z;
        }
}
vd conv(const vd& a, const vd& b) {
    if (a.empty() || b.empty()) return {};
    vd res(sz(a) + sz(b) - 1);
    ll L = 32 - __builtin_clz(sz(res)), n = 1 << L;
    vector<C> in(n), out(n);
    copy(all(a), begin(in));
    rep(i,0,sz(b)) in[i].imag(b[i]);
    fft(in);
    for (C& x : in) x *= x;
    rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
    return res;
}

const ll shift = 50000;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;
    vector<ll> in(n);
    unordered_set<ll> ins;
    ll ma = -INF, zeros = 0;
    unordered_map<ll, ll> in_c;
    for (ll i = 0; i < n; i++) {
        cin >> in[i];
        ins.emplace(in[i]);
        ma = max(ma, abs(in[i]));
        if (in[i] == 0) {
            zeros++;
        }
        in_c[in[i]]++;
    }

    vector<double> P1(ma + shift + 1);
    for (ll i : in) {
        if (i != 0) {
            P1[i + shift] += 1;
        }
    }
    vd squared = conv(P1, P1);
    vector<ll> pos(2 * ma + 1), neg(2 * ma + 1);
    for (ll i = 0; i < squared.size(); i++) {
        ll rounded = lround(squared[i]);
        if (rounded != 0) {
            if (i - 2 * shift > 0) {
                pos[i - 2 * shift] = rounded;
            }
            else if (i - 2 * shift == 0) {
                neg[0] = rounded;
            }
            else if (i - 2 * shift < 0) {
                neg[abs(i - 2 * shift)] = rounded;
            }
        }
    }

    for (ll i : in) {
        if (i > 0) {
            pos[2 * i]--;
        }
        else if (i < 0) {
            neg[abs(2 * i)]--;
        }
    }
    
    if (n <= 2) {
        cout << "0\n";
        exit(0);
    }
    
    ll ans = 0;
    for (ll i = 1; i < pos.size(); i++) {
        if (pos[i] > 0 && ins.count(i)) {
            ans += pos[i] * in_c[i];
        }
        if (neg[i] > 0 && ins.count(-i)) {
            ans += neg[i] * in_c[-i];
        }
    }

    ans += neg[0] * zeros;

    if (zeros > 0) {
        for (auto [i, _] : in_c) {
            if (i != 0) {
                ans += 2 * zeros * in_c[i] * (in_c[i] - 1);
            }
        }
    }

    if (zeros >= 3) {
        ans += zeros * (zeros - 1) * (zeros - 2);
    }
    
    cout << ans << "\n";
}

