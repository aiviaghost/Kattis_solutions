#include <bits/stdc++.h>

using namespace std;

#define BigM 1e11

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    double a, b, m, s;
    cin >> a >> b >> m >> s;

    double tableau[5][10] = {
        {1, 1, 1, 0, 0, 0, 0, 0, 0, m}, 
        {2, 1, 0, -1, 0, 0, 1, 0, 0, s}, 
        {1, 0, 0, 0, -1, 0, 0, 1, 0, 1}, 
        {0, 1, 0, 0, 0, -1, 0, 0, 1, 1}, 
        {a, b, 0, 0, 0, 0, -BigM, -BigM, -BigM, 0}
    };

    double init_obj[10] = {a, b, 0, 0, 0, 0, -BigM, -BigM, -BigM, 0};
    int val_map[] = {2, 6, 7 ,8};

    auto get_piv_col = [&] () {
        double z_row[9];
        memset(z_row, 0, sizeof(z_row));
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 9; j++) {
                z_row[j] += tableau[i][j] * init_obj[val_map[i]];
            }
        }
        
        int piv_col = -1;
        double min_val = 1e9;
        for (int i = 0; i < 9; i++) {
            double alt_min = z_row[i] - init_obj[i];
            if (min_val > alt_min && alt_min < 0) {
                min_val = alt_min;
                piv_col = i;
            }
        }

        return piv_col;
    };

    while (1) {
        int piv_col = get_piv_col();
        
        if (piv_col == -1) {
            break;
        }

        int piv_row;
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
        val_map[piv_row] = piv_col;

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

    cout << (long long) -tableau[4][9] << "\n";
}
