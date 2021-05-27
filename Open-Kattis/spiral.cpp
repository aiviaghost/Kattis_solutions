#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using pii = pair<int, int>;
using pdd = pair<double, double>;

auto sieve(int &n) -> unordered_set<int> {
    bool is_prime[n + 1];
    memset(is_prime, 1, n + 1);

    for (int p = 2; p * p < n + 1; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < n + 1; i += p) {
                is_prime[i] = false;
            }
        }
    }

    unordered_set<int> primes;
    for (int i = 2; i < n + 1; i++) {
        if (is_prime[i]) {
            primes.emplace(i);
        }
    }

    return primes;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n = 10609;
    unordered_set<int> primes = sieve(n);
    pii grid[103][103];
    // fill "grid" with prime spiral

    int x = 51, y = 51, iteration_count = 0, v = 1, k = 1;
    while (v < n) {
        if (iteration_count % 4 == 0) {
            for (int i = x; i < x + k; i++) {
                grid[y][i] = {v, primes.find(v) != primes.end()};
                v++;
            }
            x = x + k;
        } 
        else if (iteration_count % 4 == 1) {
            for (int i = y; i > y - k; i--) {
                grid[i][x] = {v, primes.find(v) != primes.end()};
                v++;
            }
            y = y - k;
            k++;
        } 
        else if (iteration_count % 4 == 2) {
            for (int i = x; i > x - k; i--) {
                grid[y][i] = {v, primes.find(v) != primes.end()};
                v++;
            }
            x = x - k;
        } 
        else if (iteration_count % 4 == 3) {
            for (int i = y; i < y + k; i++) {
                grid[i][x] = {v, primes.find(v) != primes.end()};
                v++;
            }
            y = y + k;
            k++;
        }
        iteration_count++;
    }

    pii neighbours[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // query each pair
    int qx, qy, t = 1;
    while (cin >> qx >> qy) {
        int xr, xc, yr, yc;
        for (int i = 0; i < 103; i++) {
            for (int j = 0; j < 103; j++) {
                if (grid[i][j].first == qx) {
                    xr = i;
                    xc = j;
                }
                else if (grid[i][j].first == qy) {
                    yr = i;
                    yc = j;
                }
            }
        }

        int dist[103][103];
        memset(dist, -1, 4 * n);
        dist[xr][xc] = 0;
        queue<pii> q;
        q.push({xc, xr});

        while (!q.empty()) {
            pii curr = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = curr.first + neighbours[i].first;
                int ny = curr.second + neighbours[i].second;
                if (0 <= nx && nx < 103 && 0 <= ny && ny < 103 && dist[ny][nx] == -1 && !grid[ny][nx].second) {
                    dist[ny][nx] = dist[curr.second][curr.first] + 1;
                    q.push({nx, ny});
                }
            }
        }

        cout << "Case " << t << ": " << (dist[yr][yc] != -1 ? to_string(dist[yr][yc]) : "impossible") << "\n";
        t++;
    }
}
