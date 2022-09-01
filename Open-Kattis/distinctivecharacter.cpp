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

#define all(x) x.begin(), x.end()
#define in(x, a) (x.find(a) != x.end())

const int INF = 2e9;
const int MOD = 1e9 + 7;
/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define unordered_map gp_hash_table
*/
auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> dist(1 << 20, -1);
    queue<bitset<20>> q;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        bitset<20> c(s);
        q.push(c);
        dist[c.to_ulong()] = 0;
    }
    int largest = -1;
    bitset<20> ans = 0;
    while (!q.empty()) {
        bitset<20> curr = q.front();
        q.pop();
        int curr_dist = dist[curr.to_ulong()];
        bitset<20> temp = curr;
        for (int i = 0; i < k; i++) {
            temp[i] = temp[i] == 0 ? 1 : 0;
            if (i > 0) {
                temp[i - 1] = temp[i - 1] == 0 ? 1 : 0;
            }
            if (dist[temp.to_ulong()] == -1) {
                int new_dist = curr_dist + 1;
                dist[temp.to_ulong()] = new_dist;
                if (new_dist > largest) {
                    largest = new_dist;
                    ans = temp;
                }
                q.push(temp);
            }
        }
    }
    cout << ans.to_string().substr(20 - k) << "\n";
}
