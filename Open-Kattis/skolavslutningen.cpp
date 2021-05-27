#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

const int INF = 2e9;

struct Union_Find {
    vector<int> repr, sz;
    int sets;

    Union_Find(int n) {
        sets = n;
        sz.resize(n, 1);
        repr.resize(n);
        for (int i = 1; i < n; i++) {
            repr[i] = i;
        }
    }

    auto Find(int a) -> int {
        if (repr[a] != a) {
            repr[a] = Find(repr[a]);
        }
        return repr[a];
    }

    auto Union(int a, int b) -> void {
        a = Find(a);
        b = Find(b);
        if (a == b) {
            return;
        }
        sets--;
        if (sz[b] > sz[a]) {
            swap(a, b);
        }
        repr[b] = a;
        sz[a] += sz[b];
    }
};

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    int grid[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            grid[i][j] = c - 'A';
        }
    }

    Union_Find UF = Union_Find(k);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            UF.Union(grid[j][i], grid[j + 1][i]);
        }
    }

    cout << UF.sets << "\n";
}
