#include <bits/stdc++.h>

using namespace std;

#define INF 2e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

vector<vector<int>> codes;

auto generate_codes(vector<int> code, int index = 0) -> void {
    if (index < code.size()) {
        generate_codes(code, index + 1);
        code[index] = 1;
        generate_codes(code, index + 1);
    }
    else {
        codes.push_back(code);
    }
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int M[n][k];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                cin >> M[i][j];
            }
        }

        vector<int> zero_code(k);
        generate_codes(zero_code);

        int min_dist = INF;
        for (int index = 1; index < codes.size(); index++) {
            vector<int> &code = codes[index];
            int res[n];

            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = 0; j < k; j++) {
                    sum = (sum + M[i][j] * code[j]) & 1;
                }
                res[i] = sum;
            }
            
            int dist = 0;
            for (int i = 0; i < n; i++) {
                if (res[i]) {
                    dist++;
                }
            }
            min_dist = min(dist, min_dist);
        }

        cout << min_dist << "\n";

        codes.clear();
    }
}
