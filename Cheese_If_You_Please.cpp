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

    vector<double> objective(m);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tableau[j][i];
            tableau[j][i] = tableau[j][i] / 100.0;
        }
        cin >> tableau[n][i];
        objective[i] = tableau[n][i];
    }

    // slack variables
    for (int i = 0; i < n; i++) {
        tableau[i][m + i] = 1;
    }

    for (int i = 0; i < m; i++){ // initialize objective to -1
        tableau[n][i] = -1;
    }

    // basic variables
    unordered_map<int, int> map;
    for (int i = 0; i < m; i++) {
        map.emplace(i, -1);
    }
    for (int i = 0; i < n; i++) {
        map.emplace(m + i, i);
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
            if (tableau[i][pivot_column] != 0) {
                double temp_q = tableau[i][var_count] / tableau[i][pivot_column];

                if (0 < temp_q && temp_q < min_q) {
                    min_q = temp_q;
                    pivot_row = i;
                }
            }
        }

        // update basic variable row-index
        map.at(pivot_column) = pivot_row;

        double pivot_val = tableau[pivot_row][pivot_column];
        for (int i = 0; i < var_count + 1; i++) {
            tableau[pivot_row][i] = tableau[pivot_row][i] / pivot_val;
        }

        for (int i = 0; i < n + 1; i++){
            if(i != pivot_row){
                double old_row_value = tableau[i][pivot_column];
                for (int j = 0; j < var_count + 1; j++){
                    tableau[i][j] = tableau[i][j] - old_row_value * tableau[pivot_row][j];
                }
            }
        }
    }

    double profit = 0;
    for (int i = 0; i < m; i++) {
        if (map.at(i) != -1) {
            profit = profit + objective[i] * tableau[map.at(i)][var_count];
        }
    }
    cout << profit << "\n";

    return 0;
}
