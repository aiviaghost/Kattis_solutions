#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto eat_pie(int &f, vector<double> pies, double &volume) -> double {
    int pies_eaten = 0;
    for (double &pie : pies) {
        if (pies_eaten == f || pie < volume) {
            break;
        }
        while (pie >= volume) {
            pie -= volume;
            pies_eaten++;
        }
    }

    double leftover = 0;
    for (double pie : pies) {
        leftover += pie;
    }

    if (pies_eaten < f) {
        return -1;
    }
    else  {
        return 1;
    }
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(9);

    int T;
    cin >> T;
    while (T--) {
        int n, f;
        cin >> n >> f;
        f++;
        vector<double> pies(n);
        double largest_pie = -1;
        for (int i = 0; i < n; i++) {
            int r;
            cin >> r;
            pies[i] = M_PI * r * r;
            largest_pie = max(pies[i], largest_pie);
        }
        
        sort(pies.begin(), pies.end(), greater<double>());

        double lb = 0, rb = largest_pie, mid;
        while (rb - lb > 1e-6) {
            mid = (lb + rb) / 2.0;
            double pie_left = eat_pie(f, pies, mid);
            // cout << "lb: " << lb << ", rb: " << rb << ", mid: " << mid << ", leftover: " << pie_left << endl;
            if (pie_left > 0) {
                lb = mid;
            }
            else if (pie_left < 0) {
                rb = mid;
            }
        }

        cout << lb << "\n";
    }
}
