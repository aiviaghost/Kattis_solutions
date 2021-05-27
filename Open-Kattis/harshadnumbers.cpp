#include <bits/stdc++.h>

using namespace std;

auto is_harshad(int &n) -> bool {
    int x = n;

    int sum = 0;
    while (x != 0) {
        sum += x % 10;
        x /= 10;
    }
    
    return n % sum == 0;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    while (!is_harshad(n)) {
        n++;
    }

    cout << n << "\n";

    return 0;
}
