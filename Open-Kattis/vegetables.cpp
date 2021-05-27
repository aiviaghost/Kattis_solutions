#include <bits/stdc++.h>

using namespace std;

#define INF 2e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

struct vege {
    int size, cuts, id;
};

struct cmp {
    inline auto operator() (const vege &v1, const vege &v2) const -> bool {
        double p1_size = v1.size / (double) (v1.cuts + 1), p2_size = v2.size / (double) (v2.cuts + 1);
        if (abs(p1_size - p2_size) < 1e-5) {
            if (v1.size == v2.size) {
                return v1.id > v2.id;
            }
            return v1.size < v2.size;
        }

        return p1_size > p2_size;
    }
};

inline auto vege_ratio(const vege &v1, const vege &v2) -> double {
    double p1_size = v1.size / (double) (v1.cuts + 1), p2_size = v2.size / (double) (v2.cuts + 1);
    return p1_size / p2_size;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    set<vege, cmp> veges;
    double t;
    int n;
    cin >> t >> n;
    for (int i = 0; i < n; i++) {
        vege veg;
        cin >> veg.size;
        veg.cuts = 0;
        veg.id = i;
        veges.insert(veg);
    }
    
    int tot_cuts = 0;
    while (vege_ratio(*prev(veges.end()), *veges.begin()) <= t) {
        vege largest = *veges.begin();
        veges.erase(largest);

        largest.cuts++;
        tot_cuts++;

        veges.insert(largest);
    }

    cout << tot_cuts << "\n";
}
