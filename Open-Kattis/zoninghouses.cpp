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

#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())

const int INF = 2e9 + 1e8;
const int MOD = 1e9 + 7;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define unordered_map gp_hash_table

struct House {
    int num, x, y;
    bool active = true;
};

vector<House> houses;

vector<int> merge(const vector<int> & a, const vector<int> & b) {
    int min_x = INF, min_y = INF, max_x = -INF, max_y = -INF,
        min_xi = -1, min_yi = -1, max_xi = -1, max_yi = -1;
    
    for (int i : a) {
        if (!houses[i].active) {
            continue;
        }
        if (houses[i].x < min_x) {
            min_x = houses[i].x;
            min_xi = i;
        }
        if (houses[i].y < min_y) {
            min_y = houses[i].y;
            min_yi = i;
        }
        if (houses[i].x > max_x) {
            max_x = houses[i].x;
            max_xi = i;
        }
        if (houses[i].y > max_y) {
            max_y = houses[i].y;
            max_yi = i;
        }
    }

    for (int i : b) {
        if (!houses[i].active) {
            continue;
        }
        if (houses[i].x < min_x) {
            min_x = houses[i].x;
            min_xi = i;
        }
        if (houses[i].y < min_y) {
            min_y = houses[i].y;
            min_yi = i;
        }
        if (houses[i].x > max_x) {
            max_x = houses[i].x;
            max_xi = i;
        }
        if (houses[i].y > max_y) {
            max_y = houses[i].y;
            max_yi = i;
        }
    }
    
    if (min_xi == -1 || min_yi == -1 || max_xi == -1 || max_yi == -1) {
        return {};
    }
    return {min_xi, min_yi, max_xi, max_yi};
}

struct Segment_tree {

    vector<int> extreme_houses;
    int lb, rb;
    Segment_tree *left, *right;

    Segment_tree(int lb, int rb) : lb(lb), rb(rb) {
        if (lb == rb) {
            left = right = 0;
            extreme_houses.push_back(lb);
        }
        else {
            int mid = lb + (rb - lb) / 2;
            left = new Segment_tree(lb, mid);
            right = new Segment_tree(mid + 1, rb);
            extreme_houses = merge(left->extreme_houses, right->extreme_houses);
        }
    }

    vector<int> get_extreme_houses(int a, int b) {
        if (rb < a || b < lb) {
            return {};
        }

        if (a <= lb && rb <= b) {
            return extreme_houses;
        }

        return merge(left->get_extreme_houses(a, b), right->get_extreme_houses(a, b));
    }

    void set(int index, bool status) {
        if (rb < index || index < lb) {
            return;
        }
        
        if (lb == index && index == rb) {
            houses[index].active = status;
            return;
        }

        if (left && left->lb <= index && index <= left->rb) {
            left->set(index, status);
        }
        else if (right) {
            right->set(index, status);
        }

        extreme_houses = merge(left->extreme_houses, right->extreme_houses);
    }

};

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    houses.reserve(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        houses.push_back({i, x, y});
    }
    
    Segment_tree *seg_tree = new Segment_tree(0, n - 1);
    
    while (q--) {
        int a, b;
        cin >> a >> b, a--, b--;
        
        int ans = INF;

        vector<int> extreme_houses = seg_tree->get_extreme_houses(a, b);
        for (int h : extreme_houses) {
            seg_tree->set(h, false);

            vector<int> maybe = seg_tree->get_extreme_houses(a, b);
            int min_x = INF, min_y = INF, max_x = -INF, max_y = -INF;
            for (int mh : maybe) {
                min_x = min(houses[mh].x, min_x);
                min_y = min(houses[mh].y, min_y);
                max_x = max(houses[mh].x, max_x);
                max_y = max(houses[mh].y, max_y);
            }

            int dx = abs(max_x - min_x),
                dy = abs(max_y - min_y);
            ans = min(ans, max(dx, dy));

            seg_tree->set(h, true);
        }

        cout << ans << "\n";
    }
}
