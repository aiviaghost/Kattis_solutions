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

bool can_reach_cycle(
        unordered_map<string, vector<string>>& adj, 
        unordered_set<string>& vis, 
        unordered_map<string, int>& is_safe, 
        string curr
    ) {
	if (is_safe[curr] != -1) {
		return is_safe[curr] == 1;
	}
	vis.emplace(curr);
	for (string next : adj[curr]) {
		if (vis.find(next) != vis.end() || can_reach_cycle(adj, vis, is_safe, next)) {
			is_safe[curr] = 1;
			return true;
		}
	}
	is_safe[curr] = 0;
	return false;
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
    unordered_map<string, int> is_safe;
    for (string city : cities) {
        is_safe[city] = -1;
    }
    for (string city : cities) {
        if (is_safe[city] == -1) {
            unordered_set<string> vis;
            can_reach_cycle(adj, vis, is_safe, city);
        }
    }
    string q;
    while (cin >> q) {
        cout << q << " " << (is_safe[q] == 1 ? "safe" : "trapped") << "\n";
    }
}

