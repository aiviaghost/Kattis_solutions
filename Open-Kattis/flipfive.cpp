#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto get_neighbour(bitset<9> &bit, pii &next) -> bitset<9> {
    auto is_inside = [] (int x, int y) { return 0 <= x && x < 3 && 0 <= y && y < 3; };

    bool grid[3][3];
    string bitstring = bit.to_string();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = bitstring[3 * i + j] == '1';
        }
    }

    grid[next.second][next.first] = !grid[next.second][next.first];
    if (is_inside(next.first, next.second - 1)) grid[next.second - 1][next.first] = !grid[next.second - 1][next.first];
    if (is_inside(next.first + 1, next.second)) grid[next.second][next.first + 1] = !grid[next.second][next.first + 1];
    if (is_inside(next.first, next.second + 1)) grid[next.second + 1][next.first] = !grid[next.second + 1][next.first];
    if (is_inside(next.first - 1, next.second)) grid[next.second][next.first - 1] = !grid[next.second][next.first - 1];

    bitset<9> res;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j]) { res.set(3 * i + j); }
        }
    }

    return res;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    
    int P;
    cin >> P;
    while (P--) {
        bitset<9> goal;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char state;
                cin >> state;
                if (state == '*') goal.set(3 * i + j);
            }
        }

        pii neighbours[9] = {{0, 0}, {1, 0}, {2, 0}, 
                             {0, 1}, {1, 1}, {2, 1}, 
                             {0, 2}, {1, 2}, {2, 2}};
        int dist[512];
        memset(dist, -1, 4 * 512);
        dist[0] = 0;
        queue<bitset<9>> q;
        q.push(0);
        while (!q.empty()) {
            bitset<9> curr = q.front();
            q.pop();
            for (int i = 0; i < 9; i++) {
                bitset<9> next = get_neighbour(curr, neighbours[i]);
                if (dist[next.to_ulong()] == -1) {
                    dist[next.to_ulong()] = dist[curr.to_ulong()] + 1;
                    q.push(next);
                }
            }
        }
        
        cout << dist[goal.to_ulong()] << "\n";
    }
}
