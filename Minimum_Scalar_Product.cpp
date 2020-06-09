#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli minimum_scalar_product(lli &n, vector<lli> &v1, vector<lli> &v2) {
    sort(v1.begin(), v1.begin() + n);
    sort(v2.begin(), v2.begin() + n);

    lli scalar_product = 0;

    for (lli i = 0; i < n; i++) {
        scalar_product += v1[i] * v2[n - i - 1];
    }

    return scalar_product;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    lli T;
    cin >> T;

    for (lli t = 1; t <= T; t++) {
        lli n;
        cin >> n;
        vector<lli> v1(n), v2(n);

        for (lli i = 0; i < n; i++) {
            cin >> v1[i];
        }

        for (lli i = 0; i < n; i++) {
            cin >> v2[i];
        }

        cout << "Case #" << t << ": " << minimum_scalar_product(n, v1, v2) << "\n";
    }

    return 0;
}
