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
    int n;
    vector<H> ha, pw;
    Poly_Hash(string& str, H C = 1e11 + 3) : ha(str.size() + 1), pw(ha) {
        n = str.size();
        pw[0] = 1;
        for (int i = 0; i < n; i++) {
            ha[i+1] = ha[i] * C + str[i],
            pw[i+1] = pw[i] * C;
        }
    }

    H hash(int a, int b) {
        return ha[b] - ha[a] * pw[b - a];
    }

    unordered_set<ull> hashes(int len) {
        unordered_set<ull> seen;
        for (int i = 0; i + len <= n; i++) {
            seen.emplace(hash(i, i + len).get());
        }
        return seen;
    }
};

unordered_set<ull> intersection(unordered_set<ull> & s1, unordered_set<ull> & s2) {
    unordered_set<ull> res, chosen = s1.size() < s2.size() ? s1 : s2, other = s1.size() >= s2.size() ? s1 : s2;
    for (ull i : chosen) {
        if (other.count(i)) {
            res.emplace(i);
        }
    }
    return res;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    cin.ignore();
    vector<Poly_Hash> phs;
    int smallest = INF;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        smallest = min((int) s.length(), smallest);
        phs.push_back(Poly_Hash(s));
    }
    int ans = 0;
    int lb = 0, rb = smallest + 1;
    while (lb < rb) {
        int mid = (lb + rb + 1) / 2;
        unordered_set<ull> seen = phs[0].hashes(mid);
        for (int i = 1; i < n; i++) {
            unordered_set<ull> se = phs[i].hashes(mid);
            seen = intersection(se, seen);
        }
        if (!seen.empty()) {
            ans = max(mid, ans);
            lb = mid;
        }
        else {
            rb = mid - 1;
        }
    }
    cout << ans << "\n";
}
