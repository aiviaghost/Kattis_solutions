#include <bits/stdc++.h>

using namespace std;

#define INF 2e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

auto main() -> int {
	cin.tie(0)->sync_with_stdio(0);

	int n, q;
	cin >> n >> q;

	int vals[n];
	memset(vals, 0, 4 * n);

	int last_x, last_restart_time = -1, curr_t = 0;
	int time_of_set[n];
	memset(time_of_set, -1, 4 * n);

	while (q--) {
		string op;
		cin >> op;

		if (op[0] == 'S') {
			int i, x;
			cin >> i >> x, i--;
			vals[i] = x;
			time_of_set[i] = curr_t;
		}
		else if (op[0] == 'R') {
			int x;
			cin >> x;
			last_x = x;
			last_restart_time = curr_t;
		}
		else {
			int i;
			cin >> i, i--;
			cout << (last_restart_time < time_of_set[i] ? vals[i] : last_x) << "\n";
		}

		curr_t += 1;
	}
}
