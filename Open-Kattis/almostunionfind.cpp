#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// #define unordered_map gp_hash_table

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

struct AlmostUnionFind {
    int n;
    vector<int> repr, sz, sum, remap;

    AlmostUnionFind(int n) : n(n), repr(n), sz(n, 1), sum(n), remap(n) {
        iota(all(repr), 0);
        iota(all(sum), 1);
        iota(all(remap), 0);
    }

    int find(int a) {
        if (repr[a] != a) {
            repr[a] = find(repr[a]);
        }
        return repr[a];
    }

    void merge(int a, int b) {
        a = find(remap[a]);
        b = find(remap[b]);
        if (a == b) {
            return;
        }
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        repr[b] = a;
        sz[a] += sz[b];
        sum[a] += sum[b];
    }

    int num_elems(int a) {
        return sz[find(remap[a])];
    }

    int get_sum(int a) {
        return sum[find(remap[a])];
    }

    void move(int a, int b) {
        int ra = find(remap[a]);
        int rb = find(remap[b]);
        sum[ra] -= a + 1;
        sum[rb] += a + 1;
        remap[a] = remap[b];
        sz[ra]--;
        sz[rb]++;
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);


    int n, m;
    while (cin >> n >> m) {
        AlmostUnionFind auf(n);

        for (int i = 0; i < m; i++) {
            int cmd, p, q;
            cin >> cmd >> p, p--;
            if (cmd == 1) {
                cin >> q, q--;
                auf.merge(p, q);
            }
            else if (cmd == 2) {
                cin >> q, q--;
                auf.move(p, q);
            }
            else {
                cout << auf.num_elems(p) << " " << auf.get_sum(p) << "\n";
            }
        }
    }
}
