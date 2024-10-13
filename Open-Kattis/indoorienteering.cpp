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

using ll = uint64_t;
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

const int INF = 2e9;
const int MOD = 1e9 + 7;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, L;
    cin >> n >> L;

    auto dist = make(0LL, n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
    }

    if (n == 2)
    {
        cout << (2 * dist[0][1] == L ? "possible" : "impossible") << "\n";
        return 0;
    }

    int leftover = n - 2;

    vector<int> valid_masks;
    for (int mask = 0; mask < (1 << leftover); mask++)
    {
        if (__builtin_popcount(mask) == (leftover >> 1))
        {
            valid_masks.push_back(mask);
        }
    }

    const int start = 0;

    vector<int> lookup(n);
    iota(all(lookup), 0);
    for (int end = 1; end < n; end++)
    {
        swap(lookup[end], lookup[n - 1]);

        for (int mask : valid_masks)
        {
            vector<int> chosen_inds;
            for (int i = 0; i < leftover; i++)
            {
                if ((mask >> i) & 1)
                {
                    chosen_inds.push_back(lookup[i + 1]);
                }
            }
            sort(all(chosen_inds));

            unordered_set<int> possible_dists;
            do
            {
                if (!chosen_inds.empty())
                {
                    int d = dist[start][chosen_inds[0]] + dist[chosen_inds.back()][end];
                    for (int i = 0; i < sz(chosen_inds) - 1; i++)
                    {
                        d += dist[chosen_inds[i]][chosen_inds[i + 1]];
                    }
                    possible_dists.insert(d);
                }
            } while (next_permutation(all(chosen_inds)));

            int complement_mask = ~mask;
            vector<int> inds;
            for (int i = 0; i < leftover; i++)
            {
                if ((complement_mask >> i) & 1)
                {
                    inds.push_back(lookup[i + 1]);
                }
            }
            sort(all(inds));

            do
            {
                int d = dist[start][inds[0]] + dist[inds.back()][end];
                for (int i = 0; i < sz(inds) - 1; i++)
                {
                    d += dist[inds[i]][inds[i + 1]];
                }
                if (in(possible_dists, L - d) || (possible_dists.empty() && d + dist[start][end] == L))
                {
                    cout << "possible\n";
                    return 0;
                }
            } while (next_permutation(all(inds)));
        }

        swap(lookup[end], lookup[n - 1]);
    }

    cout << "impossible\n";
}
