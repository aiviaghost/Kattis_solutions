#include <bits/stdc++.h>

using namespace std;

map<string, set<string>> L;
vector<string> path;
unordered_set<string> vis;

bool dfs(string &start, string &goal) {
    if (vis.find(start) != vis.end()) {
        return false;
    }    

    if (start == goal) {
        return true;
    }

    vis.emplace(start);

    for (auto s : L[start]) {
        if (dfs(s, goal)) {
            path.push_back(start);
            return true;
        }
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    cin.ignore();

    while (n--) {
        string s;
        getline(cin, s);

        vector<string> v;
        istringstream iss{s};
        for (string part; getline(iss, part, ' '); v.push_back(part));

        for (int i = 1; i < v.size(); i++) {
            L[v[0]].emplace(v[i]);
            L[v[i]].emplace(v[0]);
        }
    }

    string ab;
    getline(cin, ab);
    string start = ab.substr(0, ab.find(" "));
    string goal = ab.substr(ab.find(" ") + 1);

    if (dfs(start, goal)) {
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
        cout << goal << "\n";
    }
    else {
        cout << "no route found\n";
    }
    
    return 0;
}
