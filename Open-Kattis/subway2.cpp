#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

#define walking_speed 1e4
#define subway_speed 4e4

struct edge {
    pii to;
    double w;
};

auto main() -> int {
    // cin.tie(0)->sync_with_stdio(0);
    
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    pii sp = {x1, y1}, ep = {x2, y2};
    map<pii, vector<edge>> adj;
    vector<pii> nodes, subway_line;
    while (scanf("%d%d", &x1, &y1) != EOF) { // link subway lines together
        if (x1 != -1 && y1 != -1) {
            subway_line.push_back({x1, y1});
        }
        else {
            for (pii station : subway_line) {
                for (pii node : nodes) {
                    adj[station].push_back({node, walking_speed});
                    adj[node].push_back({station, walking_speed});
                }
            }

            for (pii station : subway_line) {
                nodes.push_back(station);
            }

            for (int i = 0; i < subway_line.size() - 1; i++) {
                adj[subway_line[i]].push_back({subway_line[i + 1], subway_speed});
                adj[subway_line[i + 1]].push_back({subway_line[i], subway_speed});
            }

            for (int i = 0; i < subway_line.size() - 1; i++) {
                for (int j = i + 1; j < subway_line.size(); j++) {
                    adj[subway_line[i]].push_back({subway_line[j], walking_speed});
                    adj[subway_line[j]].push_back({subway_line[i], walking_speed});
                }
            }

            subway_line.clear();
        }
    }

    for (pii node : nodes) {
        adj[sp].push_back({node, walking_speed});
        adj[node].push_back({sp, walking_speed});
        adj[ep].push_back({node, walking_speed});
        adj[node].push_back({ep, walking_speed});
    }
    adj[sp].push_back({ep, walking_speed});
    
    map<pii, double> time;
    for (pii node : nodes) {
        time[node] = INF;
    }
    time[sp] = 0;
    time[ep] = INF;

    priority_queue<pair<double, pii>, vector<pair<double, pii>>, greater<pair<double, pii>>> pq;
    pq.push({0, sp});
    set<pii> vis;
    while (!pq.empty()) {
        pair<double, pii> curr = pq.top();
        pq.pop();
        if (vis.find(curr.second) != vis.end()) {
            continue;
        }
        vis.emplace(curr.second);
        for (edge next : adj[curr.second]) {
            double alt_time = time[curr.second] + hypot(abs((double) (curr.second.first - next.to.first)), abs((double) (curr.second.second - next.to.second))) / (next.w / 60.0);
            if (alt_time < time[next.to]) {
                time[next.to] = alt_time;
                pq.push({alt_time, next.to});
            }
        }
    }

    printf("%d\n", (int) round(time[ep]));
}
