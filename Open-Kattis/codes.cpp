#include <bits/stdc++.h>

using namespace std;

#define INF 2e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

vector<vector<int>> codes[15];

auto generate_codes(vector<int> code) -> void {
    if (code.size() < 15) {
        vector<int> temp = code;
        code.push_back(0);
        codes[code.size()].push_back(code);
        generate_codes(code);
        temp.push_back(1);
        codes[temp.size()].push_back(temp);
        generate_codes(temp);
    }
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    vector<int> zero_code;
    generate_codes(zero_code);
    
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

        int min_dist = INF;
        for (int index = 1; index < codes[k].size(); index++) {
            vector<int> &code = codes[k][index];
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
    }
}
