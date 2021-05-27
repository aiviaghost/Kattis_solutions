#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(2);

    int n;
    cin >> n;
    int ineq_count = (n * (n - 1)) / 2;

    vector<pair<int, int>> posts(n);

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        posts[i] = {x, y};
    }

    int var_count = ineq_count + n;
    vector<vector<double>> tableau(ineq_count + 1, vector<double>(var_count + 1));

    int temp_row_index = 0;
    for (int i = 0; i < n - 1; i++) { // set initial coefficients
        for (int j = i + 1; j < n; j++) {
            tableau[temp_row_index][i] = 1;
            tableau[temp_row_index][j] = 1;
            tableau[temp_row_index][n + temp_row_index] = 1;

            int dx = abs(posts[i].first - posts[j].first);
            int dy = abs(posts[i].second - posts[j].second);
            tableau[temp_row_index][var_count] = sqrt(dx * dx + dy * dy);
            
            temp_row_index++;
        }
    }

    for(int i = 0; i < n; i++){ // initialize objective to -1
        tableau[ineq_count][i] = -1;
    }

    auto is_optimal = [&] () {
        for (int i = 0; i < var_count + 1; i++) {
            if (tableau[ineq_count][i] < 0) {
                return false;
            }
        }
        return true;
    };
    
    while (!is_optimal()) {
        int pivot_column = 0;
        for (int i = 0; i < var_count; i++) {
            if (tableau[ineq_count][i] < 0) { // Bland's rule, prevents cycling
                pivot_column = i;
                break;
            }
        }

        int pivot_row = -1;
        double min_q = numeric_limits<double>::max();
        for (int i = 0; i < ineq_count; i++) {
            if (tableau[i][pivot_column] != 0) {
                double temp_q = tableau[i][var_count] / tableau[i][pivot_column];

                if (0 < temp_q && temp_q < min_q) {
                    min_q = temp_q;
                    pivot_row = i;
                }
            }
        }

        double pivot_val = tableau[pivot_row][pivot_column];
        for (int i = 0; i <= var_count; i++) {
            tableau[pivot_row][i] = tableau[pivot_row][i] / pivot_val;
        }

        for(int i = 0; i < ineq_count + 1; i++){
            if(i != pivot_row){
                double old_row_value = tableau[i][pivot_column];
                for(int j = 0; j < var_count + 1; j++){
                    tableau[i][j] = tableau[i][j] - old_row_value * tableau[pivot_row][j];
                }
            }
        }
    }

    cout << tableau[ineq_count][var_count] << "\n";

    return 0;
}
