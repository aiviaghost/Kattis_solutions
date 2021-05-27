#include <bits/stdc++.h>

typedef long long int lli;

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    lli N;
    int b;
    cin >> N >> b;

    lli max_unique = 0;
    for (int i = b; i >= 0; i--) {
        max_unique += pow(2, i);
    }

    if (N > max_unique) {
        cout << "no";
    }
    else{
        cout << "yes";
    }

    return 0;
}
