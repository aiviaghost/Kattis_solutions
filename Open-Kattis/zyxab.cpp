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

auto no_repeats(string& s) -> bool {
	unordered_set<char> chars;
	for (int i = 0; i < s.length(); i++) {
		chars.emplace(s[i]);
	}
	return chars.size() == s.length();
}

auto main() -> int {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	vector<string> names(n);
	for (int i = 0; i < n; i++) {
		cin >> names[i];
	}
	sort(names.begin(), names.end(), [&](string& s1, string& s2) {
		return s1.length() < s2.length() || (s1.length() == s2.length() && s1 > s2);
	});
	bool exists = false;
	string ans;
	for (string name : names) {
		if (name.length() >= 5 && no_repeats(name)) {
			ans = name;
			exists = true;
			break;
		}
	}
	cout << (exists ? ans : "neibb!") << "\n";
}
