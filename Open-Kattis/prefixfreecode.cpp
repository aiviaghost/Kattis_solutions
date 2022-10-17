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

#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())

const int INF = 2e9;
const int MOD = 1e9 + 7;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define unordered_map gp_hash_table

vector<int> merge(const vector<int> & a, const vector<int> & b) {
    vector<int> res;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            res.push_back(a[i]);
            i++;
        }
        else {
            res.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size()) {
        res.push_back(a[i]);
        i++;
    }
    while (j < b.size()) {
        res.push_back(b[j]);
        j++;
    }
    return res;
}

struct Segment_tree {
    
    vector<int> elems;
    int lb, rb;
    Segment_tree *left, *right;

    Segment_tree(const vector<int> & target, int lb, int rb) : lb(lb), rb(rb) {
        if (lb == rb) {
            left = right = 0;
            elems.push_back(target[lb]);
        }
        else {
            int mid = lb + (rb - lb) / 2;
            left = new Segment_tree(target, lb, mid);
            right = new Segment_tree(target, mid + 1, rb);
            elems = merge(left->elems, right->elems);
        }
    }

    int query(int rb, int x) {
        if (rb < lb) {
            return 0;
        }

        if (this->rb <= rb) {
            return lower_bound(all(elems), x) - elems.begin();
        }

        return left->query(rb, x) + right->query(rb, x);
    }
};

int n, k;
vector<ll> facs, invs, dp;

inline ll bin_exp(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if ((exp & 1) == 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

inline ll inv(ll a) {
    return bin_exp(a, MOD - 2);
}

inline ll choose(ll a, ll b) {
    return (facs[a] * inv(facs[a - b])) % MOD;
}

ll solve(const vector<int> & target, int curr = 0) {
    if (curr == target.size()) {
        return 1;
    }
    ll ans = 0;
    if (target[curr] > 0) {
        ans = (ans + ((target[curr] - dp[curr]) * choose(n - 1 - curr, k - 1 - curr)) % MOD) % MOD;
    }
    ans = (ans + solve(target, curr + 1)) % MOD;
    return ans;
}

using i128 = __int128_t;
const i128 B = 3001, P = 13787311523495059631ULL;
i128 poly_hash(const string & s) {
    i128 res = 0;
    for (int i = 0; i < s.size(); i++) {
        res = (((B * res) % P) + (s[i] - 'a' + 1)) % P;
    }
    return res;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    vector<string> ss;
    ss.reserve(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ss.push_back(s);
    }
    
    string test;
    cin >> test;
    
    sort(all(ss));
    map<i128, int> lookup;
    for (string s : ss) {
        lookup[poly_hash(s)] = lookup.size();
    }
    
    vector<int> target;
    int prev = 0;
    while (target.size() < k) {
        i128 curr = 0;
        int it = 0;
        for (int i = prev; i < test.size(); i++) {
            curr = (((B * curr) % P) + (test[i] - 'a' + 1)) % P;
            it++;
            if (in(lookup, curr)) {
                target.push_back(lookup[curr]);
                break;
            }
        }
        prev += it;
    }

    dp.resize(n);
    Segment_tree *seg_tree = new Segment_tree(target, 0, k - 1);
    for (int i = 1; i < k; i++) {
        dp[i] = seg_tree->query(i, target[i]);
    }

    facs.resize(n + 1);
    facs[0] = 1;
    for (int i = 1; i <= n; i++) {
        facs[i] = (i * facs[i - 1]) % MOD;
    }
    cout << solve(target) << "\n";
}
