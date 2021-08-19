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
    segment_tree *left, *right;
    int value = 0, lb, rb;
    segment_tree(int lb, int rb) : lb(lb), rb(rb), left(NULL), right(NULL) {
        if (lb < rb) {
            int mid = lb + (rb - lb) / 2;
            left = new segment_tree(lb, mid);
            right = new segment_tree(mid + 1, rb);
        }
    }
};

auto query(segment_tree *tree, int l, int r) -> int {
    if (tree == NULL) {
        return 0;
    }

    if (l <= tree->lb && tree->rb <= r) {
        return tree->value;
    }

    if (tree->rb < l) {
        return 0;
    }

    if (tree->lb > r) {
        return 0;
    }

    return __gcd(query(tree->left, l, r), query(tree->right, l, r));
}

auto update(segment_tree *tree, int index, int new_val) -> int {
    if (tree == NULL) {
        return 0;
    }
    
    if (tree->lb > index || tree->rb < index) {
        return tree->value;
    }

    if (tree->lb == tree->rb && tree->lb == index) {
        tree->value = new_val;
    }
    else {
        tree->value = __gcd(update(tree->left, index, new_val), update(tree->right, index, new_val));
    }

    return tree->value;
}

auto main() -> int {
	cin.tie(0)->sync_with_stdio(0);

	int n, q;
	cin >> n >> q;
	segment_tree *seg_tree = new segment_tree(1, n);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		update(seg_tree, i, x);
	}
	for (int i = 0; i < q; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 1) {
			update(seg_tree, y, z);
		}
		else {
			cout << query(seg_tree, y, z) << "\n";
		}
	}
}
