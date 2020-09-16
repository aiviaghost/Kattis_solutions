#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using pii = pair<int, int>;
using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    long long A, B;
    while (cin >> A >> B && A != 0 && B != 0) {
        vector<long long> stepsA{A}, stepsB{B};

        while (A != 1) {
            if ((A & 1) == 0) {
                A /= 2;
            }
            else {
                A = 3 * A + 1;
            }
            stepsA.push_back(A);
        }

        while (B != 1) {
            if ((B & 1) == 0) {
                B /= 2;
            }
            else {
                B = 3 * B + 1;
            }
            stepsB.push_back(B);
        }

        int reqA, reqB;
        for (int i = 0; i < stepsA.size(); i++) {
            for (int j = 0; j < stepsB.size(); j++) {
                if (stepsA[i] == stepsB[j]) {
                    reqA = i, reqB = j;
                    i = stepsA.size();
                    break;
                }
            }
        }

        cout << stepsA[0] << " needs " << reqA << " steps, " << stepsB[0] << " needs " << reqB << " steps, they meet at " << stepsA[reqA] << "\n";
    }
}
