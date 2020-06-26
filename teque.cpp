#include <bits/stdc++.h>

using namespace std;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    cin.ignore();

    deque<int> half_1, half_2;

    while (n--) {
        string command;
        getline(cin, command);

        int val = stoi(command.substr(command.find_first_of(" ") + 1));
        string op = command.substr(0, command.find_first_of(" "));

        if (op == "get") {
            if (val < half_1.size()) {
                cout << to_string(half_1[val]) << "\n";
            }
            else {
                cout << to_string(half_2[val - half_1.size()]) << "\n";
            }
        }
        else if (op == "push_front") {
            if (half_1.size() >= half_2.size() && !half_1.empty()) {
                half_2.push_front(half_1.back());
                half_1.pop_back();
                half_1.push_front(val);
            }
            else {
                half_1.push_front(val);
            }
        }
        else if (op == "push_back") {
            if (half_2.size() >= half_1.size() && !half_2.empty()) {
                half_1.push_back(half_2.front());
                half_2.pop_front();
                half_2.push_back(val);
            }
            else {
                half_2.push_back(val);
            }
        }
        else {
            if (half_1.size() < half_2.size()) {
                half_1.push_back(half_2.front());
                half_2.pop_front();
                half_2.push_front(val);
            }
            else if (half_1.size() == half_2.size()) {
                half_1.push_back(val);
            }
            else {
                half_2.push_front(val);
            }
        }
    }

    return 0;
}
