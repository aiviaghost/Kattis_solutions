#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using pii = pair<int, int>;
using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int p;
    while (cin >> p) {
        vector<int> divs, temp;
        for (int d = 1; d * d <= p; d++) {
            if (p % d == 0) {
                if (p / d != d) {
                    temp.push_back(p / d);
                }
                divs.push_back(d);
            }
        }
        for (int i = temp.size() - 1; i >= 1; i--) {
            divs.push_back(temp[i]);
        }

        int sum = 0;
        for (int d : divs) {
            sum += d;
        }
        
        if (sum == p) {
            cout << p << " perfect\n";
        }
        else if (abs(sum - p) <= 2) {
            cout << p << " almost perfect\n";
        }
        else {
            cout << p << " not perfect\n";
        }
    }
}
