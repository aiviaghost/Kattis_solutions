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

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<string> initial_words(n);
    for (auto &&s : initial_words)
    {
        cin >> s;
    }

    optional<string> ans = {};
    auto solve = [&](auto &&solve, const vector<string> &words) -> void
    {
        if (words.size() == 1)
        {
            ans = ans.and_then([&](string a)
                               {
                    string res = a.size() < words[0].size() ? a : a.size() > words[0].size() ? words[0] : min(a, words[0]);
                    return optional(res); })
                      .value_or(words[0]);
            return;
        }

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                string s1 = words[i];
                string s2 = words[j];
                vector<string> new_words;
                for (int k = 0; k < words.size(); k++)
                {
                    if (k != i && k != j)
                    {
                        new_words.push_back(words[k]);
                    }
                }
                for (int it = 0; it < 2; it++)
                {
                    for (int k = 1; k <= min(s1.size(), s2.size()); k++)
                    {
                        if (s1.substr(s1.size() - k) == s2.substr(0, k))
                        {
                            new_words.push_back(s1 + s2.substr(k));
                            solve(solve, new_words);
                            new_words.pop_back();
                        }
                    }
                    swap(s1, s2);
                }
            }
        }
    };

    solve(solve, initial_words);

    cout << (ans.has_value() ? ans.value() : "-1") << "\n";
}
