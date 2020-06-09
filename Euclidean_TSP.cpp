#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    const ld root2 = sqrt(2);
    const ld gr = (1 + sqrt(5)) / 2;

    ld n, p, s, v;
    cin >> n >> p >> s >> v;

    auto f = [&](ld c) {
        return (n * pow(log2(n), c * root2)) / (p * 1e9) + (s * (1 + (1 / c))) / v;
    };

    auto grs = [&](ld a, ld b) {
        ld c = b - (b - a) / gr;
        ld d = a + (b - a) / gr;

        while ((abs(c - d)) > 1e-6) {
            if (f(c) < f(d)) {
                b = d;
            }
            else {
                a = c;
            }

            c = b - (b - a) / gr;
            d = a + (b - a) / gr;
        }

        return (b + a) / 2;
    };

    ld c = grs(0.1, 500);
    ld t = f(c);

    cout << fixed << setprecision(13);
    cout << t << " " << c;

    return 0;
}
