#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    int diff = n - m;

    if (diff == -1) {
        cout << "Dr. Chaz will have 1 piece of chicken left over!";
    }
    else if (diff == 1) {
        cout << "Dr. Chaz needs 1 more piece of chicken!";
    }
    else if (diff > 0) {
        cout << "Dr. Chaz needs " << diff << " more pieces of chicken!";
    }
    else {
        cout << "Dr. Chaz will have " << abs(diff) << " pieces of chicken left over!";
    }

    cout << "\n";

    return 0;
}
