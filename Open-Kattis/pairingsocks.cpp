#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    stack<int> p1, p2;
    for (int i = 0; i < 2 * n; i++) {
        int sock;
        cin >> sock;
        p1.push(sock);
    }

    int ops = 0;
    while (!p1.empty()) {
        if (!p2.empty() && p1.top() == p2.top()) {
            p1.pop();
            p2.pop();
            ops++;
            continue;
        }

        p2.push(p1.top());
        p1.pop();
        ops++;
    }

    cout << (p1.empty() && p2.empty() ? to_string(ops) : "impossible") << "\n";
}
