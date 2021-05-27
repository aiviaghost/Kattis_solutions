#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, p, m;
    cin >> n >> p >> m;

    cin.ignore();

    unordered_map<string, int> score_count;
    while (n--) {
        string s;
        getline(cin, s);
        score_count.emplace(s, 0);
    }

    unordered_set<string> seen;
    vector<string> winners;
    while (m--) {
        string s;
        getline(cin, s);
        string name = s.substr(0, s.find_first_of(" "));
        score_count.at(name) += stoi(s.substr(s.find_first_of(" ") + 1));
        
        if (seen.find(name) == seen.end() && score_count.at(name) >= p) {
            winners.push_back(name);
            seen.emplace(name);
        }
    }

    if (winners.empty()) {
        cout << "No winner!\n";
    }
    else {
        for (string name : winners) {
            cout << name << " wins!\n";
        }
    }

    return 0;
}
