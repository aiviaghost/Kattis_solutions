#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define unordered_map gp_hash_table

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

using tiii = tuple<int, int, int>;

struct Segment_tree {

    int lb, rb, val = INF;
    Segment_tree *left, *right;

    Segment_tree(int lb, int rb) : lb(lb), rb(rb) {
        if (lb == rb) {
            left = right = 0;
        }
        else {
            int mid = lb + (rb - lb) / 2;
            left = new Segment_tree(lb, mid);
            right = new Segment_tree(mid + 1, rb);
        }
    }

    int query(int a, int b) {
        if (rb < a || b < lb) {
            return INF;
        }

        if (a <= lb && rb <= b) {
            return val;
        }

        return min(left->query(a, b), right->query(a, b));
    }

    void set(int index, int new_val) {
        if (rb < index || index < lb) {
            return;
        }
        
        if (lb == index && index == rb) {
            val = new_val;
            return;
        }

        if (left->lb <= index && index <= left->rb) {
            left->set(index, new_val);
        }
        else {
            right->set(index, new_val);
        }

        val = min(left->val, right->val);
    }

};

int coordinate_compression(vector<pii> & points, vector<tiii> & sensors) {
    int point = 1, sensor_start = 0, sensor_end = 2;
    vector<tiii> xs;
    for (int i = 0; i < size(points); i++) {
        xs.push_back({points[i].first, point, i});
    }
    for (int i = 0; i < size(sensors); i++) {
        xs.push_back({get<0>(sensors[i]), sensor_start, i});
        xs.push_back({get<1>(sensors[i]), sensor_end, i});
    }

    sort(all(xs));
    
    int curr_x = 0;
    for (int i = 0; i < size(xs); i++) {
        auto [x, obj_type, idx] = xs[i];
        if (obj_type == point) {
            points[idx].first = curr_x;
        }
        else if (obj_type == sensor_start) {
            get<0>(sensors[idx]) = curr_x;
        }
        else {
            get<1>(sensors[idx]) = curr_x;
        }

        curr_x++;
    }
    
    return curr_x;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int D, S;
    cin >> D >> S;

    vector<pii> points(D);
    for (int i = 0; i < D; i++) {
        cin >> points[i].first >> points[i].second;
    }
    vector<tiii> sensors(S);
    for (int i = 0; i < S; i++) {
        cin >> get<0>(sensors[i]) >> get<1>(sensors[i]) >> get<2>(sensors[i]);
    }

    int max_x = coordinate_compression(points, sensors);
    Segment_tree st(0, max_x);

    unordered_map<int, set<pii>> y_levels;
    map<pii, int> idx_map;
    for (pii p : points) {
        idx_map[p] = size(idx_map);
        y_levels[p.second].emplace(p);
    }

    sort(all(points), [&](pii & p1, pii & p2) {
        return p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first);
    });

    sort(all(sensors), [&](tiii & s1, tiii & s2) {
        return get<2>(s1) > get<2>(s2) || (get<2>(s1) == get<2>(s2) && get<0>(s1) < get<0>(s2));
    });

    vector<int> ans(D);
    int points_idx = 0;
    for (auto [x1, x2, y] : sensors) {
        while (points_idx < size(points) && points[points_idx].second >= y) {
            st.set(points[points_idx].first, points[points_idx].second);
            points_idx++;
        }

        int lowest_y_inside = st.query(x1, x2);

        if (lowest_y_inside == INF) {
            continue;
        }

        while (1) {
            auto p = y_levels[lowest_y_inside].lower_bound({x1, 0});
            if (p == y_levels[lowest_y_inside].end()) {
                break;
            }
            auto [px, py] = *p;
            if (px > x2) {
                break;
            }
            
            ans[idx_map[*p]] = y;
            st.set(px, INF);
            y_levels[lowest_y_inside].erase(*p);
        }
    }

    for (int y : ans) {
        cout << y << "\n";
    }
}
