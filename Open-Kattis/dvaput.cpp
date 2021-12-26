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

const int INF = 2e9;
const int MOD = 1e9 + 7;

typedef uint64_t ull;
struct H {
	ull x; H(ull x=0) : x(x) {}
#define OP(O,A,B) H operator O(H o) { ull r = x; asm \
	(A "addq %%rdx, %0\n adcq $0,%0" : "+a"(r) : B); return r; }
	OP(+,,"d"(o.x)) OP(*,"mul %1\n", "r"(o.x) : "rdx")
	H operator-(H o) { return *this + ~o.x; }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};

struct Poly_Hash {
	vector<H> ha, pw;
	Poly_Hash(string& str, H C) : ha(str.size() + 1), pw(ha) {
		pw[0] = 1;
		for (int i = 0; i < str.size(); i++) {
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
		}
	}

	H hash(int a, int b) {
		return ha[b] - ha[a] * pw[b - a];
	}
};

auto main() -> int {
	cin.tie(0)->sync_with_stdio(0);

	int L;
	cin >> L;
	cin.ignore();
	string s;
	cin >> s;

	Poly_Hash ph1(s, 2515871711);

	auto exists = [&](int len) {
		unordered_set<ull> s1;
		for (int i = 0; i < s.length() - len; i++) {
			ull H1 = ph1.hash(i, i + len).get();
			if (s1.count(H1)) {
				return true;
			}
			s1.emplace(H1);
		}
		return false;
	};

	int lb = 0, rb = L, mid;
	while (rb - lb > 0) {
		int mid = (lb + rb + 1) / 2;
		if (exists(mid)) {
			lb = mid;
		}
		else {
			rb = mid - 1;
		}
	}
	cout << lb << "\n";
}
