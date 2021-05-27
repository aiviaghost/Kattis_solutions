#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    vector<vector<char>> board(8, vector<char>(8));

    int queen_count = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
            if (board[i][j] == '*') {
                queen_count++;
            }
        }
    }

    auto is_inside = [&](int x, int y) {
        return 0 <= x && x < 8 && 0 <= y && y < 8;
    };

    bool is_valid = queen_count == 8;

    if (is_valid) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == '*') {
                    for (int k = 1; k < 8; k++) {
                        if (is_inside(j, i + k) && board[i + k][j] == '*') {
                            is_valid = false;
                            i = j = k = 8;
                        }
                        else if (is_inside(j, i - k) && board[i - k][j] == '*') {
                            is_valid = false;
                            i = j = k = 8;
                        }
                        else if (is_inside(j + k, i) && board[i][j + k] == '*') {
                            is_valid = false;
                            i = j = k = 8;
                        }
                        else if (is_inside(j - k, i) && board[i][j - k] == '*') {
                            is_valid = false;
                            i = j = k = 8;
                        }
                        else if (is_inside(j + k, i + k) && board[i + k][j + k] == '*') {
                            is_valid = false;
                            i = j = k = 8;
                        }
                        else if (is_inside(j - k, i - k) && board[i - k][j - k] == '*') {
                            is_valid = false;
                            i = j = k = 8;
                        }
                        else if (is_inside(j + k, i - k) && board[i - k][j + k] == '*') {
                            is_valid = false;
                            i = j = k = 8;
                        }
                        else if (is_inside(j - k, i + k) && board[i + k][j - k] == '*') {
                            is_valid = false;
                            i = j = k = 8;
                        }
                    }
                }
            }
        }
    }

    cout << (is_valid ? "valid" : "invalid") << "\n";

    return 0;
}
