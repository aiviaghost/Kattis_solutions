#include <bits/stdc++.h>

using namespace std;

#define BIGM 1e18

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int a, b, m, s;
    cin >> a >> b >> m >> s;

    double tableau[5][10] = {
        {1, 1, 1, 0, 0, 0, 0, 0, 0, m}, 
        {2, 1, 0, -1, 0, 0, 1, 0, 0, s}, 
        {1, 0, 0, 0, -1, 0, 0, 1, 0, 1}, 
        {0, 1, 0, 0, 0, -1, 0, 0, 1, 1}, 
        {-a, -b, 0, 0, 0, 0, BIGM, BIGM, BIGM, 0}
    };

    auto get_piv_col = [&] () {
        double min_val = 1e9, index = -1;
        for (int i = 0; i < 10; i++) {
            if (tableau[4][i] < 0 && tableau[4][i] < min_val) {
                min_val = tableau[4][i];
                index = i;
                // cout << "index: " << index << ", val: " << min_val << "\n";
            }
        }
        return index;
    };

    int piv_col, piv_row;
    while (1) {
        /*
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 10; j++) {
                cout << tableau[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        */

        piv_col = get_piv_col();
        if (piv_col == -1) {
            break;
        }
        
        double min_q = numeric_limits<double>::max();
        for (int i = 0; i < 4; i++) {
            if (tableau[i][piv_col] > 0) {
                double temp_q = tableau[i][9] / tableau[i][piv_col];
                if (0 <= temp_q && temp_q < min_q) {
                    min_q = temp_q;
                    piv_row = i;
                }
            }
        }
        cout << "col: " << piv_col << ", row: " << piv_row << "\n";
        double piv_val = tableau[piv_row][piv_col];

        for (int i = 0; i < 10; i++) {
            tableau[piv_row][i] /= piv_val;
        }

        for (int i = 0; i < 5; i++) {
            if (i != piv_row) {
                double old_val = tableau[i][piv_col];
                for (int j = 0; j < 10; j++) {
                    tableau[i][j] -= old_val * tableau[piv_row][j];
                }
            }
        }
    }

    cout << tableau[4][9] << "\n";
}
