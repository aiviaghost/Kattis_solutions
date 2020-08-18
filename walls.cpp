#include <bits/stdc++.h>

using namespace std;

using pdd = pair<double, double>;

auto covered_points(pdd &crane, double &r, pdd midpoints[4]) -> vector<int> {
    vector<int> res;
    for (int i = 0; i < 4; i++) {
        if (hypot(abs(crane.first - midpoints[i].first), abs(crane.second - midpoints[i].second)) <= r) {
            res.push_back(i);
        }
    }
    return res;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    double l, w, n, r;
    cin >> l >> w >> n >> r;

    pdd midpoints[4] = {{l / 2.0, 0}, {-l / 2.0, 0}, {0, w / 2.0}, {0, -w / 2.0}};

    pdd cranes[(int) n];
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        cranes[i] = {x, y};
    }

    int tot_cranes = 5;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int m = 0; m < n; m++) {
                    vector<int> c1 = covered_points(cranes[i], r, midpoints), c2 = covered_points(cranes[j], r, midpoints), c3 = covered_points(cranes[k], r, midpoints), c4 = covered_points(cranes[m], r ,midpoints);
                    unordered_set<int> covered_walls;

                    // 1 crane
                    for (int c : c1) { 
                        covered_walls.emplace(c);
                    }
                    tot_cranes = (covered_walls.size() == 4 ? 1 : tot_cranes);

                    if (tot_cranes == 1) {
                        i = j = k = m = n;
                        break;
                    }

                    covered_walls.clear();

                    // 2 cranes
                    for (int c : c1) {
                        covered_walls.emplace(c);
                    }
                    for (int c : c2) {
                        covered_walls.emplace(c);
                    }
                    tot_cranes = (covered_walls.size() == 4 ? min(2, tot_cranes) : tot_cranes);

                    covered_walls.clear();

                    // 3 cranes
                    for (int c : c1) {
                        covered_walls.emplace(c);
                    }
                    for (int c : c2) {
                        covered_walls.emplace(c);
                    }
                    for (int c : c3) {
                        covered_walls.emplace(c);
                    }
                    tot_cranes = (covered_walls.size() == 4 ? min(3, tot_cranes) : tot_cranes);

                    covered_walls.clear();

                    // 4 cranes
                    for (int c : c1) {
                        covered_walls.emplace(c);
                    }
                    for (int c : c2) {
                        covered_walls.emplace(c);
                    }
                    for (int c : c3) {
                        covered_walls.emplace(c);
                    }
                    for (int c : c4) {
                        covered_walls.emplace(c);
                    }
                    tot_cranes = (covered_walls.size() == 4 ? min(4, tot_cranes) : tot_cranes);

                    covered_walls.clear();
                }
            }
        }
    }

    cout << (tot_cranes < 5 ? to_string(tot_cranes) : "Impossible") << "\n";
}
