#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T, n1, n2;
    cin >> T;

    while (T--) {
        cin >> n1;
        vector<int> p1(n1 + 1);
        for (int i = 0; i <= n1; i++) {
            cin >> p1[i];
        }

        cin >> n2;
        vector<int> p2(n2 + 1);
        for (int i = 0; i <= n2; i++) {
            cin >> p2[i];
        }
 
        vector<int> prod(n1 + n2 + 1);

        for (int i = 0; i < max(p1.size(), p2.size()); i++) {
            for (int j = 0; j < min(p1.size(), p2.size()); j++) {
                if (p1.size() < p2.size() && p1[j] != 0 && p2[i] != 0) {
                    prod[i + j] += p1[j] * p2[i];
                }
                else if (p1[i] != 0 && p2[j] != 0){
                    prod[i + j] += p1[i] * p2[j];
                }
            }
        }

        cout << prod.size() - 1 << "\n";
        string out = "";
        for (int i = 0; i < prod.size(); i++) {
            out += to_string(prod[i]) + " ";
        }
        out.pop_back();
        cout << out << "\n";
    }

    return 0;
}
