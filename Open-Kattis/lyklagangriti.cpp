#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

const int INF = 2e9;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    
    string s;
    cin >> s;
    
    list<char> password;
    auto itr = password.end();
    for (char c : s) {
        if (c == 'R') {
            itr++;
        }
        else if (c == 'L') {
            itr--;
        }
        else if (c == 'B') {
            itr--;
            itr = password.erase(itr);
        }
        else {
            itr = password.emplace(itr, c);
            itr++;
        }
    }

    for (char c : password) {
        cout << c;
    }
    cout << "\n";
}
