#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    while (cin >> n) {
        if (n == 0)
            break;
        
        vector<int> reg(32), known(32);

        string op;
        int x, y;
        while (n--) {
            cin >> op;

            if (op == "OR") {
                cin >> x >> y;
                if (known[x] == 1 && known[y] == 1) {
                    reg[x] = reg[x] | reg[y];
                }
                else if (known[y] == 1 && reg[y] == 1) {
                    reg[x] = reg[x] | reg[y];
                    known[x] = 1;
                }
                else if (known[x] == 1 && reg[x] == 0) {
                    reg[x] = 0;
                    known[x] = 0;
                }
            }
            else if (op == "AND") {
                cin >> x >> y;
                if (known[x] == 1 && known[y] == 1) {
                    reg[x] = reg[x] & reg[y];
                }
                else if (known[y] && reg[y] == 0) {
                    reg[x] = reg[x] & reg[y];
                    known[x] = 1;
                }
                else if (known[x] == 1 && reg[x] == 1){
                    reg[x] = 0;
                    known[x] = 0;
                }
            }
            else if (op == "SET") {
                cin >> x;
                reg[x] = 1;
                known[x] = 1;
            }
            else {
                cin >> x;
                reg[x] = 0;
                known[x] = 1;
            }
        }

        for (int i = 31; i >= 0; i--) {
            if (known[i]) {
                cout << reg[i];
            }
            else {
                cout << "?";
            }
        }

        cout << "\n";
    }

    return 0;
}
