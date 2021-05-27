#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> valid(n, 1);

    int max_val = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < max_val) {
            valid[i] = 0;
        }
        max_val = max(max_val, arr[i]);
    }

    int min_val = n + 1;
    for (int i = n - 1; i >= 0; i--) {
        if (valid[i] == 1 && arr[i] > min_val) {
            valid[i] = 0;
        }
        min_val = min(min_val, arr[i]);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (valid[i] == 1) {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}
