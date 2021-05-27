#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int ncs, ne;
        cin >> ncs >> ne;

        vector<int> cs(ncs);

        double avg_cs = 0;
        for (int i = 0; i < ncs; i++) {
            cin >> cs[i];
            avg_cs += cs[i];
        }
        avg_cs /= ncs;

        double avg_e = 0;
        for (int i = 0; i < ne; i++) {
            int e;
            cin >> e;
            avg_e += e;
        }
        avg_e /= ne;

        int count = 0;
        for (int i = 0; i < ncs; i++) {
            if (cs[i] < avg_cs && cs[i] > avg_e) {
                count++;
            }
        }
        cout << count << "\n";
    }

    return 0;
}
