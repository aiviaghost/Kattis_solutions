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

struct Segment_Tree {
	Segment_Tree *left = 0, *right = 0;
	int lb, rb, val = 0;

	Segment_Tree(int lb, int rb) : lb(lb), rb(rb) {
		if (lb != rb) {
			int mid = lb + (rb - lb) / 2;
			left = new Segment_Tree(lb, mid);
			right = new Segment_Tree(mid + 1, rb);
		}
	}

	void update(int index) {
		if (index < lb || rb < index) {
			return;
		}

		if (lb == rb) {
			val = 1;
			return;
		}

		if (left->lb <= index && index <= left->rb) {
			left->update(index);
		}
		else {
			right->update(index);
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
	iota(all(inds), 0);
	sort(all(inds), [&](int i, int j) {
		return a[i] < a[j];
	});
	Segment_Tree *seg_tree = new Segment_Tree(0, n - 1);
	ll inversions = 0;
	for (int i : inds) {
		seg_tree->update(i);
		inversions += seg_tree->query(i + 1);
	}
	cout << inversions <<  "\n";
}
