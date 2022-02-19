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

#define all(x) x.begin(), x.end()

const int INF = 2e9;
const int MOD = 1e9 + 7;

double D(pii & p1, pii & p2) {
	return sqrt(pow((double)(p1.first - p2.first), 2.0) + pow((double)(p1.second - p2.second), 2.0));
}

pii start;
pii end1;
map<pii, vector<pii>> adj;
int bfs(double max_dist, bool alice) {
	queue<pii> q({start});
	map<pii, int> dist;
	dist[start] = 0;
	while (!q.empty()) {
		pii curr = q.front();
		q.pop();
		for (pii next : adj[curr]) {
			if (alice) {
				if (!dist.count(next) && D(curr, next) <= max_dist) {
					dist[next] = dist[curr] + 1;
					q.push(next);
				}
			}
			else {
				if (!dist.count(next) && D(curr, next) <= max_dist && (curr.first == next.first || curr.second == next.second)) {
					dist[next] = dist[curr] + 1;
					q.push(next);
				}
			}
		}
	}
	return dist.count(end1) ? dist[end1] : INF;
}

auto main() -> int {
	cin.tie(0)->sync_with_stdio(0);

	int A, F;
	cin >> A >> F;
	int l, w;
	cin >> l >> w;
	vector<pii> ws;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < w; j++) {
			char c;
			cin >> c;
			if (c == 'S') {
				start = {j, i};
				ws.push_back(start);
			}
			else if (c == 'G') {
				end1 = {j, i};
				ws.push_back(end1);
			}
			else if (c == 'W') {
				ws.push_back({j, i});
			}
		}
	}
	int n = ws.size();
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			adj[ws[i]].push_back(ws[j]);
			adj[ws[j]].push_back(ws[i]);
		}
	}

	int alice = bfs(A, true);
	int father = bfs(F, false);

	if (alice == INF && father == INF) {
		cout << "NO WAY\n";
	}
	else if (alice == father) {
		cout << "SUCCESS\n";
	}
	else if (alice < father) {
		cout << "GO FOR IT\n";
	}
	else if (father < alice) {
		cout << "NO CHANCE\n";
	}
	else {
		cout << "NO WAY\n";
	}
}
