#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define unordered_map gp_hash_table

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

using ld = long double;

struct Event {
    int type;
    ld r;
    ll o;
    ld A, B;
    int time;
    Event(ld r, ll o) : type(0), r(r), o(o) {}
    Event(int type, ld A, int time) : type(type), A(A), time(time) {}
    Event(int type, ld A, ld B, int time) : type(type), A(A), B(B), time(time) {}
};

struct Tree {
    typedef ll T;
    static constexpr T unit = 1;
    inline T f(T a, T b) { return ((__int128_t)a * (__int128_t)b) / __gcd(a, b); } // (any associative fn)
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(n << 1, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos >>= 1;)
            s[pos] = f(s[pos << 1], s[(pos << 1) + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b >>= 1, e >>= 1) {
            if (b & 1) ra = f(ra, s[b++]);
            if (e & 1) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int P, R;
    cin >> P >> R;
    vector<Event> events;
    events.reserve(P + 2 * R);
    for (int i = 0; i < P; i++) {
        ld r;
        ll o;
        cin >> r >> o;
        events.push_back(Event(r, o));
    }        
    for (int i = 0; i < R; i++) {
        ld A, B;
        cin >> A >> B;
        events.push_back(Event((int)1, A, i));
        events.push_back(Event((int)2, A, B, i));
    }

    sort(all(events), [](Event & e1, Event & e2) {
        if (e1.type == 0 && e2.type == 0) {
            return e1.r < e2.r;
        }
        else if (e1.type == 0 && e2.type == 1) {
            if (e1.r == e2.A) {
                return false;
            }
            return e1.r < e2.A;
        }
        else if (e1.type == 0 && e2.type == 2) {
            if (e1.r == e2.B) {
                return true;
            }
            return e1.r < e2.B;
        }
        else if (e1.type == 1 && e2.type == 0) {
            if (e1.A == e2.r) {
                return true;
            }
            return e1.A < e2.r;
        }
        else if (e1.type == 1 && e2.type == 1) {
            return e1.A < e2.A;
        }
        else if (e1.type == 1 && e2.type == 2) {
            return e1.A <= e2.B;
        }
        else if (e1.type == 2 && e2.type == 0) {
            if (e1.B == e2.r) {
                return false;
            }
            return e1.B < e2.r;
        }
        else if (e1.type == 2 && e2.type == 1) {
            return e1.B < e2.A;
        }
        else {
            return e1.B < e2.B;
        }
    });

    Tree st(P);
    int pc = 0;
    vector<ll> ans(R), mm(R);
    ld last = 0;
    for (int t = 0; t < P + 2 * R; t++) {
        if (events[t].type == 0) {
            last = events[t].r;
            st.update(pc, events[t].o);
            pc++;
        }
        else if (events[t].type == 1) {
            mm[events[t].time] = pc;
        }
        else {
            if (events[t].A <= last && last <= events[t].B) {
                ans[events[t].time] = st.query(mm[events[t].time], pc);
            }
            else {
                ans[events[t].time] = 1;
            }
        }
    }

    for (ll i : ans) {
        cout << i << "\n";
    }
}
