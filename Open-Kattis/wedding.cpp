#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// #define unordered_map gp_hash_table

#define int ll
#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
// #define size(x) (ll)(x).size()

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
#define sz(x) (int)(x).size()
typedef vector<int> vi;

struct TwoSat {
    int N;
    vector<vi> gr;
    vi values; // 0 = false, 1 = true

    TwoSat(int n = 0) : N(n), gr(2 * n) {}

    int addVar() { // (optional)
        gr.emplace_back();
        gr.emplace_back();
        return N++;
    }

    void either(int f, int j) {
        f = max(2 * f, -1 - 2 * f);
        j = max(2 * j, -1 - 2 * j);
        gr[f].push_back(j ^ 1);
        gr[j].push_back(f ^ 1);
    }
    void setValue(int x) { either(x, x); }

    void add_xor(int a, int b) {
        either(a, b);
        either(~a, ~b);
    }

    vi val, comp, z; int time = 0;
    int dfs(int i) {
        int low = val[i] = ++time, x; z.push_back(i);
        for (int e : gr[i]) if (!comp[e])
            low = min(low, val[e] ? : dfs(e));
        if (low == val[i]) do {
            x = z.back(); z.pop_back();
            comp[x] = low;
            if (values[x >> 1] == -1)
                values[x >> 1] = x & 1;
        } while (x != i);
        return val[i] = low;
    }

    bool solve() {
        values.assign(N, -1);
        val.assign(2 * N, 0); comp = val;
        rep(i, 0, 2 * N) if (!comp[i]) dfs(i);
        rep(i, 0, N) if (comp[2 * i] == comp[2 * i + 1]) return 0;
        return 1;
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    TwoSat sat(2 * n);
    unordered_map<string, int> lookup;
    for (int i = 0; i < n; i++) {
        string w = to_string(i) + "w", h = to_string(i) + "h";
        lookup[w] = sz(lookup);
        lookup[h] = sz(lookup);
        sat.add_xor(lookup[w], lookup[h]);
    }

    const string BRIDE = "0w";

    sat.setValue(lookup[BRIDE]);

    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        sat.either(lookup[a], lookup[b]);
    }

    if (sat.solve()) {
        for (auto [k, v] : lookup) {
            if (sat.values[v] == 1 && k != BRIDE) {
                cout << k << " ";
            }
        }
        cout << "\n";
    }
    else {
        cout << "bad luck\n";
    }
}
