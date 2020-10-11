#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

struct Union_Find {
    vector<int> repr, sz;

    Union_Find(int n) {
        repr.resize(n);
        sz.resize(n, 1);
        for (int i = 1; i < n; i++) {
            repr[i] = i;
        }
    }

    auto Find(int a) -> int {
        if (a != repr[a]) {
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
        if (sz[b] > sz[a]) {
            swap(a, b);
        }
        repr[b] = a;
        sz[a] += sz[b];
    }

    auto size(int a) -> int {
        return sz[Find(a)];
    }
};

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int F;
        cin >> F;
        Union_Find UF(2 * F);
        unordered_map<string, int> ids;
        for (int i = 0; i < F; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            if (ids.find(s1) == ids.end()) {
                ids[s1] = ids.size();
            }
            if (ids.find(s2) == ids.end()) {
                ids[s2] = ids.size();
            }
            UF.Union(ids[s1], ids[s2]);
            cout << UF.size(ids[s1]) << "\n";
        }
    }
}
