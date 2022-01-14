#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

const int INF = 2e9;
const int MOD = 1e9 + 7;

const double LEN = 1e5;
const double EPS = 1e-6;

inline double W(double r, double a, double b) {
    return M_PI * (r * r * (b - a) - ((b * b * b - a * a * a) / 3));
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(9);

    int n, s;
    cin >> n >> s;
    vector<pdd> holes(n);
    for (int i = 0; i < n; i++) {
        double r, x, y, z;
        cin >> r >> x >> y >> z;
        holes[i] = {z, r};
    }
    double total_hole_volume = 0;
    for (pdd hole : holes) {
        total_hole_volume += W(hole.second, -hole.second, hole.second);
    }
    auto tot_W = [&](double cut) {
        double w = pow(LEN, 2) * cut;
        for (pdd hole : holes) {
            if (hole.first + hole.second < cut) {
                w -= W(hole.second, -hole.second, hole.second);
            }
            else if (hole.first - hole.second < cut) {
                w -= W(hole.second, -hole.second, cut - hole.first);
            }
        }
        return w;
    };
    vector<double> cuts;
    for (int i = 1; i < s; i++) {
        double lb = 0, rb = LEN, mid;
        while (rb - lb > EPS) {
            mid = lb + (rb - lb) / 2;
            double w = tot_W(mid);
            if (w * s < (pow(LEN, 3) - total_hole_volume) * i) {
                lb = mid;
            }
            else {
                rb = mid;
            }
        }
        cuts.push_back(mid);
    }
    double last_cut = 0;
    for (double cut : cuts) {
        cout << (cut - last_cut) / 1000.0 << "\n";
        last_cut = cut;
    }
    cout << (LEN - last_cut) / 1000.0 << "\n";
}
