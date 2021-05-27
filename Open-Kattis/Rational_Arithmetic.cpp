#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

void ext_gcd(lli &a, lli &b) {

   lli gcd = __gcd(a, b);
   a = a / gcd;
   b = b / gcd;

   if (b < 0) {
       a = -1 * a;
       b = -1 * b;
   }

   cout << a << " / " << b << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    lli n, a, b, c, d;
    char op;

    cin >> n;
    while (n--) {
        cin >> a >> b >> op >> c >> d;

        lli numerator, denominator;

        if (op == '+') {
            numerator = a * d + b * c;
            denominator = b * d;
        }
        else if (op == '-') {
            numerator = a * d - b * c;
            denominator = b * d;
        }
        else if (op == '*') {
            numerator = a * c;
            denominator = b * d;
        }
        else {
            numerator = a * d;
            denominator = b * c;
        }

        ext_gcd(numerator, denominator);
    }

    return 0;
}
