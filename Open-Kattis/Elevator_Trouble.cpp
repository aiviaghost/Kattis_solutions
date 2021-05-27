#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;

    vector<int> curr_layer, vis(f), dist(f, -1), neighbours = {u, -d};

    dist[s - 1] = 0;
    vis[s - 1] = 1;
    curr_layer.push_back(s - 1);

    auto is_inside = [&](int x) {
        return 0 <= x && x < f;
    };

    while (!curr_layer.empty()) {
        vector<int> next_layer;
        for (int c : curr_layer) {
            if (c == g - 1) {
                curr_layer.clear();
                next_layer.clear();
                break;
            }
            for (int n : neighbours) {
                int next = c + n;
                if (is_inside(next) && vis[next] != 1) {
                    vis[next] = 1;
                    dist[next] = dist[c] + 1;
                    next_layer.push_back(next);
                }
            }
        }
        curr_layer = next_layer;
    }

    cout << (dist[g - 1] == -1 ? "use the stairs" : to_string(dist[g - 1])) << "\n";

    return 0;
}
