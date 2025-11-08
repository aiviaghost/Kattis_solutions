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

int ans = 0;

struct Trie
{
    Trie *children[26];
    int num_children = 0;

    Trie()
    {
        memset(children, 0, sizeof(children));
    }

    void insert(const string &s, int idx = 0)
    {
        if (idx == s.length())
        {
            return;
        }

        if (!children[s[idx] - 'a'])
        {
            if (num_children >= 1)
            {
                ans = max(ans, idx);
            }
            children[s[idx] - 'a'] = new Trie();
            num_children++;
        }

        children[s[idx] - 'a']->insert(s, idx + 1);
    }
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    Trie trie;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        reverse(all(s));

        trie.insert(s);
    }

    cout << ans << "\n";
}
