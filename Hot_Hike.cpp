#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> temps(n);

    for (int i = 0; i < n; i++) {
        cin >> temps[i];
    }

    int index = 0, max_temp = 41;
    for (int i = 1; i < n - 1; i++) {
        if (max(temps[i - 1], temps[i + 1]) < max_temp) {
            max_temp = max(temps[i - 1], temps[i + 1]);
            index = i - 1;
        }
    }

    cout << index + 1 << " " << max_temp << "\n";

    return 0;
}
