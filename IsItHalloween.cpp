#include <bits/stdc++.h>

using namespace std;

bool is_OCT(vector<char> &m) {
    return m[0] == 'O' && m[1] == 'C' && m[2] == 'T';
}

bool is_DEC(vector<char> &m) {
    return m[0] == 'D' && m[1] == 'E' && m[2] == 'C';
}

bool is_correct_month_and_day_for_halloween(vector<char> &m, int &d) {
    return (is_OCT(m) && d == 31) || (is_DEC(m) && d == 25);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    vector<char> m(3);
    int d;

    for (int i = 0; i < 3; i++) {
        cin >> m[i];
    }

    cin >> d;

    bool is_halloween = false;

    if (is_correct_month_and_day_for_halloween(m, d)) {
        is_halloween = true;
    }

    cout << (is_halloween ? "yup" : "nope") << "\n";

    return 0;
}
