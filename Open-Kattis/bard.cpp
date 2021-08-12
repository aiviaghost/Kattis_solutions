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

	int N;
	cin >> N;
	vector<unordered_set<int>> villagers(N);
	int E;
	cin >> E;
	int song_nbr = 0, bard_count = 0;
	for (int e = 0; e < E; e++) {
		int K;
		cin >> K;
		vector<int> ve(K);
		bool bard = false;
		for (int i = 0; i < K; i++) {
			cin >> ve[i], ve[i]--;
			if (ve[i] == 0) {
				bard = true;
			}
		}
		if (bard) {
			for (int v : ve) {
				villagers[v].emplace(song_nbr);
			}
			bard_count++;
			song_nbr++;
		}
		else {
			unordered_set<int> heard_songs;
			for (int v : ve) {
				heard_songs.insert(villagers[v].begin(), villagers[v].end());
			}
			for (int v : ve) {
				villagers[v] = heard_songs;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (villagers[i].size() == bard_count) {
			cout << i + 1 << "\n";
		}
	}
}
