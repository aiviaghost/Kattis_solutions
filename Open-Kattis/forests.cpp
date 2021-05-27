#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

struct Union_Find {
    vector<int> repr, size;
    int sets;

    auto Find(int a) -> int {
        if (a == repr[a]) {
            return a;
        }
        repr[a] = Find(repr[a]);
        return repr[a];
    }

    auto Union(int a, int b) -> void {
        a = Find(a);
        b = Find(b);
        if (a == b) {
            return;
        }
        sets--;
        if (size[b] > size[a]) {
            swap(a, b);
        }
        repr[b] = a;
        size[a] += size[b];
    }

    Union_Find(int n) {
        sets = n;
        repr.resize(n);
        size.resize(n, 1);
        for (int i = 1; i < n; i++) {
            repr[i] = i;
        }
    }
};

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int p, t;
    cin >> p >> t;
    unordered_set<int> ps[p];
    Union_Find UF(p);
    int pi, tj;
    while (cin >> pi >> tj) {
        pi--, tj--;
        ps[pi].emplace(tj);
    }

    for (int i = 0; i < p; i++) {
        for (int j = i + 1; j < p; j++) {
            if (ps[i].size() == ps[j].size()) {
                bool same = true;
                for (auto itr = ps[i].begin(); itr != ps[i].end(); itr++) {
                    if (ps[j].find(*itr) == ps[j].end()) {
                        same = false;
                        break;
                    }
                }
                if (same) {
                    UF.Union(i, j);
                }
            }
        }
    }

    cout << UF.sets << "\n";
}
