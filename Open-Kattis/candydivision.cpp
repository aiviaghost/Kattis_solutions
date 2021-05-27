#include <bits/stdc++.h>

using namespace std;

using ll = long long;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<ll> divs, temp;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i != n / i) {
                temp.push_back(n / i);
            }
            divs.push_back(i);
        }
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
        divs.push_back(temp[i]);
    }

    cout << divs.front() - 1;
    for (int i = 1; i < divs.size(); i++) {
        cout << " " << divs[i] - 1;
    }
    cout << "\n";
}
