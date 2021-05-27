#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int X, Y, N;
    cin >> X >> Y >> N;

    for (int i = 1; i <= N; i++){
        if(i % X == 0 && i % Y == 0){
            cout << "FizzBuzz";
        }
        else if(i % X == 0){
            cout << "Fizz";
        }
        else if(i % Y == 0){
            cout << "Buzz";
        }
        else{
            cout << i;
        }
        cout << "\n";
    }

    return 0;
}
