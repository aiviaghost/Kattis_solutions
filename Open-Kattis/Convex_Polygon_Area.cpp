#include <bits/stdc++.h>

using namespace std;

void area(vector<pair<int, int>> &coords) {
    double area = 0;
    int s = coords.size();
    for (int i = 0; i < s; i++) {
        area += (coords[i].first * coords[(i + 1) % s].second) - (coords[(i + 1) % s].first * coords[i].second);
    }
    cout << abs(area) / 2 << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n;
    
    while (n--) {
        cin >> m;
        vector<pair<int, int>> coords;
        while (m--) {
            int x, y;
            cin >> x >> y;
            coords.push_back({x, y});
        }
        area(coords);
    }

    return 0;
}
