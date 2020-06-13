#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &list, int &query) {
    int min_diff = 1e8;
    int closest = 1e8;
    for (int i = 0; i < list.size(); i++) {
        int diff = abs(list[i] - query);
        if (diff < min_diff) {
            min_diff = diff;
            closest = list[i];
        }
    }
    return closest;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, t = 0;
    while (cin >> n) {
        t++;
        cout << "Case " << t << ":\n";

        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        unordered_set<int> seen;
        vector<int> pairs;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = nums[i] + nums[j];
                if (seen.find(sum) == seen.end()) {
                    pairs.push_back(sum);
                    seen.emplace(sum);
                }
            }
        }
        sort(pairs.begin(), pairs.begin() + pairs.size());

        int m, query;
        cin >> m;
        while (m--) {
            cin >> query;
            cout << "Closest sum to " << query << " is " << solve(pairs, query) << ".\n";
        }
    }

    return 0;
}
