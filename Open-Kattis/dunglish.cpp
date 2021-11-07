#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
	auto inner = make<T>(init, sizes...);
	return vector<decltype(inner)>(first, inner);
}

const int INF = 2e9;
const int MOD = 1e9 + 7;

unordered_map<string, vector<pair<string, bool>>> dict;

bool single(vector<string>& words) {
	int valid_count = 0;
	for (string s : words) {
		if (dict[s].size() == 1) {
			valid_count++;
		}
	}
	return valid_count == words.size();
}

auto main() -> int {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	vector<string> words;
	for (int i = 0; i < n; i++) {
		string sp;
		cin >> sp;
		words.push_back(sp);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string word, tr, cor;
		cin >> word >> tr >> cor;
		dict[word].push_back({tr, cor == "correct"});
	}

	if (single(words)) {
		bool valid = dict[words[0]][0].second;
		cout << dict[words[0]][0].first;
		for (int i = 1; i < n; i++) {
			cout << " " << dict[words[i]][0].first;
			valid = valid && dict[words[i]][0].second;
		}
		cout << "\n";
		cout << (valid ? "correct\n" : "incorrect\n");
	}
	else {
		vector<ll> corr(n), incorr(n);
		int index = 0;
		for (string s : words) {
			for (auto p : dict[s]) {
				corr[index] += p.second;
				incorr[index] += !p.second;
			}
			index++;
		}
		ll ans_corr = 1, tot = 1;
		for (int i = 0; i < n; i++) {
			ans_corr *= corr[i];
			tot *= (corr[i] + incorr[i]);
		}
		ll ans_incorr = tot - ans_corr;
		cout << ans_corr << " correct\n";
		cout << ans_incorr << " incorrect\n";
	}
}
