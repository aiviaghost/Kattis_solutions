#include <bits/stdc++.h>

using namespace std;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    string pattern, text;
    while (getline(cin, pattern) && getline(cin, text)) {
        // generate search table (KMP)
        int pos = 1, cnd = 0;
        vector<int> T(text.length());
        T[0] = -1;

        while (pos < text.length()) {
            if (text[pos] == text[cnd]) {
                T[pos] = T[cnd];
            }
            else {
                T[pos] = cnd;
                cnd = T[cnd];
                while (cnd >= 0 && text[pos] != text[cnd]) {
                    cnd = T[cnd];
                }
            }
            pos++;
            cnd++;
        }
        T[pos] = cnd;

        // run KMP algo
        vector<int> P;
        int i = 0, j = 0;

        while (i < text.length()) {
            if (pattern[j] == text[i]) {
                i++;
                j++;
                if (j == pattern.length()) {
                    P.push_back(i - j);
                    j = T[j];
                }
            }
            else {
                j = T[j];
                if (j < 0) {
                    i++;
                    j++;
                }
            }
        }

        if (P.empty()) {
            cout << "\n";
        }
        else {
            cout << P.front();
            for (i = 1; i < P.size(); i++) {
                cout << " " << P[i];
            }
            cout << "\n";
        }
    }
}
