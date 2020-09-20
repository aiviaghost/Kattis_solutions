#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using pii = pair<int, int>;
using pdd = pair<double, double>;
using lli = long long;

lli inverse (lli a, lli n) {
    lli t = 0, new_t = 1, r = n, new_r = a;

    while (new_r != 0) {
        lli q = r / new_r;
        
        lli temp_t = t;
        t = new_t;
        new_t = temp_t - q * new_t;

        lli temp_r = r;
        r = new_r;
        new_r = temp_r - q * new_r;
    }

    if (r > 1) {
        return -1;
    }
    else if (t < 0) {
        return t + n;
    }
    else {
        return t;
    }
}

auto mod_exp(int base, int exp, int &mod) -> int {
    int res = 1;
    while (exp > 0) {
        if ((exp & 1) == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;
    while (N--) {
        int p;
        cin >> p;
        string text;
        cin >> text;
        int n = text.length();

        vector<vector<int>> matrix(n, vector<int>(n + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = mod_exp(i + 1, j, p);
            }
            matrix[i][n] = text[i] != '*' ? text[i] - 'a' + 1 : 0;
        }

        // gauss-jordan
        for (int row = 0, col = 0; row < n && col < n; row++, col++) {
            int selected_row = row;
            if (matrix[selected_row][col] == 0) {
                for (int i = selected_row; i < n; i++) {
                    if (matrix[i][col] != 0) {
                        swap(matrix[i], matrix[selected_row]);
                    }
                }
            }

            int coefficient = inverse(matrix[selected_row][col], p);
            for (int i = col; i < n + 1; i++) {
                matrix[selected_row][i] = (matrix[selected_row][i] * coefficient) % p;
            }

            for (int i = 0; i < n; i++) {
                if (i != selected_row) {
                    int prev_val = matrix[i][col];
                    for (int j = col; j < n + 1; j++) {
                        int mult = (prev_val * matrix[selected_row][j]) % p;
                        int res = (matrix[i][j] - mult) % p;
                        matrix[i][j] = res < 0 ? res + p : res;
                    }
                }
            }
        }

        cout << matrix[0][n];
        for (int i = 1; i < n; i++) {
            cout << " " << matrix[i][n];
        }
        cout << "\n";
    }
}
