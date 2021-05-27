#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto calculate_routers_needed(vector<int> &house_nums, int &max_dist) -> int {
    int routers_needed = 0;
    int curr_router_pos = -1;
    for (int house_num : house_nums) {
        if (curr_router_pos < house_num) {
            routers_needed++;
            curr_router_pos = house_num + max_dist;
        }
    }
    return routers_needed;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(1);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> house_nums(m);
        for (int i = 0; i < m; i++) {
            cin >> house_nums[i];
        }
        sort(house_nums.begin(), house_nums.end());

        int lb = 0, rb = 1000000, max_dist;
        while (rb - lb > 0) {
            max_dist = lb + (rb - lb) / 2;
            int routers_needed = calculate_routers_needed(house_nums, max_dist);
            if (routers_needed > n) {
                lb = max_dist + 1;
            }
            else {
                rb = max_dist;
            }
        }

        cout << lb / 2.0 << "\n";
    }
}
