#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(2);

    int n, m;
    cin >> n >> m;
    int var_count = n + m;

    vector<vector<double>> tableau(n + 1, vector<double>(var_count + 1));

    for (int i = 0; i < n; i++) {
        cin >> tableau[i][var_count];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tableau[j][i];
            tableau[j][i] /= 100.0;
        }
        cin >> tableau[n][i];
        tableau[n][i] *= -1.0;
    }

    // slack variables
    for (int i = 0; i < n; i++) {
        tableau[i][m + i] = 1.0;
    }

    auto is_optimal = [&] () {
        for (int i = 0; i < var_count; i++) {
            if (tableau[n][i] < 0) {
                return false;
            }
        }
        return true;
    };
    
    while (!is_optimal()) {
        int pivot_column = 0;
        for (int i = 0; i < var_count; i++) {
            if (tableau[n][i] < 0) { // Bland's rule, prevents cycling
                pivot_column = i;
                break;
            }
        }

        int pivot_row = -1;
        double min_q = numeric_limits<double>::max();
        for (int i = 0; i < n; i++) {
            if (tableau[i][pivot_column] > 0) {
                double temp_q = tableau[i][var_count] / tableau[i][pivot_column];

                if (0 <= temp_q && temp_q < min_q) {
                    min_q = temp_q;
                    pivot_row = i;
                }
            }
        }

        // gauss elimination
        double pivot_val = tableau[pivot_row][pivot_column];
        for (int i = 0; i < var_count + 1; i++) {
            tableau[pivot_row][i] = tableau[pivot_row][i] / pivot_val;
        }

        for (int i = 0; i < n + 1; i++){
            if (i != pivot_row){
                double old_row_value = tableau[i][pivot_column];
                for (int j = 0; j < var_count + 1; j++){
                    tableau[i][j] = tableau[i][j] - old_row_value * tableau[pivot_row][j];
                }
            }
        }
    }

    cout << tableau[n][var_count] << "\n";

    return 0;
}
