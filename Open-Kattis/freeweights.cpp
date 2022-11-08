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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define unordered_map gp_hash_table

#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
#define size(x) (ll)(x).size()

const int INF = 2e9;
const int MOD = 1e9 + 7;

struct Segment_tree {

    int value, lb, rb;
    Segment_tree *left, *right;

    Segment_tree(const vector<int> & xs, int lb, int rb) : lb(lb), rb(rb) {
        if (lb == rb) {
            left = right = 0;
            value = xs[lb];
        }
        else {
            int mid = lb + (rb - lb) / 2;
            left = new Segment_tree(xs, lb, mid);
            right = new Segment_tree(xs, mid + 1, rb);
            value = max(left->value, right->value);
        }
    }

    int query(int a, int b) {
        if (b < lb || rb < a) {
            return -INF;
        }

        if (a <= lb && rb <= b) {
            return value;
        }

        return max(left->query(a, b), right->query(a, b));
    }
};

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> row_1(n), row_2(n);
    for (int i = 0; i < n; i++) {
        cin >> row_1[i];
    }
    unordered_set<int> seen_2;
    for (int i = 0; i < n; i++) {
        cin >> row_2[i];
        seen_2.emplace(row_2[i]);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (in(seen_2, row_1[i])) {
            ans = max(ans, row_1[i]);
        }
    }

    unordered_map<ll, pii> locations_1;
    for (int i = 0; i < n; i++) {
        if (!in(locations_1, row_1[i])) {
            locations_1[row_1[i]].first = i;
        }
        else {
            locations_1[row_1[i]].second = i;
        }
    }

    Segment_tree *seg_1 = new Segment_tree(row_1, 0, n - 1);
    for (auto [_, p] : locations_1) {
        if (!(p.first == -1 || p.second == -1)) {
            if (abs(p.first - p.second) > 1) {
                ans = max(ans, min(row_1[p.first], seg_1->query(p.first + 1, p.second - 1)));
            }
        }
    }


    unordered_map<ll, pii> locations_2;
    for (int i = 0; i < n; i++) {
        if (!in(locations_2, row_2[i])) {
            locations_2[row_2[i]].first = i;
        }
        else {
            locations_2[row_2[i]].second = i;
        }
    }

    Segment_tree *seg_2 = new Segment_tree(row_2, 0, n - 1);
    for (auto [_, p] : locations_2) {
        if (!(p.first == -1 || p.second == -1)) {
            if (abs(p.first - p.second) > 1) {
                ans = max(ans, min(row_2[p.first], seg_2->query(p.first + 1, p.second - 1)));
            }
        }
    }

    cout << ans << "\n";
}
