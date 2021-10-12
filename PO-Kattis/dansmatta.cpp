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

auto diff(string &s1, string &s2) -> int {
	int d = 0;
	for (int i = 0; i < 4; i++) {
		if (s1[i] != s2[i]) {
			d++;
		}
	}
	return d / 2;
}

auto convert(string &s) -> string {
	string out;
	out.append((s[0] == 'V' || s[1] == 'V') ? "1" : "0");
	out.append((s[0] == 'U' || s[1] == 'U') ? "1" : "0");
	out.append((s[0] == 'H' || s[1] == 'H') ? "1" : "0");
	out.append((s[0] == 'N' || s[1] == 'N') ? "1" : "0");
	return out;
}

auto main() -> int {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	vector<string> input(n);
	for (int i = 0; i < n; i++) {
		string move;
		cin >> move;
		input[i] = convert(move);
	}
	vector<string> all_moves = {
		"0011", "0101", "0110", "1010", "1100", "1001"
	};
	auto moves = vector<vector<pair<string, int>>>(n + 1);
	moves[0].push_back({"1010", 0});
	for (int t = 0; t < n; t++) {
		for (string pos : all_moves) {
			bool valid = true;
			for (int i = 0; i < 4; i++) {
				if (input[t][i] == '1' && pos[i] == '0') {
					valid = false;
				}
			}
			if (valid) {
				int best = INF;
				for (pair<string, int> p : moves[t]) {
					best = min(p.second + diff(p.first, pos), best);
				}
				moves[t + 1].push_back({pos, best});
			}
		}
	}
	int ans = INF;
	for (pair<string, int> p : moves[n]) {
		ans = min(p.second, ans);
	}
	cout << ans << "\n";
}
