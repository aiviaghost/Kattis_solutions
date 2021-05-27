#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int l, r;
    cin >> l >> r;

    if (l == r && l > 0) {
        cout << "Even " << (l + r);
    }
    else if (l > 0 || r > 0) {
        cout << "Odd " << 2 * max(l, r);
    }
    else {
        cout << "Not a moose";
    }
    cout << "\n";

    return 0;
}
