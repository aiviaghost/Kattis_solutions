#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// #define unordered_map gp_hash_table

#define int ll
#define all(xs) xs.begin(), xs.end()
#define in(xs, a) (xs.find(a) != xs.end())
#define sz(x) (ll)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vi = vector<int>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

const int INF = 2e9;
const int MOD = 1e9 + 7;

class SegTree {
    private:
        int n4;
        vector<int> L, R, value;

        void combine(int i) {
            value[i] = max(value[2 * i], value[2 * i + 1]);
        }

        void setup(int i, int lo, int hi) {
            L[i] = lo;
            R[i] = hi;
            if (lo == hi) {
                return;
            }

            int mid = (lo + hi) / 2;
            setup(2 * i, lo, mid);
            setup(2 * i + 1, mid + 1, hi);
            combine(i);
        }

        void update(int i, int idx, int val) {
            if (idx < L[i] || R[i] < idx) {
                return;
            }

            if (L[i] == R[i] && L[i] == idx) {
                value[i] = val;
                return;
            }

            update(2 * i, idx, val);
            update(2 * i + 1, idx, val);
            combine(i);
        }

        int find_first(int i, int lb, int x) {
            if (value[i] < x) {
                return -1;
            }

            if (R[i] < lb) {
                return -1;
            }

            if (L[i] == R[i]) {
                return L[i];
            }

            int res = find_first(2 * i, lb, x);
            if (res == -1) {
                res = find_first(2 * i + 1, lb, x);
            }
            return res;
        }

    public:
        SegTree(int n) : n4(4 * n), L(n4), R(n4), value(n4) {
            setup(1, 0, n - 1);
        }

        void update(int idx, int val) {
            update(1, idx, val);
        }

        int find_first(int lb, int x) {
            return find_first(1, lb, x);
        }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    struct Student {
        int knowledge,
            understanding,
            index;
    };

    vector<Student> students;
    vector<pii> P;

    for (int i = 0; i < n; i++) {
        char type;
        cin >> type;
        if (type == 'D') {
            int A, B;
            cin >> A >> B;
            students.push_back({B, A, sz(students)});
        }
        else {
            int idx;
            cin >> idx;
            idx--;
            P.push_back({idx, sz(students)});
        }
    }

    sort(all(students), [](Student a, Student b) {
        return a.knowledge < b.knowledge || (a.knowledge == b.knowledge && a.understanding < b.understanding);
    });
    vector<int> idx_to_sorted(sz(students)), sorted_to_idx(sz(students));
    int idx = 0;
    for (auto [_1, _2, i] : students) {
        idx_to_sorted[i] = idx;
        sorted_to_idx[idx] = i;
        idx++;
    }

    SegTree st(sz(students));
    int in_tree = 0;
    for (auto [idx, students_added_before] : P) {
        while (in_tree < students_added_before) {
            st.update(idx_to_sorted[in_tree], students[idx_to_sorted[in_tree]].understanding);
            in_tree++;
        }

        int ans = st.find_first(idx_to_sorted[idx] + 1, students[idx_to_sorted[idx]].understanding);
        cout << (ans != -1 ? to_string(sorted_to_idx[ans] + 1) : "NE") << "\n";
    }
}
