#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
	auto inner = make<T>(init, sizes...);
	return vector<decltype(inner)>(first, inner);
}

const int INF = 2e9;
const int MOD = 1e9 + 7;

struct Tree {
	typedef ll T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(ll n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(ll b, ll e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

auto main() -> int {
	cin.tie(0)->sync_with_stdio(0);

	ll n, c;
	cin >> n >> c;
	vector<ll> x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	vector<ll> pos(n), neg(n);
	for (ll i = 0; i < n; i++) {
		pos[i] = x[i] + c * (i + 1);
		neg[i] = -x[i] + c * (i + 1);
	}

	Tree *tree_pos = new Tree(n);
	for (int i = 0; i < n; i++) {
		tree_pos->update(i, pos[i]);
	}
	Tree *tree_neg = new Tree(n);
	for (int i = 0; i < n; i++) {
		tree_neg->update(i, neg[i]);
	}

	vector<ll> ans(n);
	for (ll i = 1; i < n; i++) {
		ans[i] = max(x[i] - c * (i + 1) + tree_neg->query(0, i + 1), 
					 -x[i] - c * (i + 1) + tree_pos->query(0, i + 1));
	}

	cout << ans.front();
	for (int i = 1; i < n; i++) {
		cout << " " << ans[i];
	}
	cout << "\n";
}
