#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(5);

    int n;
    while (cin >> n) {
        if (n == 0)
            break;
        
        vector<vector<double>> matrix(n, vector<double>(n + 1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            cin >> matrix[i][n];
        }

        bool has_multiple = false, inconsistent = false;
        int row = 0, col = 0;
        while (row < n && col < n) {
            if (matrix[row][col] == 0) {
                for (int i = row; i < n; i++) {
                    if (i == n - 1 && matrix[i][col] == 0) {
                        inconsistent = true; // hmm
                        row = col = n + 1;
                        break;
                    }
                    
                    if (matrix[i][col] != 0) {
                        vector<double> copy(matrix[i]);
                        matrix[i] = matrix[row];
                        matrix[row] = copy;
                        break;
                    }
                }
            }
            else {
                double pivot = matrix[row][col];
                
                for (int i = 0; i < n + 1; i++) {
                    matrix[row][i] = matrix[row][i] / pivot;
                }

                for (int i = 0; i < n; i++) {
                    if (i != row) {
                        int zero_counter = 0;
                        double c = matrix[i][col];
                        for (int j = 0; j < n + 1; j++) {
                            matrix[i][j] = matrix[i][j] - c * matrix[col][j];
                            if (matrix[i][j] == 0) {
                                zero_counter++;

                                if (zero_counter == n) {
                                    inconsistent = true;
                                }
                                
                                if (zero_counter == n + 1) {
                                    has_multiple = true;
                                }
                            }
                        }
                        if (inconsistent || has_multiple) {
                            row = col = i = n + 1;
                        }
                    }
                }

                row++;
                col++;
            }
        }

        if (has_multiple) {
            cout << "multiple" << "\n";
        }
        else if (inconsistent) {
            cout << "inconsistent" << "\n";
        }
        else {
            string out = "";
            for (int i = 0; i < n; i++) {
                out += to_string(matrix[i][n]) + " ";
            }

            if (out != "")
                out.pop_back();
            
            cout << out << "\n";
        }
    }

    return 0;
}
