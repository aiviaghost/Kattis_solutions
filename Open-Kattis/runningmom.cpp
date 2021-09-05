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
const int MOD = 1e9 + 7;

void can_reach_cycle(
        unordered_map<string, vector<string>>& adj, 
        unordered_set<string>& gvis, 
        unordered_set<string>& lvis, 
        unordered_map<string, bool>& is_safe, 
        string curr
    ) {
    if (gvis.find(curr) != gvis.end()) {
        return;
    }
    gvis.emplace(curr);
    lvis.emplace(curr);
    for (string next : adj[curr]) {
        if (lvis.find(next) != lvis.end()) {
            is_safe[curr] = true;
        }
        else {
            can_reach_cycle(adj, gvis, lvis, is_safe, next);
            is_safe[curr] = is_safe[next];
        }
    }
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    cin.ignore();
    unordered_map<string, vector<string>> adj;
    unordered_set<string> cities;
    for (int i = 0; i < n; i++) {
        string o, d;
        cin >> o >> d;
        adj[o].push_back(d);
        cities.insert({o, d});
    }
    unordered_map<string, bool> is_safe;
    for (string city : cities) {
        is_safe[city] = false;
    }
    unordered_set<string> gvis;
    for (string city : cities) {
        unordered_set<string> lvis;
        can_reach_cycle(adj, gvis, lvis, is_safe, city);
    }
    string q;
    while (cin >> q) {
        cout << q << " " << (is_safe[q] ? "safe" : "trapped") << "\n";
    }
}
