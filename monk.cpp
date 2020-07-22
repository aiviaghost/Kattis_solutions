#include <bits/stdc++.h>

using namespace std;

// linear function from coordinate pair, return function evaluated at "mid"
auto height(double x1, double y1, double x2, double y2, double &mid) -> double {
    double k = (y2 - y1) / (x2 - x1);
    double m = y1 - k * x1;
    return k * mid + m;
}

// find closest end points to mid and run "height()" with the found end points
auto height_at_mid(unordered_map<int, int> &path, double mid) -> double {
    int left_end_point = floor(mid), right_end_point = left_end_point + 1;
    while (path.find(left_end_point) == path.end()) {
        left_end_point--;
    }
    while (path.find(right_end_point) == path.end()) {
        right_end_point++;
    }
    return height(left_end_point, path[left_end_point], right_end_point, path[right_end_point], mid);
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(6);

    int a, d;
    cin >> a >> d;

    unordered_map<int, int> up_path, down_path;
    int curr_t = 0, curr_h = 0;
    while (a--) {
        int h, t;
        cin >> h >> t;

        up_path[curr_t] = curr_h;
        curr_t += t;
        curr_h += h;
        up_path[curr_t] = curr_h;
    }

    curr_t = 0;
    while (d--) {
        int h, t;
        cin >> h >> t;

        down_path[curr_t] = curr_h;
        curr_t += t;
        curr_h -= h;
        down_path[curr_t] = curr_h;
    }

    // initial binary-search
    double l = 0, r = curr_t, mid;
    while (r - l > 1e-6) {
        mid = l + (r - l) / 2;

        double up_height = height_at_mid(up_path, mid);
        double down_height = height_at_mid(down_path, mid);

        if (up_height == down_height) {
            break;
        }
        else if (up_height > down_height) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    // binary-search to to find first point with same heigth (if paths overlap at more than one point)
    if (height_at_mid(up_path, floor(mid)) == height_at_mid(down_path, floor(mid)) || (floor(mid) == mid && height_at_mid(up_path, mid - 1) == height_at_mid(down_path, mid - 1))) {
        // find initial left and right bounds
        int up_l = floor(mid), up_r = up_l + 1;
        while (down_path.find(up_l) == down_path.end()) {
            up_l--;
        }
        while (down_path.find(up_r) == down_path.end()) {
            up_r++;
        }

        int down_l = floor(mid), down_r = down_l + 1;
        while (down_path.find(down_l) == down_path.end()) {
            down_l--;
        }
        while (down_path.find(down_r) == down_path.end()) {
           down_r++;
        }

        l = max(up_l, down_l), r = min(up_r, down_r); // minimize search space
        while (r - l > 1e-6) {
            mid = l + (r - l) / 2;

            double up_height = height_at_mid(up_path, mid);
            double down_height = height_at_mid(down_path, mid);

            if (up_height == down_height) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
    }

    cout << mid << "\n";
}
