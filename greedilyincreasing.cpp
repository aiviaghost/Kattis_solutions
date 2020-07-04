#include <bits/stdc++.h>

using namespace std;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> GIS;
    int val;
    cin >> val;
    GIS.push_back(val);
    for (int i = 1; i < n; i++) {
        cin >> val;
        if (val > GIS.back()) {
            GIS.push_back(val);
        }
    }

    cout << GIS.size() << "\n";
    cout << GIS.front();
    for (int i = 1; i < GIS.size(); i++) {
        cout << " " << GIS[i];
    }
    cout << "\n";
}
