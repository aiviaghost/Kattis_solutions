#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli inverse (lli &a, lli n) {
    lli t = 0, new_t = 1, r = n, new_r = a;

    while (new_r != 0) {
        lli q = r / new_r;
        
        lli temp_t = t;
        t = new_t;
        new_t = temp_t - q * new_t;

        lli temp_r = r;
        r = new_r;
        new_r = temp_r - q * new_r;
    }

    if (r > 1) {
        return -1;
    }
    else if (t < 0) {
        return t + n;
    }
    else {
        return t;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    lli n, t, x, y;
    char op;

    while (cin >> n >> t) {
        if (n == 0 && t == 0) 
            break;
        
        while (t--) {
            cin >> x >> op >> y;

            if (op == '+') {
                cout << ((x % n) + (y % n)) % n;
            }
            else if (op == '-') {
                lli ans = ((x % n) - (y % n)) % n;
                cout << (ans < 0 ? ans + n : ans);
            }
            else if (op == '*') {
                cout << ((x % n) * (y % n)) % n;
            }
            else {
                lli inv = inverse(y, n);
                cout << (inv != -1 ? ((x % n) * inv) % n : -1);
            }

            cout << "\n";
        }
    }    

    return 0;
}
