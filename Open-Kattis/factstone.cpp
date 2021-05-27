#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using pii = pair<int, int>;
using pdd = pair<double, double>;

auto gen_map() -> unordered_map<int, int> {
    unordered_map<int, int> answers;
    int year = 1960, i = 2;
    double log_fact = 0;
    while (year <= 2160) {
        log_fact += log2(i);
        if (log_fact > 4 * pow(2, (year - 1960) / 10)) {
            answers[year] = i - 1;
            year += 10;
        }
        i++;
    }

    return answers;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    unordered_map<int, int> answers = gen_map();

    int y;
    while (cin >> y && y != 0) {
        cout << answers[y - y % 10] << "\n";
    }
}
