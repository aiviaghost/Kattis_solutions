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

const int INF = 2e9;
const int MOD = 1e9 + 7;

const int B = 29;
const int P = 987654121;

int pows[101];

int hash_str(const string &s)
{
    int h = 0;
    for (char c : s)
    {
        h = h * B + (c - 'a' + 1);
    }
    return h;
}

string solve(const vector<string> &s, const vector<pii> &as, const vector<pii> &bs)
{
    int n = sz(as);
    vector<int> inds(n);
    iota(all(inds), 0);

    int ans_len = INF;
    string ans;

    do
    {
        int total_h1 = 0, total_h2 = 0;
        int total_l1 = 0, total_l2 = 0;

        int pref_used = 1;
        for (int i : inds)
        {
            auto [h1, l1] = as[i];
            total_h1 = total_h1 * pows[l1] + h1;
            total_l1 += l1;
            if (total_l1 > ans_len)
            {
                break;
            }

            auto [h2, l2] = bs[i];
            total_h2 = total_h2 * pows[l2] + h2;
            total_l2 += l2;
            if (total_l2 > ans_len)
            {
                break;
            }

            if (total_h1 == total_h2 && total_l1 == total_l2 && total_l1 <= ans_len)
            {
                ans_len = total_l1;
                string maybe_ans;
                for (int j = 0; j < pref_used; j++)
                {
                    maybe_ans += s[inds[j]];
                }
                ans = ans.empty() ? maybe_ans : min(ans, maybe_ans);
            }

            pref_used++;
        }
    } while (next_permutation(all(inds)));

    return ans;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    pows[0] = 1;
    for (int i = 1; i < 101; i++)
    {
        pows[i] = pows[i - 1] * B;
    }

    int k, t = 1;
    while (cin >> k)
    {
        vector<string> s(k);
        vector<pii> data_a(k), data_b(k);
        for (int i = 0; i < k; i++)
        {
            string a, b;
            cin >> a >> b;
            s[i] = a;
            data_a[i] = {hash_str(a), sz(a)};
            data_b[i] = {hash_str(b), sz(b)};
        }

        auto ans = solve(s, data_a, data_b);

        cout << "Case " << t << ": " << (ans.empty() ? "IMPOSSIBLE" : ans) << "\n";
        t++;
    }
}
