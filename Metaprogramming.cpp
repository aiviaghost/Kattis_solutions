#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    unordered_map<string, int> lookup;

    string command, x, op, y;
    int value;
    while (cin >> command) {
        if (command == "eval") {
            cin >> x >> op >> y;

            if (lookup.find(x) == lookup.end() || lookup.find(y) == lookup.end()) {
                cout << "undefined";
            }
            else if (op == "<") {
                cout << (lookup.at(x) < lookup.at(y) ? "true" : "false");
            }
            else if (op == ">") {
                cout << (lookup.at(x) > lookup.at(y) ? "true" : "false");
            }
            else {
                cout << (lookup.at(x) == lookup.at(y) ? "true" : "false");
            }

            cout << "\n";
        }
        else {
            cin >> value >> x;

            if (lookup.find(x) != lookup.end()) {
                lookup.at(x) = value;
            }
            else {
                lookup.emplace(x, value);
            }
        }
    }

    return 0;
}
