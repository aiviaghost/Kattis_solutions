#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    unordered_map<string, set<string>> adj;
    unordered_map<string, int> dist;
    vector<string> order;
    string in;
    while (getline(cin, in)) {
        vector<string> v;
        istringstream iss{in};
        for (string part; getline(iss, part, ' '); v.push_back(part));
        order.push_back(v[0]);
        for (int i = 1; i < v.size(); i++) {
            adj[v[0]].emplace(v[i]);
            adj[v[i]].emplace(v[0]);

            dist[v[0]] = -1;
            dist[v[i]] = -1;
        }
    }
    
    vector<string> curr_layer{"PAUL_ERDOS"};
    dist.at("PAUL_ERDOS") = 0;
    unordered_set<string> vis{"PAUL_ERDOS"};

    while (!curr_layer.empty()) {
        vector<string> next_layer;
        for (string c : curr_layer) {
            for (auto n : adj[c]) {
                if (vis.find(n) == vis.end()) {
                    vis.emplace(n);
                    dist.at(n) = dist.at(c) + 1;
                    next_layer.push_back(n);
                }
            }
        }
        curr_layer = next_layer;
    }

    for (string s : order) {
        cout << s << " " << (dist.at(s) != -1 ? to_string(dist.at(s)) : "no-connection") << "\n";
    }
    
    return 0;
}
