#include <bits/stdc++.h>

using namespace std;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    string line;
    regex regexp ("problem", regex_constants::icase);
    while (getline(cin, line)) {
        cout << (regex_search(line, regexp) ? "yes" : "no") << "\n";
    }
}
