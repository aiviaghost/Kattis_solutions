#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(9);

    int dist, sag;
    cin >> dist >> sag;


    // find min of a * cosh(d / (2a)):
    const double gr = (1 + sqrt(5)) / 2;
    auto grs = [&](double a, double b) {
        double c = b - (b - a) / gr;
        double d = a + (b - a) / gr;

        while ((abs(c - d)) > 1e-5) {
            if (c * cosh(dist / (2 * c)) < d * cosh(dist / (2 * d))) {
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
    double min = grs(0, 420);


    // binary-search [0, min]:
    double llb = 0;
    double lrb = min;
    double lmid;
    while (abs(llb - lrb) > 1e-5) {
        lmid = llb + (lrb - llb) / 2;
        if (lmid + sag < lmid * cosh(dist / (2 * lmid))) {
            llb = lmid;
        }
        else {
            lrb = lmid;
        }
    }


    // binary-search [min, 125000]:
    double rlb = min;
    double rrb = 125000;
    double rmid;
    while (abs(rlb - rrb) > 1e-5) {
        rmid = rlb + (rrb - rlb) / 2;
        if (rmid + sag < rmid * cosh(dist / (2 * rmid))) {
            rlb = rmid;
        }
        else {
            rrb = rmid;
        }
    }

    if (abs((lmid + sag) - lmid * cosh(dist / (2 * lmid))) <= 1e-4) {
        cout << 2 * lmid * sinh(dist / (2 * lmid));
    }
    else {
        cout << 2 * rmid * sinh(dist / (2 * rmid));
    }

    return 0;
}
