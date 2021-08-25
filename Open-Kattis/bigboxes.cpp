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

bool validate(int n, int k, int max_w, vector<int>& items) {
    int boxes_needed = 0, index = 0;
    while (index < n) {
        int tot_w = 0;
        while (index < n && tot_w + items[index] <= max_w) {
            tot_w += items[index];
            index++;
        }
        if (tot_w > 0) {
            boxes_needed++;
        }
        else {
            return false;
        }
    }
    return boxes_needed <= k;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i];
    }
    int best_ans = INF;
    int lb = 1, rb = 1e9, mid;
    while (lb < rb) {
        mid = lb + (rb - lb) / 2;
        if (validate(n, k, mid, items)) {
            rb = mid - 1;
        }
        else {
            lb = mid + 1;
        }
    }
    while (!validate(n, k, mid, items)) {
        mid++;
    }
    cout << mid << "\n";
}
