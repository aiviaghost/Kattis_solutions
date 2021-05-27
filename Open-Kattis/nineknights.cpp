#include <bits/stdc++.h>

using namespace std;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int knight_count = 0;
    char board[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'k') {
                knight_count++;
            }
        }
    }

    bool valid = knight_count == 9;

    if (valid) {
        vector<pair<int, int>> moves{{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == 'k') {
                    for (pair<int, int> next : moves) {
                        int nx = j + next.first;
                        int ny = i + next.second;
                        if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && board[ny][nx] == 'k') {
                            valid = false;
                            i = j = 5;
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << (valid ? "valid" : "invalid") << "\n";
}
