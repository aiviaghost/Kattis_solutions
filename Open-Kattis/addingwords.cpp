#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using pii = pair<int, int>;
using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    unordered_map<string, int> mem;

    string line;
    while (getline(cin, line)) {
        vector<string> cmds;
        istringstream iss{line};
        for (string part ; getline(iss, part, ' '); cmds.push_back(part));

        if (cmds[0] == "def") {
            mem[cmds[1]] = stoi(cmds[2]);
        }
        else if (cmds[0] == "calc") {
            int sum = 0;
            bool vars_are_known = true, sum_is_known = false;
            
            if (mem.find(cmds[1]) != mem.end()) {
                sum += mem[cmds[1]];
            }
            else {
                vars_are_known = false;
            }

            for (int i = 2; i < cmds.size() - 1; i += 2) {
                if (mem.find(cmds[i + 1]) == mem.end()) {
                    vars_are_known = false;
                    break;
                }

                if (cmds[i] == "+") {
                    sum += mem[cmds[i + 1]];
                }
                else {
                    sum -= mem[cmds[i + 1]];
                }
            }

            string sum_word;
            for (auto itr = mem.begin(); itr != mem.end(); itr++) {
                if (itr->second == sum) {
                    sum_word = itr->first;
                    sum_is_known = true;
                }
            }
            
            for (int i = 1; i < cmds.size(); i++) {
                cout << cmds[i] << " ";
            }
            cout << (vars_are_known && sum_is_known ? sum_word : "unknown") << "\n";
        }
        else {
            mem.clear();
        }
    }
}
