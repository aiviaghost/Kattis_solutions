#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    string in1, in2;
    cin >> in1 >> in2;

    deque<char> s1, s2;
    for (char c : in1) {
        s1.push_back(c);
    }

    for (char c : in2) {
        s2.push_back(c);
    }

    while(!s1.empty() && !s2.empty() && s1.front() == s2.front()) {
        s1.pop_front();
        s2.pop_front();
    }

    while(!s1.empty() && !s2.empty() && s1.back() == s2.back()) {
        s1.pop_back();
        s2.pop_back();
    }

    cout << s2.size() << "\n";
}
