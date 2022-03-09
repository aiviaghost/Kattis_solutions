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

#define sz(x) x.size()
typedef complex<double> C;
typedef vector<double> vd;

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); i++)
#define repd(i, a, b) for(int i = a - 1; i >= b; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define last(x) x[x.size() - 1]
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<pii> > vvpii;
typedef priority_queue<pii, vector<pii>, greater<pii> > pq;

const int INF = 2e9;
const int MOD = 1e9 + 7;

void fft(vector<C>& a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1);  // (^ 10% faster if double)
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n); rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
    }
    vi rev(n);
    rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
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
    int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
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

auto main() -> int {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	vector<int> shot_dists(n);
	int ma = 0;
	for (int i = 0; i < n; i++) {
		cin >> shot_dists[i];
		ma = max(ma, shot_dists[i]);
	}
	int m;
	cin >> m;
	vector<int> holes(m);
	for (int i = 0; i < m; i++) {
		cin >> holes[i];
	}
	vd P(ma + 1);
	for (int i : shot_dists) {
		P[i] += 1;
	}
	vd res = conv(P, P);
	unordered_set<int> possible;
	for (int i = 0; i < res.size(); i++) {
		if (lround(res[i]) != 0) {
			possible.emplace(i);
		}
	}
	for (int i : shot_dists) {
		possible.emplace(i);
	}
	int ans = 0;
	for (int i : holes) {
		if (possible.count(i)) {
			ans++;
		}
	}
	cout << ans << "\n";
}
