#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed;
    cout.precision(3);

    int C;
    cin >> C;

    while(C--){
        int N;
        cin >> N;
        vector<int> grades(N);

        double average = 0;
        for (int i = 0; i < N; i++){
            int t;
            cin >> t;
            average += t;
            grades[i] = t;
        }
        average = average / N;
        
        double above_average = 0;
        for (int i = 0; i < N; i++) {
            if(grades[i] > average) {
                above_average++;
            }
        }
        
        above_average = (above_average / N) * 100;

        cout << above_average << "%\n";
    }

    return 0;
}
