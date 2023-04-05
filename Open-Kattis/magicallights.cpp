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

using u128 = __uint128_t;

vector<vector<int>> adj;
vector<int> first, last;
vector<u128> color, values;

void compute_euler(int curr, int from) {
    first[curr] = size(values);
    values.push_back(color[curr]);
    for (int next : adj[curr]) {
        if (next != from) {
            compute_euler(next, curr);
        }
    }
    last[curr] = size(values) - 1;
}

struct Tree {
	typedef u128 T;
	static constexpr T unit = 0;
	inline T f(T a, T b) { return a ^ b; } // (any associative fn)
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

int get_int() {
    int r = 0, c = getchar();
    while (c < '0' || '9' < c) c = getchar();
    while ('0' <= c && c <= '9') r = r * 10 + c - '0', c = getchar();
    return r;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n = get_int(), q = get_int();

    color.resize(n);
    for (int i = 0; i < n; i++) {
        int c = get_int();
        color[i] = (u128)1 << c;
    }

    adj.resize(n);
    for (int u = 1; u < n; u++) {
        int v = get_int() - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    first.resize(n);
    last.resize(n);
    compute_euler(0, INF);

    Tree st(size(values));
    for (int i = 0; i < size(values); i++) {
        st.update(i, values[i]);
    }

    while (q--) {
        int k = get_int(), x = get_int() - 1;
        if (k == 0) {
            u128 state = st.query(first[x], last[x] + 1);
            cout << __builtin_popcountll(state >> 64) + __builtin_popcountll(state) << "\n";
        }
        else {
            st.update(first[x], (u128)1 << k);
        }
    }
}
