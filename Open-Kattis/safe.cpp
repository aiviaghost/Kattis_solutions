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

struct Code {
    vector<vector<int>> code;

    Code(vector<vector<int>> code) : code(code) {}

    bool operator==(Code c) const {
        return code == c.code;
    }

    Code flip(int row, int col) {
        auto c = code;

        for (int i = 0; i < 3; i++) {
            c[i][col] = (c[i][col] + 1) % 4;
            if (i != col) c[row][i] = (c[row][i] + 1) % 4;
        }

        return c;
    }
};

namespace std {
    template<> struct hash<Code> {
        size_t operator()(const Code& p) const noexcept {
            const int B = 5;
            size_t h = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    h = B * h + p.code[i][j];
                }
            }
            return h;
        }
    };
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    auto c = make(0LL, 3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> c[i][j];
        }
    }

    Code start(c);
    unordered_map<Code, int> dist;
    dist[start] = 0;
    queue<Code> q({start});

    while (!q.empty()) {
        Code curr = q.front();
        q.pop();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Code next = curr.flip(i, j);
                if (!in(dist, next)) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }
    }

    Code end(make(0LL, 3, 3));
    cout << (in(dist, end) ? dist[end] : -1) << "\n";
}
