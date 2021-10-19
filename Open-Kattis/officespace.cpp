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

struct Person {
	string name;
	int x1, y1, x2, y2;
};

auto main() -> int {
	cin.tie(0)->sync_with_stdio(0);

	int w, h;
	while (cin >> w >> h) {
		auto used = make<int>(0, h, w);
		int n;
		cin >> n;
		vector<Person> people;
		people.reserve(n);
		for (int i = 0; i < n; i++) {
			string name;
			cin >> name;
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			people.push_back({name, x1, y1, x2, y2});
			for (int y = y1; y < y2; y++) {
				for (int x = x1; x < x2; x++) {
					used[y][x]++;
				}
			}
		}

		int unused = 0, contested = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				unused += used[i][j] == 0;
				contested += used[i][j] > 1;
			}
		}

		cout << "Total " << w * h << "\n";
		cout << "Unallocated " << unused << "\n";
		cout << "Contested " << contested << "\n";
		for (Person p : people) {
			int given = 0;
			for (int y = p.y1; y < p.y2; y++) {
				for (int x = p.x1; x < p.x2; x++) {
					given += used[y][x] == 1;
				}
			}
			cout << p.name << " " << given << "\n";
		}
		cout << "\n";
	}
}
