#include <bits/stdc++.h>

using namespace std;

#define umap unordered_map

bool is_bipartite = true;

auto dfs(umap<string, vector<string>> &adj, umap<string, int> &marks, string &item) -> void {
    for (string next : adj[item]) {
        if (marks[next] == -1) {
            marks[next] = 1 - marks[item];
            dfs(adj, marks, next);
        }
        else if (marks[item] == marks[next]) {
            is_bipartite = false;
            return;
        }
    }
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    umap<string, vector<string>> adj;
    int n;
    cin >> n;
    string items[n];
    for (int i = 0; i < n; i++) {
        string item;
        cin >> item;
        items[i] = item;
        adj[item] = {};
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string item1, item2;
        cin >> item1 >> item2;
        adj[item1].push_back(item2);
        adj[item2].push_back(item1);
    }

    umap<string, int> marks;
    for (string item : items) {
        marks[item] = -1;
    }

    for (string item : items) {
        if (marks[item] == -1) {
            marks[item] = 0;
            dfs(adj, marks, item);
        }
    }

    if (is_bipartite) {
        vector<string> walter, jesse;
        for (auto itr = marks.begin(); itr != marks.end(); itr++) {
            if (itr->second == 0) {
                walter.push_back(itr->first);
            }
            else {
                jesse.push_back(itr->first);
            }
        }

        if (!walter.empty()) {
            cout << walter.front();
            for (int i = 1; i < walter.size(); i++) {
                cout << " " << walter[i];
            }
            cout << "\n";
        }

        if (!jesse.empty()) {
            cout << jesse.front();
            for (int i = 1; i < jesse.size(); i++) {
                cout << " " << jesse[i];
            }
            cout << "\n";
        }
    }
    else {
        cout << "impossible\n";
    }
}
