#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(15);

    int n;
    cin >> n;

    auto factorial = [&](int n) { double sum = 1; for (int i = 2; i <= n; i++) { sum = sum * i; } return sum; };
    
    double e = 0;
    for (int i = 0; i <= n; i++) {
        double div = factorial(i);
        if (div >= 1) {
            e += 1 / div;
        }
        else {
            break;
        }
    }

    cout << e << "\n";

    return 0;
}
