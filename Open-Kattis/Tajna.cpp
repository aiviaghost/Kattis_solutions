#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string enc;
    getline(cin, enc);

    int max_row = 1;
    for (int d = 1; d <= sqrt(enc.length()); d++) {
        max_row = enc.length() % d == 0 ? max(d, max_row) : max_row;
    }
        
    vector<vector<char>> matrix(max_row, vector<char>(enc.length() / max_row));

    for (int i = 0; i < enc.length() / max_row; i++) {
        for (int j = 0; j < max_row; j++) {
            matrix[j][i] = enc.at(i * max_row + j);
        }
    }

    string decr = "";
    for (int i = 0; i < max_row; i++) {
        for (int j = 0; j < enc.length() / max_row; j++) {
            decr += matrix[i][j];
        }
    }

    cout << decr << "\n";

    return 0;
}
