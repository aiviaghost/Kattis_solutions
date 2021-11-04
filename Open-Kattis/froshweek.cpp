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

struct segment_tree {
    segment_tree *left = 0, *right = 0;
    int lb, rb, val = 0;
    segment_tree(int lb, int rb): lb(lb), rb(rb) {
        if (lb != rb) {
            int mid = lb + (rb - lb) / 2;
            left = new segment_tree(lb, mid);
            right = new segment_tree(mid + 1, rb);
        }
    }

    void insert(int index) {
        if (lb > index || rb < index) {
            return;
        }

        if (lb == rb) {
            val = 1;
            return;
        }

        if (left->lb <= index && index <= left->rb) {
            left->insert(index);
        }
        else {
            right->insert(index);
        }

        val = left->val + right->val;
    }

    int query(int lb) {
        if (this->rb < lb) {
            return 0;
        }

        if (lb <= this->lb || this->lb == this->rb) {
            return val;
        }

        return left->query(lb) + right->query(lb);
    }
};

auto main() -> int {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> inds(n);
	iota(inds.begin(), inds.end(), 0);
	sort(inds.begin(), inds.end(), [&](int i, int j) {
		return a[i] < a[j];
	});
	ll ans = 0;
	segment_tree *tree = new segment_tree(0, n);
	for (int i : inds) {
		tree->insert(i);
		ans += tree->query(i + 1);
	}
	cout << ans << "\n";
}
