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
const int MOD = 1e9 + 7;

constexpr const pii dirs[] = {
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}
};

map<pii, string> moves = {
    {dirs[0], "left"}, 
    {dirs[1], "up"}, 
    {dirs[2], "right"}, 
    {dirs[3], "down"}
};

pii add(pii & pos, pii & dir) {
    return {pos.first + dir.first, pos.second + dir.second};
}

pii opposite(pii & dir) {
    return {-1 * dir.first, -1 * dir.second};
}

string ignore_response;
set<pii> vis;
stack<pii> last_move;
void dfs(pii curr = {0, 0}) {
    if (vis.count(curr)) {
        cout << moves[opposite(last_move.top())] << "\n" << flush;
        last_move.pop();
        cin >> ignore_response;
        return;
    }
    vis.emplace(curr);
    for (pii dir : dirs) {
        if ((last_move.empty() || dir != opposite(last_move.top())) && !vis.count(add(curr, dir))) {
            cout << moves[dir] << "\n" << flush;
            string response;
            cin >> response;
            if (response == "wall") {
                continue;
            }
            else if (response == "ok") {
                last_move.push(dir);
                dfs(add(curr, dir));
            }
            else {
                exit(0);
            }
        }
    }
    if (!last_move.empty()) {
        cout << moves[opposite(last_move.top())] << "\n" << flush;
        last_move.pop();
        cin >> ignore_response;
    }
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    dfs();
    cout << "no way out\n" << flush;
    cin >> ignore_response;
}
