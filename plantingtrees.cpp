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
    vector<int> trees(n);
    for (int i = 0; i < n; i++) {
        cin >> trees[i];
    }
    sort(trees.begin(), trees.end(), greater<int>());

    int final_day = 0, curr = 1;
    for (int t : trees) {
        final_day = max(t + curr, final_day);
        curr++;
    }

    cout << final_day + 1 << "\n";
}
