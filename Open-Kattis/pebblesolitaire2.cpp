#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

const int INF = 2e9;

auto get_neighbours(bitset<23>& curr) -> vector<bitset<23>> {
    vector<bitset<23>> next;
    for (int i = 1; i < 22; i++) {
        if (curr.test(i) && curr.test(i - 1) && !curr.test(i + 1)) {
            bitset<23> temp(curr);
            temp.set(i + 1);
            temp.reset(i);
            temp.reset(i - 1);
            next.push_back(temp);
        }
        else if (curr.test(i) && !curr.test(i - 1) && curr.test(i + 1)) {
            bitset<23> temp(curr);
            temp.set(i - 1);
            temp.reset(i);
            temp.reset(i + 1);
            next.push_back(temp);
        }
    }
    return next;
}

auto bfs(bitset<23>& start) -> int {
    int min_left = INF;
    vector<bool> vis(1 << 23);
    vis[start.to_ulong()] = true;
    queue<bitset<23>> q;
    q.push(start);
    while (!q.empty()) {
        bitset<23> curr = q.front();
        q.pop();
        min_left = min((int) curr.count(), min_left);
        for (bitset<23> next : get_neighbours(curr)) {
            if (!vis[next.to_ulong()]) {
                vis[next.to_ulong()] = true;
                q.push(next);
            }
        }
    }
    return min_left;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string seq;
        cin >> seq;
        bitset<23> start;
        for (int i = 0; i < 23; i++) {
            if (seq[i] == 'o') {
                start.set(i);
            }
        }
        cout << bfs(start) << "\n";
    }
}
