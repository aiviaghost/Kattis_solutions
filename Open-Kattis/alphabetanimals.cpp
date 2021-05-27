#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    string last_said;
    cin >> last_said;
    
    int n;
    cin >> n;
    cin.ignore();

    unordered_map<char, unordered_set<string>> seen;
    vector<string> possible;
    for (int i = 0; i < n; i++) {
        string not_used;
        cin >> not_used;
        if (not_used[0] == last_said.back()) {
            possible.push_back(not_used);
        }
        seen[not_used[0]].emplace(not_used);
    }

    if (possible.empty()) {
        cout << "?\n";
    }
    else {
        bool can_elim = false;
        string choice;
        for (string poss : possible) {
            if (seen.find(poss.back()) == seen.end() || (seen.find(poss.back()) != seen.end() && seen[poss.back()].size() == 1 && seen[poss.back()].find(poss) != seen[poss.back()].end())) {
                can_elim = true;
                choice = poss;
                choice += "!";
                break;
            }
        }
        cout << (can_elim ? choice : possible[0]) << "\n";
    }
}
