#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using pii = pair<int, int>;
using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, h, l;
    cin >> n >> h >> l;

    int horror_movies[h];
    for (int i = 0; i < h; i++) {
        int xi;
        cin >> xi;
        horror_movies[i] = xi;
    }

    vector<int> adj[n];
    while (l--) {
        int ai, bi;
        cin >> ai >> bi;
        adj[ai].push_back(bi);
        adj[bi].push_back(ai);
    }

    int dist[n];
    memset(dist, -1, 4 * n);
    for (int i = 0; i < h; i++) {
        dist[horror_movies[i]] = 0;
        queue<int> q;
        q.push(horror_movies[i]);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next : adj[curr]) {
                if (dist[next] == -1 || dist[next] > dist[curr] + 1) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }
    }

    int id = -1, max_hi = -1;
    for (int i = 0; i < n; i++) {
        if (dist[i] > max_hi) {
            max_hi = dist[i];
            id = i;
        }
        else if (dist[i] == -1) {
            id = i;
            break;
        }
    }
    cout << id << "\n";
}
