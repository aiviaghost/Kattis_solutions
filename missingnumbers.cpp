#include <bits/stdc++.h>

using namespace std;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<bool> said(201);
    int last_number = -1;
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        said[number] = true;

        if (i == n - 1) {
            last_number = number;
        }
    }

    vector<int> missed;
    for (int i = 1; i < last_number; i++) {
        if (!said[i]) {
            missed.push_back(i);
        }
    }

    if (missed.empty()) {
        cout << "good job\n";
    }
    else {
        for (int m : missed) {
            cout << m << "\n";
        }
    }

    return 0;
}
