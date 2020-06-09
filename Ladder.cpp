#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int h, v;
    cin >> h >> v;

    cout << ceil(h / sin((atan(1) * 4 * v) / 180));

    return 0;
}
