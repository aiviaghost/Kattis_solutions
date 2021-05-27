#include <bits/stdc++.h>

using namespace std;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    cin.ignore();

    while (T--) {
        string input;
        getline(cin, input);

        list<char> out;
        bool at_end = true;
        int current_index = 0;

        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '[') {
                at_end = false;
                current_index = 0;
            }
            else if (input[i] == ']') {
                at_end = true;
                current_index = out.size();
            }
            else if (input[i] == '<') {
                if (at_end && !out.empty()) {
                    out.pop_back();
                    current_index--;
                }
                else if (!out.empty() && current_index > 0) {
                    list<char>::iterator itr = out.begin();
                    advance(itr, current_index - 1);
                    out.erase(itr);
                    current_index--;
                }
            }
            else if (at_end) {
                out.push_back(input[i]);
                current_index++;
            }
            else {
                list<char>::iterator itr = out.begin();
                advance(itr, current_index);
                out.insert(itr, input[i]);
                current_index++;
            }
        }

        for (list<char>::iterator itr = out.begin(); itr != out.end(); itr++) {
            cout << *itr;
        }
        cout << "\n";
    }

    return 0;
}
