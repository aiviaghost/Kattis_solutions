#include <bits/stdc++.h>

using namespace std;

struct shield {
    int lower_bound, upper_bound;
    double factor;
};

struct lower_bound_comparator {
    inline bool operator() (const shield &s1, const shield &s2) {
        return s1.lower_bound < s2.lower_bound;
    }
};

auto end_x(int &fy, vector<shield> &shields, double &init_v) -> double {
    double curr_x = 0, curr_y = 0;

    for (shield s : shields) {
        if (curr_y < s.lower_bound) {
            int t = s.lower_bound - curr_y;
            curr_x += init_v * t;
            curr_y = s.lower_bound;
        }

        int t = s.upper_bound - s.lower_bound;
        curr_x += init_v * s.factor * t;
        curr_y = s.upper_bound;
    }

    if (curr_y < fy) {
        int t = fy - curr_y;
        curr_x += init_v * t;
    }

    return curr_x;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(11);

    int fx, fy;
    cin >> fx >> fy;

    int n;
    cin >> n;

    vector<shield> shields(n);
    for (int i = 0; i < n; i++) {
        int lower_bound, upper_bound;
        double factor;
        cin >> lower_bound >> upper_bound >> factor;
        shields[i] = {lower_bound, upper_bound, factor};
    }
    sort(shields.begin(), shields.end(), lower_bound_comparator());

    double l = -1e9, r = 1e9, mid;
    while (r - l > 1e-7) {
        mid = l + (r - l) / 2;
        if (end_x(fy, shields, mid) > fx) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    cout << mid << "\n";
}
