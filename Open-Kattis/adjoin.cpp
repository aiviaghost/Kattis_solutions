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

vector<int> dist, total;
vector<bool> vis_tree;

int furthest_from(vector<vector<int>>& adj, int s) {
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    vis_tree[s] = true;
    int furthest = s, max_dist = -INF;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int next : adj[curr]) {
            if (!vis_tree[next]) {
                vis_tree[next] = true;
                dist[next] = dist[curr] + 1;
                if (dist[next] > max_dist) {
                    max_dist = dist[next];
                    furthest = next;
                }
                q.push(next);
            }
        }
    }
    return furthest;
}

void find_center(vector<vector<int>>& adj, int s) {
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    unordered_set<int> vis;
    vis.emplace(s);
    int max_dist = -INF;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int next : adj[curr]) {
            if (vis.find(next) == vis.end()) {
                vis.emplace(next);
                dist[next] = dist[curr] + 1;
                if (dist[next] > max_dist) {
                    max_dist = dist[next];
                }
                q.push(next);
            }
        }
    }
    total.push_back(max_dist);
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int c, l;
    cin >> c >> l;
    vector<vector<int>> adj(c);
    dist.resize(c, -1);
    vis_tree.resize(c);
    total.resize(c);
    for (int i = 0; i < l; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < c; i++) {
        if (!vis_tree[i]) {
            int furthest = furthest_from(adj, i);
            find_center(adj, furthest);
        }
    }
    sort(total.begin(), total.end(), greater<int>());
    int longest_path = total[0];
    for (int i = 1; i < total.size(); i++) {
        int d1 = (total[i] / 2) + ((total[i] & 1) == 1), d2 = (longest_path / 2) + ((longest_path & 1) == 1);
        longest_path = max({d1 + d2 + 1, total[i], longest_path});
    }
    cout << longest_path << "\n";
}
