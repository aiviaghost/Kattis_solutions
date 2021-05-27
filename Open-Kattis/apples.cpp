#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using pii = pair<int, int>;
using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    char grid[R][C];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    for (int c = 0; c < C; c++) {
        queue<pii> q;
        int r = R - 1;
        while (r >= 0) {
            if (grid[r][c] == '#') {
                queue<pii> empty;
                swap(q, empty); // clears the queue
            }

            if (grid[r][c] == '.') {
                q.push({c, r});
            }
            else if (grid[r][c] == 'a' && !q.empty()) {
                pii first_available = q.front();
                q.pop();
                grid[first_available.second][first_available.first] = 'a';
                grid[r][c] = '.';
                q.push({c, r});
            }

            r--;
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}
