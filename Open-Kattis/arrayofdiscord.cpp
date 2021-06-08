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
    cin.ignore();
    string nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    auto minify = [&] (string &s) {
        if (s.length() == 1) {
            return 0LL;
        }

        string out = "1";
        for (int i = 1; i < s.length(); i++) {
            out += s[i];
        }
        return stoll(out);
    };

    auto largify = [&] (string &s) {
        string out = "9";
        for (int i = 1; i < s.length(); i++) {
            out += s[i];
        }
        return stoll(out);
    };


    bool possible = false;
    for (int i = 0; i < n; i++) {
        ll small = minify(nums[i]);
        ll large = largify(nums[i]);
        if (i - 1 >= 0 && stoll(nums[i - 1]) > small) {
            possible = true;
            nums[i] = to_string(small);
            break;
        }

        if (i + 1 < n && stoll(nums[i + 1]) < large) {
            possible = true;
            nums[i] = to_string(large);
            break;
        }
    }

    if (possible) {
        cout << nums[0];
        for (int i = 1; i < n; i++) {
            cout << " " << nums[i];
        }
        cout << "\n";
    }
    else {
        cout << "impossible\n";
    }
}
