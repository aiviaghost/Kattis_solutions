#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

const int INF = 2e9;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    cin.ignore();

    int mid = 7;

    vector<int> upper_teeth(16, 1), lower_teeth(16, 1);

    for (int i = 0; i < n; i++) {
        string pos;
        char cond;
        cin >> pos >> cond;

        int act_pos;
        if (pos[0] == '-') {
            act_pos = mid + (pos[1] - '0');
            lower_teeth[act_pos] = (cond == 'm' ? 0 : -1e4);
        }
        else if (pos[0] == '+') {
            act_pos = mid + (pos[1] - '0');
            upper_teeth[act_pos] = (cond == 'm' ? 0 : -1e4);
        }
        else if (pos[1] == '-') {
            act_pos = mid - (pos[0] - '0' - 1);
            lower_teeth[act_pos] = (cond == 'm' ? 0 : -1e4);
        }
        else if (pos[1] == '+') {
            act_pos = mid - (pos[0] - '0' - 1);
            upper_teeth[act_pos] = (cond == 'm' ? 0 : -1e4);
        }
    }

    bool left_upper, right_upper, left_lower, right_lower;

    int sum = 0;
    for (int i = 0; i <= mid; i++) {
        sum += upper_teeth[i];
    }
    right_upper = sum > 0;

    sum = 0;
    for (int i = mid + 1; i < 16; i++) {
        sum += upper_teeth[i];
    }
    left_upper = sum > 0;

    sum = 0;
    for (int i = 0; i <= mid; i++) {
        sum += lower_teeth[i];
    }
    right_lower = sum > 0;

    sum = 0;
    for (int i = mid + 1; i < 16; i++) {
        sum += lower_teeth[i];
    }
    left_lower = sum > 0;

    if (left_lower && left_upper) {
        cout << "0";
    }
    else if (right_lower && right_upper) {
        cout << "1";
    }
    else {
        cout << "2";
    }
    cout << "\n";
}
