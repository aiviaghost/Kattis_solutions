#include <bits/stdc++.h>

using namespace std;

void solve(vector<pair<int, int>> &coords) {
    double area = 0;
    int s = coords.size();

    for (int i = 0; i < s; i++) {
        area += coords[i].first * coords[(i + 1) % s].second - coords[i].second * coords[(i + 1) % s].first;
    }

    cout << (area < 0 ? "CW " : "CCW ") << abs(area) / 2.0 << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(1);
    
    int n, x, y;
    while (cin >> n) {
        if (n == 0)
            break;
        
        vector<pair<int, int>> coords;
        while (n--) {
            cin >> x >> y;
            coords.push_back({x, y});
        }
        solve(coords);
    }

    return 0;
}
