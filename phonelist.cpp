#include <bits/stdc++.h>

using namespace std;

bool consistent = true;

struct Node {
    Node* children[10];
    bool is_end = false;

    Node() {
        memset(children, 0, sizeof(children));
    }
};

auto insert(Node* trie, const char* num) -> void {
    if (*num) {
        if (!trie->children[*num - '0']) {
            trie->children[*num - '0'] = new Node();
        }
        insert(trie->children[*num - '0'], num + 1);
    }
    else {
        trie->is_end = true;
    }
}

auto is_consistent(Node* trie) -> void {
    if (!trie->is_end) {
        for (int i = 0; i < 10; i++) {
            if (trie->children[i]) {
                is_consistent(trie->children[i]);
            }
        }
    }
    else {
        for (int i = 0; i < 10; i++) {
            if (trie->children[i]) {
                consistent = false;
                return;
            }
        }
    }
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
    
        cin.ignore();

        Node* trie = new Node();

        while (n--) {
            string num;
            getline(cin, num);
            insert(trie, num.c_str());
        }

        is_consistent(trie);

        cout << (consistent ? "YES" : "NO") << "\n";
        consistent = true;
    }
}
