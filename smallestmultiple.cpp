#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using pii = pair<int, int>;
using pdd = pair<double, double>;

auto LCM(long long a, long long b) -> long long {
    return a * b / __gcd(a, b);
}

struct segment_tree {
    long long lb, rb, val, lcm;
    segment_tree *left, *right;
    
    segment_tree(vector<int> nums, long long lb, long long rb) : lb(lb), rb(rb), left(NULL), right(NULL) {
        if (lb + 1 == rb) {
            lcm = val = nums[lb];
        }
        else {
            int mid = lb + (rb - lb) / 2;
            left = new segment_tree(nums, lb, mid);
            right = new segment_tree(nums, mid, rb);
            lcm = LCM(left->lcm, right->lcm);
        }
    }
};

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    string line;
    while (getline(cin, line)) {
        vector<int> nums;
        istringstream iss{line};
        for (string part; getline(iss, part, ' '); nums.push_back(stoi(part)));
        segment_tree* seg_tree = new segment_tree(nums, 0, nums.size());
        cout << seg_tree->lcm << "\n";
    }
}
