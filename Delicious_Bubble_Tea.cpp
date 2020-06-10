#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> tea(n);
    for (int i = 0; i < n; i++) {
        cin >> tea[i];
    }

    int m;
    cin >> m;

    vector<int> topping(m);
    for (int i = 0; i < m; i++) {
        cin >> topping[i];
    }

    return 0;
}
