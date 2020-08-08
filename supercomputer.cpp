#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
    segment_tree *left, *right;
    int state, value, l_bound, r_bound;
    bool is_leaf = false;
    segment_tree(int l_bound, int r_bound): l_bound(l_bound), r_bound(r_bound), left(NULL), right(NULL), state(0), value(0) { }
};

auto dfs(segment_tree *tree) -> void {
    cout << "l: " << tree->l_bound << ", r: " << tree->r_bound << ", state: " << tree->state << ", val: " << tree->value << "\n";
    dfs(tree->left);
    dfs(tree->right);
}

auto build_seg_tree(int l, int r) -> segment_tree* {
    if (l > r) {
        return NULL;
    }

    segment_tree *tree = new segment_tree(l, r);
    cout << tree->l_bound << " " << tree->r_bound << endl;

    if (l == r) {
        tree->is_leaf = true;
    }
    else {
        int mid = (l + r) / 2;
        tree->left = build_seg_tree(l, mid);
        tree->right = build_seg_tree(mid + 1, r);
    }

    return tree;
}

auto query(segment_tree *tree, int l, int r) -> int {
    if (tree == NULL) {
        return 0;
    }

    if (tree->l_bound <= l && r <= tree->r_bound) {
        return tree->value;
    }

    if (tree->l_bound > r) {
        return 0;
    }

    if (tree->r_bound < l) {
        return 0;
    }

    return query(tree->left, l, r) + query(tree->right, l, r);
}

auto update(segment_tree *tree, int index) -> int {
    if (tree == NULL) {
        return 0;
    }

    if (tree->l_bound > index) {
        return 0;
    }

    if (tree->r_bound < index) {
        return 0;
    }

    if (tree->l_bound == tree->r_bound && tree->l_bound == index) {
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
    // cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    segment_tree *seg_tree = build_seg_tree(1, n);
    dfs(seg_tree);
    
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
