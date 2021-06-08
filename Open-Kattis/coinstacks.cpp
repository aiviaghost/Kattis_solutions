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
    vector<pii> order;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a > 0) order.push_back({a, i + 1});
    }
    
    vector<pii> moves;
    while (order.size() >= 2) {
        sort(order.begin(), order.end());
        moves.push_back({order.front().second, order.back().second});
        
        order.front().first--;
        if (order.front().first == 0) { order.erase(order.begin()); }

        order.back().first--;
        if (order.back().first == 0) { order.pop_back(); }
    }

    if (order.empty()) {
        cout << "yes\n";
        for (pii move : moves) {
            cout << move.first << " " << move.second << "\n";
        }
    }
    else {
        cout << "no\n";
    }
}