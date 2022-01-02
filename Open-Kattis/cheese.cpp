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

double V(double r, double a, double b) {
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
        holes[i] = {x / 1000.0, r / 1000.0};
    }
    sort(holes.begin(), holes.end());

    vector<double> cuts;
    auto use = [&](double w) {
        cuts.clear();
        int used = 0;

        return used;
    };

    double lb = 0, rb = 1e15 + 1;
    while (rb - lb > 1e-7) {
        double mid = lb + (rb - lb) / 2;
        int used = use(mid);
        if (used == s) {
            break;
        }
        else if (used < s) {
            rb = mid;
        }
        else {
            lb = mid;
        }
    }
    for (double cut : cuts) {
        cout << cut << "\n";
    }
}
