#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int x, available;
    cin >> available;
    x = available;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        available += x;
        available -= p;
    }

    cout << available << "\n";

    return 0;
}
