#include<iostream>

using namespace std;

bool equal(int n, int &x){
    int sum = 0;
    while(n > 0){
        sum += n % 10;
        n = n / 10;
    }
    return sum == x;
}

int main(){
    int L, D, X;
    cin >> L;
    cin >> D;
    cin >> X;

    int n = L;
    while(!equal(n, X)) {
        n++;
    }
    cout << n << "\n";

    int m = D;
    while(!equal(m, X)) {
        m--;
    }
    cout << m << "\n";

    return 0;
}
