#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    while(n--) {
        int r, e, c;
        cin >> r >> e >> c;

        if(r == e - c){
            cout << "does not matter\n";
        }
        else if(max(r, e - c) == r){
            cout << "do not advertise\n";
        }
        else{
            cout << "advertise\n";
        }
    }

    return 0;
}
