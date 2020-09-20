#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

vector<vector<double>> matrix;
vector<double> x;

auto gauss(int &n) -> int {
    int ones[n];
    memset(ones, -1, 4 * n);
    for (int row = 0, col = 0; row < n && col < n; col++) {
        if (matrix[row][col] == 0) {
            for (int i = row; i < n; i++) {
                if (matrix[i][col] != 0) {
                    swap(matrix[row], matrix[i]);
                    break;
                }
            }
        }

        double piv = matrix[row][col];

        if (piv == 0) {
            continue;
        }

        ones[col] = row;
        
        for (int i = col; i < n + 1; i++) {
            matrix[row][i] /= piv;
        }

        for (int i = 0; i < n; i++) {
            if (i != row) {
                double prev_val = matrix[i][col];
                for (int j = col; j < n + 1; j++) {
                    matrix[i][j] -= prev_val * matrix[row][j];
                }
            }
        }

        row++;   
    }

    // preliminary solution vector
    x.resize(n);
    for (int i = 0; i < n; i++) {
        if (ones[i] != -1) {
            x[i] = matrix[ones[i]][n];
        }
    }

    // test if solution is valid
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < n; j++) {
            sum += matrix[i][j] * x[j];
        }
        if (sum != matrix[i][n]) {
            return 0;
        }
    }

    // if column does not have a distinct one then the system is inconsistent
    for (int i = 0; i < n; i++) {
        if (ones[i] == -1) {
            return INF;
        }
    }

    return 1;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(4);

    int n;
    while (cin >> n && n != 0) {
        matrix.resize(n, vector<double>(n + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            cin >> matrix[i][n];
        }

        int solution_count = gauss(n);
        
        /*
        cout << "res: \n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n + 1; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
        */

        if (solution_count == 0) {
            cout << "inconsistent";
        }
        else if (solution_count == 1) {
            cout << x.front();
            for (int i = 1; i < n; i++) {
                cout << " " << x[i];
            }
        }
        else if (solution_count == INF) {
            cout << "multiple";
        }
        cout << "\n";
    }
}
