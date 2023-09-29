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

template<typename T, typename cmp = less<T>> using order_statistic_tree = tree<
    T,
    null_type,
    cmp,
    rb_tree_tag,
    tree_order_statistics_node_update>;

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> opus_numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> opus_numbers[i];
    }

    order_statistic_tree<int> ost;
    for (int i = 0; i < n; i++) {
        ost.insert(i);
    }

    int member_index = 0;
    for (int i = 0; i < n - 1; i++) {
        int index_in_tree = ost.order_of_key(member_index);
        auto it = ost.find_by_order((index_in_tree + opus_numbers[member_index] - 1) % size(ost));
        int r = *it;
        it++;
        member_index = it != ost.end() ? *it : *ost.begin();
        ost.erase(r);
    }

    cout << *ost.begin() + 1 << "\n";
}
