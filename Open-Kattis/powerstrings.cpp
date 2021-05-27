#include <bits/stdc++.h>

using namespace std;

auto compute_T(const string &pattern) -> int* {
    int m = pattern.size();
    int *T = new int[m + 1];

    if (0 <= m) {
        T[0] = 0;
    }

    if (1 <= m) {
        T[1] = 0;
    }

    for (int i = 2; i <= m; i++) {
        for (int j = T[i - 1] ;; j = T[j]) {
            if (pattern[j] == pattern[i - 1]) {
                T[i] = j + 1;
                break;
            }

            if (j == 0) {
                T[i] = 0;
                break;
            }
        }
    }

    return T;
}

auto KMP(const string &text, const string &pattern) -> int {
    int n = text.length(), m = pattern.length();

    int* T = compute_T(pattern);
    int matches = 0;
    int last_match = -1;

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == m) {
                if (last_match == -1 || i - j == last_match + m) {
                    last_match = i - j;
                    matches++;
                }
                else {
                    delete[] T;
                    return matches;
                }
            }
            else if (i - j > last_match + m) {
                delete[] T;
                return matches;
            }
        }
        else if (j > 0) {
            j = T[j];
        }
        else {
            i++;
        }
    }

    delete[] T;
    return matches;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    string word;
    while (getline(cin, word)) {
        if (word == ".") {
            break;
        }

        int n = word.length();

        vector<int> divs, temp;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (i != n / i) {
                    temp.push_back(i);
                }
                divs.push_back(n / i);
            }
        }
        for (int i = temp.size() - 1; i >= 0; i--) {
            divs.push_back(temp[i]);
        }

        int res;
        for (int div : divs) {
            string pattern = word.substr(0, n / div);
            if (KMP(word, pattern) == div) {
                res = div;
                break;
            }
        }

        cout << res << "\n";
    }
}
