#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    int cpc = 1;
    if(cpc == n){
        cout << n;
    }
    else{
        int days = 1;
        while (cpc < n){
            cpc <<= 1; // bit shifting POGCHAMP
            days++;
        }
        cout << days;
    }

    return 0;
}
