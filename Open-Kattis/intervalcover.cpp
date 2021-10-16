#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

const int INF = 2e9;
const int MOD = 1e9 + 7;

vector<int> cover(double A, double B, vector<pdd>& ints) {
    vector<int> inds(ints.size()), chosen;
    iota(inds.begin(), inds.end(), 0);
    sort(inds.begin(), inds.end(), [&](int i, int j) {
        return ints[i] < ints[j];
    });
    double rb = A;
    int i = 0;
    while (rb < B || chosen.empty()) {
        pair<double, int> best = {rb, -1};
        while (i < ints.size() && ints[inds[i]].first <= rb) {
            best = max({ints[inds[i]].second, inds[i]}, best);
            i++;
        }
        if (best.second == -1) {
            return {};
        }
        rb = best.first;
        chosen.push_back(best.second);
    }
    return chosen;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    double A, B;
    while (cin >> A >> B) {
        int n;
        cin >> n;
        vector<pdd> ints(n);
        for (int i = 0; i < n; i++) {
            cin >> ints[i].first >> ints[i].second;
        }

        vector<int> chosen = cover(A, B, ints);
        
        if (!chosen.empty()) {
            cout << chosen.size() << "\n";
            for (int i : chosen) {
                cout << i << " ";
            }
            cout << "\n";
        }
        else {
            cout << "impossible\n";
        }
    }
}
