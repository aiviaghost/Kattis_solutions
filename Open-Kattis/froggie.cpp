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

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int L, W;
    cin >> L >> W;
    
    vector<char> LR(L);
    for (int i = 0; i < L; i++) {
        if (i % 2 == 0) {
            LR[i] = 'R';
        }
        else {
            LR[i] = 'L';
        }
    }
    
    vector<int> speeds(L), spacing(L);
    vector<deque<int>> cars(L);
    for (int i = 0; i < L; i++) {
        int O, I, S;
        cin >> O >> I >> S;
        speeds[i] = S;
        spacing[i] = I;
        if (LR[i] == 'R') {
            int curr = O;
            while (curr < W) {
                cars[i].push_back(curr);
                curr += I;
            }
        }
        else {
            int curr = W - 1 - O;
            while (curr >= 0) {
                cars[i].push_front(curr);
                curr -= I;
            }
        }
    }

    int P;
    cin >> P;

    vector<int> times(L);

    int t = 0;

    auto rotate = [&](int y, int steps) {
        for (int i = 0; i < steps; i++) {
            for (int j = 0; j < size(cars[y]); j++) {
                if (LR[y] == 'R') {
                    cars[y][j] += speeds[y];
                }
                else {
                    cars[y][j] -= speeds[y];
                }
            }
            while (cars[y].back() + spacing[y] < W) {
                cars[y].push_back(cars[y].back() + spacing[y]);
            }
            while (cars[y].front() < 0) {
                cars[y].pop_front();
            }
            while (cars[y].front() - spacing[y] >= 0) {
                cars[y].push_front(cars[y].front() - spacing[y]);
            }
            while (cars[y].back() >= W) {
                cars[y].pop_back();
            }
        }
        times[y] += steps;
    };

    string moves;
    cin >> moves;

    bool valid = true;

    int x = P, y = L;

    auto check = [&](int y) {
        for (int i : cars[y]) {
            if (LR[y] == 'R') {
                if (i + speeds[y] == x || (i < x && x <= i + speeds[y])) {
                    valid = false;
                }
            }
            else {
                if (i - speeds[y] == x || (i - speeds[y] <= x && x < i)) {
                    valid = false;
                }
            }
        }
        if (LR[y] == 'R') {
            if (cars[y].front() + speeds[y] - spacing[y] >= 0 && x <= cars[y].front() + speeds[y] - spacing[y]) {
                valid = false;
            }
        }
        else {
            if (cars[y].back() - speeds[y] + spacing[y] < W && cars[y].back() - speeds[y] + spacing[y] <= x) {
                valid = false;
            }
        }
    };

    for (char c : moves) {
        if (c == 'U') {
            y--;            
            if (0 <= y && y < L) {
                rotate(y, t - times[y]);

                check(y);

                rotate(y, 1);
            }
        }
        else if (c == 'D') {
            y++;
            if (0 <= y && y < L) {
                rotate(y, t - times[y]);
            
                check(y);

                rotate(y, 1);
            }
        }
        else if (c == 'L') {
            x--;
            if (0 <= y && y < L) {
                check(y);

                rotate(y, 1);
            }
        }
        else if (c == 'R') {
            x++;
            if (0 <= y && y < L) {
                check(y);

                rotate(y, 1);
            }
        }
        t++;
    }

    if (y != -1) {
        valid = false;
    }

    cout << (valid ? "safe" : "squish") << "\n";
}
