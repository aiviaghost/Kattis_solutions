#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) { auto inner = make<T>(init, sizes...); return vector<decltype(inner)>(first, inner); }

const int INF = 2e9;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    
    int R, C, K;
    cin >> R >> C >> K;
    char grid[R][C];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    auto dist = make<int>(-1, K + 1, R, C);
    auto marked = make<bool>(false, K + 1, R, C); 
    auto steps = make<int>(-1, K + 1, R, C);
    steps[0][0][0] = K;

    pii neighbours[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    auto is_inside = [&](int &x, int &y) { return 0 <= x && x < C && 0 <= y && y < R; };

    for (int k = 0; k < K + 1; k++) {
        queue<pii> q;
        q.push({0, 0});
        dist[k][0][0] = 0;
        
        while (!q.empty()) {
            pii curr = q.front();
            q.pop();

            for (pii next : neighbours) {
                int nx = curr.first + next.first;
                int ny = curr.second + next.second;
                if (is_inside(nx, ny) && (dist[k][ny][nx] == -1 || dist[k][curr.second][curr.first] + 1 < dist[k][ny][nx] || marked[k][ny][nx])) {
                    if (grid[ny][nx] == '.') {
                        steps[k][ny][nx] = steps[k][curr.second][curr.first];
                        dist[k][ny][nx] = dist[k][curr.second][curr.first] + 1;
                        q.push({nx, ny});
                    }
                    else if (marked[k][ny][nx]) {
                        marked[k][ny][nx] = false;
                        if (k + 1 < K + 1) {
                            marked[k + 1][ny][nx] = true;
                            if (dist[k][curr.second][curr.first] + 1 < dist[k][ny][nx] || (dist[k][curr.second][curr.first] + 1 == dist[k][ny][nx] && steps[k][curr.second][curr.first] - 1 > steps[k][ny][nx])) {
                                dist[k + 1][ny][nx] = dist[k][curr.second][curr.first] + 1;
                                steps[k + 1][ny][nx] = steps[k][curr.second][curr.first] - 1;
                            }
                            else {
                                dist[k + 1][ny][nx] = dist[k][ny][nx];
                                steps[k + 1][ny][nx] = steps[k][ny][nx];
                            }
                        }
                        q.push({nx, ny});
                    }
                    else if (steps[k][curr.second][curr.first] > 0 && (dist[k][curr.second][curr.first] + 1 < dist[k + 1][ny][nx] || dist[k + 1][ny][nx] == -1)) {
                        dist[k + 1][ny][nx] = dist[k][curr.second][curr.first] + 1;
                        steps[k + 1][ny][nx] =  steps[k][curr.second][curr.first] - 1;
                        marked[k + 1][ny][nx] = true;
                    }
                }
            }
        }
    }
    
    cout << (dist[K][R - 1][C - 1] == -1 ? "nej" : to_string(dist[K][R - 1][C - 1])) << "\n";
}
