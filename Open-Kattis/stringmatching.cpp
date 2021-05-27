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

auto KMP(const string &text, const string &pattern) -> vector<int> {
    int n = text.size(), m = pattern.size();

    int* T = compute_T(pattern);
    vector<int> indices;

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == m) {
                indices.push_back(i - j);
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

    return indices;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    string pattern, text;
    while (getline(cin, pattern) && getline(cin, text)) {
        vector<int> indices = KMP(text, pattern);
        if (indices.empty()) {
            cout << "\n";
        }
        else {
            cout << indices.front();
            for (int i = 1; i < indices.size(); i++) {
                cout << " " << indices[i];
            }
            cout << "\n";
        }
    }
}
