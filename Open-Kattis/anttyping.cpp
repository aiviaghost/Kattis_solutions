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

int n = 9;
vector<vector<int>> perms;

void gen_perms() {
	vector<int> arr;
    for (int i = 0; i < n; i++) {
        arr.push_back(i);
    }
    perms.push_back(arr);
    vector<int> c(n);
    int i = 1;
    while (i < n) {
        if (c[i] < i) {
            if (i % 2 == 0) {
                swap(arr[0], arr[i]);
            }
            else {
                swap(arr[c[i]], arr[i]);
            }
        	perms.push_back(arr);
            c[i]++;
            i = 1;
        }
        else {
            c[i] = 0;
            i++;
        }
    }
}

auto main() -> int {
	cin.tie(0)->sync_with_stdio(0);

	gen_perms();

	string s;
	cin >> s;
	
	if (s.length() == 1) {
		cout << "1\n";
		exit(0);
	}

	auto dist = make<int>(0, perms.size(), n, n);
	for (int i = 0; i < dist.size(); i++) {
		vector<int> c = perms[i];
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				dist[i][c[j]][c[k]] = abs(j - k);
			}
		}
	}
	
	auto uses = make<int>(0, n, n);
	for (int i = 0; i < s.length() - 1; i++) {
		int from = s[i] - '1', to = s[i + 1] - '1';
		uses[from][to]++;
	}

	int ans = INF;
	for (int i = 0; i < perms.size(); i++) {
		int maybe_ans = s.length();
		if (s[0] - '1' != perms[i][0]) {
			maybe_ans += dist[i][perms[i][0]][s[0] - '1'];
		}
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				maybe_ans += uses[j][k] * dist[i][j][k];
			}
		}
		ans = min(maybe_ans, ans);
	}
	cout << ans << "\n";
}
