#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    cin.ignore();
    cout << T << "\n";
    while (T--) {
        string inst;
        getline(cin, inst);
        int len = inst.length();

        pii curr = {0, 0}, dir = {1, 0};
        vector<pii> path{curr};
        int minX = 0, minY = 0, maxX = 0, maxY = 0;
        for (int i = 0; i < len; i++) {
            if (inst[i] == 'B') {
                dir.first *= -1;
                dir.second *= -1;
            }
            else if (inst[i] == 'L') {
                if (dir.first == 1 && dir.second == 0) {
                    dir.first = 0;
                    dir.second = -1;
                }
                else if (dir.first == 0 && dir.second == -1) {
                    dir.first = -1;
                    dir.second = 0;
                }
                else if (dir.first == -1 && dir.second == 0) {
                    dir.first = 0;
                    dir.second = 1;
                }
                else {
                    dir.first = 1;
                    dir.second = 0;
                }
            }
            else if (inst[i] == 'R') {
                if (dir.first == 1 && dir.second == 0) {
                    dir.first = 0;
                    dir.second = 1;
                }
                else if (dir.first == 0 && dir.second == 1) {
                    dir.first = -1;
                    dir.second = 0;
                }
                else if (dir.first == -1 && dir.second == 0) {
                    dir.first = 0;
                    dir.second = -1;
                }
                else {
                    dir.first = 1;
                    dir.second = 0;
                }
            }

            curr.first += dir.first;
            curr.second += dir.second;
            path.push_back(curr);

            minX = min(curr.first, minX);
            minY = min(curr.second, minY);
            maxX = max(curr.first, maxX);
            maxY = max(curr.second, maxY);
        }

        int w = maxX - minX + 2, h = maxY - minY + 3;
        cout << h << " " << w << "\n";
        char grid[h][w];

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                grid[i][j] = '#';
            }
        }

        for (pii p : path) {
            grid[p.second - minY + 1][p.first - abs(minX)] = '.';
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cout << grid[i][j];
            }
            cout << "\n";
        }
    }
}
