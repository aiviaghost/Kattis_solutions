#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// #define unordered_map gp_hash_table

#define int ll
#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
#define sz(x) (ll)(x).size()
#define rep(i, a, b) for (int i = a; i < (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vi = vector<int>;

template <typename T>
vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args>
auto make(T init, size_t first, Args... sizes)
{
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

const int INF = 1e18;
const int MOD = 1e9 + 7;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, s, t;
    cin >> n >> s >> t;

    map<int, int> og_belt;
    for (int i = 0; i < n; i++)
    {
        int idx;
        cin >> idx;
        og_belt[idx]++;
    }

    vector<int> active_positions;
    for (auto [k, _] : og_belt) {
        active_positions.push_back(k);
    }
    unordered_map<int, int> num_before;
    num_before[active_positions[0]] = active_positions[0] + (s - active_positions.back() - 1);
    for (int i = 0; i < sz(active_positions) - 1; i++) {
        num_before[active_positions[i + 1]] = active_positions[i + 1] - active_positions[i] - 1;
    }

    int min_total = INF;
    int max_total = -1;
    int avg = 0;
    for (auto [start, _] : og_belt)
    {
        auto belt = og_belt;

        int curr_spot = start,
            total_t = 0;
        for (int it = 0; it < n; it++)
        {
            auto tmp = belt.lower_bound(curr_spot);
            if (tmp == belt.end())
            {
                total_t += s - curr_spot;
                curr_spot = 0;
                tmp = belt.begin();
            }
            auto&& [idx, count] = *tmp;
            count--;
            if (count == 0)
            {
                belt.erase(idx);
            }
            total_t += idx - curr_spot;
            total_t += t;
            curr_spot = (idx + t) % s;
        }

        min_total = min(min_total, total_t);
        max_total = max(max_total, num_before[start] + total_t);
        avg += ((1 + num_before[start]) * (total_t + total_t + num_before[start])) / 2;
    }

    cout << min_total << "\n";
    cout << max_total << "\n";
    int d = gcd(avg, s);
    cout << (avg / d) << "/" << (s / d) << "\n";
}
