#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// #define unordered_map gp_hash_table

// #define int ll
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

uint8_t char_to_bits(char c) {
    switch (c) {
    case 'R':
        return 0;
    case 'G':
        return 1;
    case 'B':
        return 2;
    case 'Y':
        return 3;
    }
}

struct State {
    uint8_t r1, r2, r3, r4;

    State() {}

    State(uint8_t r1, uint8_t r2, uint8_t r3, uint8_t r4) : r1(r1), r2(r2), r3(r3), r4(r4) {}

    void set_row(int row_index, char a, char b, char c, char d) {
        uint8_t r = (char_to_bits(a) << 6) + (char_to_bits(b) << 4) + (char_to_bits(c) << 2) + char_to_bits(d);
        switch (row_index) {
        case 0:
            r1 = r;
            break;
        case 1:
            r2 = r;
            break;
        case 2:
            r3 = r;
            break;
        case 3:
            r4 = r;
            break;
        }
    }

    int to_int() const {
        return (((int)r1) << 24) | (((int)r2) << 16) | (((int)r3) << 8) | r4;
    }

    void rotr(int row_index) {
        switch (row_index) {
        case 0:
            r1 = ((r1) << 6) | (r1 >> 2);
            break;
        case 1:
            r2 = ((r2) << 6) | (r2 >> 2);
            break;
        case 2:
            r3 = ((r3) << 6) | (r3 >> 2);
            break;
        case 3:
            r4 = ((r4) << 6) | (r4 >> 2);
            break;
        }
    }

    void rotl(int row_index) {
        switch (row_index) {
        case 0:
            r1 = (r1 << 2) | ((r1) >> 6);
            break;
        case 1:
            r2 = (r2 << 2) | ((r2) >> 6);
            break;
        case 2:
            r3 = (r3 << 2) | ((r3) >> 6);
            break;
        case 3:
            r4 = (r4 << 2) | ((r4) >> 6);
            break;
        }
    }

    void rotu(int column_index) {
        uint8_t mask;
        switch (column_index) {
        case 0:
            mask = 0b11000000;
            break;
        case 1:
            mask = 0b110000;
            break;
        case 2:
            mask = 0b1100;
            break;
        case 3:
            mask = 0b11;
            break;
        }
        uint8_t temp = r1 & mask;
        r1 = (r1 ^ (r1 & mask)) | (r2 & mask);
        r2 = (r2 ^ (r2 & mask)) | (r3 & mask);
        r3 = (r3 ^ (r3 & mask)) | (r4 & mask);
        r4 = (r4 ^ (r4 & mask)) | temp;
    }

    void rotd(int column_index) {
        uint8_t mask;
        switch (column_index) {
        case 0:
            mask = 0b11000000;
            break;
        case 1:
            mask = 0b110000;
            break;
        case 2:
            mask = 0b1100;
            break;
        case 3:
            mask = 0b11;
            break;
        }
        uint8_t temp = r4 & mask;
        r4 = (r4 ^ (r4 & mask)) | (r3 & mask);
        r3 = (r3 ^ (r3 & mask)) | (r2 & mask);
        r2 = (r2 ^ (r2 & mask)) | (r1 & mask);
        r1 = (r1 ^ (r1 & mask)) | temp;
    }

    bool operator==(State other) const {
        return r1 == other.r1 && r2 == other.r2 && r3 == other.r3 && r4 == other.r4;
    }

    State& operator=(const State& other) {
        r1 = other.r1;
        r2 = other.r2;
        r3 = other.r3;
        r4 = other.r4;
        return *this;
    }
};

State final_state = State(0, 85, 170, 255);

unordered_map<int, pair<int, bool>> dp;

void solve_backward(const State& state, int max_depth) {
    queue<pair<State, int>> q({ {state, 0} });
    dp[state.to_int()] = { 0, true };
    while (!q.empty()) {
        auto [curr, curr_dist] = q.front();
        q.pop();
        if (curr_dist == max_depth) {
            continue;
        }
        for (int i = 0; i < 4; i++) {
            State next = curr;
            next.rotl(i);
            int hash = next.to_int();
            if (!in(dp, hash)) {
                dp[hash] = { curr_dist + 1, true };
                q.push({ next, curr_dist + 1 });
            }

            next = curr;
            next.rotr(i);
            hash = next.to_int();
            if (!in(dp, hash)) {
                dp[hash] = { curr_dist + 1, true };
                q.push({ next, curr_dist + 1 });
            }

            next = curr;
            next.rotu(i);
            hash = next.to_int();
            if (!in(dp, hash)) {
                dp[hash] = { curr_dist + 1, true };
                q.push({ next, curr_dist + 1 });
            }

            next = curr;
            next.rotd(i);
            hash = next.to_int();
            if (!in(dp, hash)) {
                dp[hash] = { curr_dist + 1, true };
                q.push({ next, curr_dist + 1 });
            }
        }
    }
}

int solve_forward(const State& state) {
    int h = state.to_int();
    if (in(dp, h)) {
        return dp[h].first;
    }
    queue<pair<State, int>> q({ {state, 0} });
    dp[h] = { 0, false };
    while (!q.empty()) {
        auto [curr, curr_dist] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            State next = curr;
            next.rotl(i);
            auto lookup = dp.find(next.to_int());
            if (lookup == dp.end()) {
                dp[next.to_int()] = { curr_dist + 1, false };
                q.push({ next, curr_dist + 1 });
            }
            else {
                auto [dist, valid] = lookup->second;
                if (valid) {
                    return curr_dist + dist + 1;
                }
            }

            next = curr;
            next.rotr(i);
            lookup = dp.find(next.to_int());
            if (lookup == dp.end()) {
                dp[next.to_int()] = { curr_dist + 1, false };
                q.push({ next, curr_dist + 1 });
            }
            else {
                auto [dist, valid] = lookup->second;
                if (valid) {
                    return curr_dist + dist + 1;
                }
            }

            next = curr;
            next.rotu(i);
            lookup = dp.find(next.to_int());
            if (lookup == dp.end()) {
                dp[next.to_int()] = { curr_dist + 1, false };
                q.push({ next, curr_dist + 1 });
            }
            else {
                auto [dist, valid] = lookup->second;
                if (valid) {
                    return curr_dist + dist + 1;
                }
            }

            next = curr;
            next.rotd(i);
            lookup = dp.find(next.to_int());
            if (lookup == dp.end()) {
                dp[next.to_int()] = { curr_dist + 1, false };
                q.push({ next, curr_dist + 1 });
            }
            else {
                auto [dist, valid] = lookup->second;
                if (valid) {
                    return curr_dist + dist + 1;
                }
            }
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    State init_state;
    for (int i = 0; i < 4; i++) {
        init_state.set_row(i, getchar(), getchar(), getchar(), getchar());
        getchar();
    }

    solve_backward(final_state, 6);

    cout << solve_forward(init_state) << "\n";
}
