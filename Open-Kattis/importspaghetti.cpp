#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto string_to_vector(string &s) -> vector<string> {
    vector<string> out;
    istringstream iss{s};
    for (string part, i = "0"; getline(iss, part, ' '); i = to_string(stoi(i) + 1)) { // now that's a for loop
        if (part.back() == ',') {
            part.pop_back();
        }
        if (stoi(i) > 0) {
            out.push_back(part);
        }
    }
    return out;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    cin.ignore();

    string files[n];
    for (int i = 0; i < n; i++) {
        cin >> files[i];
    }
    cin.ignore();
    unordered_map<string, vector<string>> adj;
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        int import_count = stoi(string_to_vector(s)[0]);
        for (int j = 0; j < import_count; j++) {
            string imports;
            getline(cin, imports);
            for (string import : string_to_vector(imports)) {
                adj[files[i]].push_back(import);
            }
        }
    }

    bool ship_it = true;
    vector<string> cycle;
    for (int i = 0; i < n; i++) {
        string start = files[i];
        vector<string> curr_layer{start};
        unordered_map<string, string> parent;
        unordered_map<string, int> dist;
        for (int i = 0; i < n; i++) { dist[files[i]] = -1; }
        dist[start] = 0;
        bool has_cycle = false;
        while (!curr_layer.empty()) {
            vector<string> next_layer;
            for (string curr : curr_layer) {
                for (string next : adj[curr]) {
                    if (dist[next] == -1) {
                        dist[next] = dist[curr] + 1;
                        next_layer.push_back(next);
                        parent[next] = curr;
                    }
                    else if (next == start && (dist[curr] + 1 < dist[start] || !has_cycle)) {
                        dist[next] = dist[curr] + 1;
                        has_cycle = true;
                        parent[next] = curr;
                    }
                }
            }
            curr_layer = next_layer;
        }

        if (has_cycle && (ship_it || dist[start] < cycle.size())) {
            cycle.clear();
            ship_it = false;
            string curr = parent[start];
            while (curr != start) {
                cycle.push_back(curr);
                curr = parent[curr];
            }
            cycle.push_back(start);
            reverse(cycle.begin(), cycle.end());
        }
    }

    if (!ship_it) {
        cout << cycle.front();
        for (int i = 1; i < cycle.size(); i++) {
            cout << " " << cycle[i];
        }
    }
    else {
        cout << "SHIP IT";
    }
    cout << "\n";
}
