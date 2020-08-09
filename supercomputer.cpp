#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
    segment_tree *left, *right;
    int state = 0, value = 0, lb, rb;
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

    return query(tree->left, l, r) + query(tree->right, l, r);
}

auto update(segment_tree *tree, int index) -> int {
    if (tree == NULL) {
        return 0;
    }
    
    if (tree->lb > index || tree->rb < index) {
        return tree->value;
    }

    if (tree->lb == tree->rb && tree->lb == index) {
        tree->state = 1 - tree->state;

        if (tree->state == 1) {
            tree->value++;
        }
        else {
            tree->value--;
        }
    }
    else {
        tree->value = update(tree->left, index) + update(tree->right, index);
    }

    return tree->value;
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    segment_tree *seg_tree = new segment_tree(1, n);
    
    while (k--) {
        char op;
        cin >> op;

        if (op == 'F') {
            int pos;
            cin >> pos;
            update(seg_tree, pos);
        }
        else {
            int spos, epos;
            cin >> spos >> epos;
            cout << query(seg_tree, spos, epos) << "\n";
        }
    }
}
