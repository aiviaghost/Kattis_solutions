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

#define int ll
#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
#define size(x) (ll)(x).size()

const int INF = 2e9;
const int MOD = 1e9 + 7;

using i128 = __int128_t;

struct Hash {

    int n;
    vector<i128> hashes, ex;
    i128 B, P;

    Hash(string & s, i128 B, i128 P) : n(size(s)), hashes(n + 1), ex(n + 1), B(B), P(P) {
        hashes[0] = 1;
        ex[0] = 1;
        for (int i = 0; i < n; i++) {
            hashes[i + 1] = ((hashes[i] * B) % P + s[i] - 'a' + 1) % P;
            ex[i + 1] = (ex[i] * B) % P;
        }
    }

    i128 hash(int lb, int rb) {
        return (hashes[rb] - (hashes[lb] * ex[rb - lb]) % P + P) % P;
    }

    i128 del(int index) {
        return ((hash(0, index) * ex[B, n - index - 1]) % P + hash(index + 1, n)) % P;
    }

};

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<string> words;
    vector<Hash> hashes;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        words.push_back(s);
        hashes.push_back(Hash(s, 31, 6787712873425775803));
    }

    set<i128> seen;
    for (int i = 0; i < n; i++) {
        seen.emplace(hashes[i].hash(0, size(words[i])));
    }

    bool found = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < size(words[i]); j++) {
            if (in(seen, hashes[i].del(j))) {
                found = true;
                cout << words[i] << "\n";
                break;
            }
        }
    }

    if (!found) {
        cout << "NO TYPOS\n";
    }
}
