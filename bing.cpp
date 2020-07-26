#include <bits/stdc++.h>

using namespace std;

int number_containing = 0;

struct Node {
    Node* children[26];
    int freq = 0;
    
    Node() {
        memset(children, 0, sizeof(children));
    }
};

auto insert(Node* trie, const string& word) -> void {
    for (char c : word) {
        if (!trie->children[c - 'a']) {
            trie->children[c - 'a'] = new Node();
        }
        trie = trie->children[c - 'a'];
    }
    trie->freq++;
}

auto contains(Node* trie, const char* word) -> void {
    if (*word) {
        if (!trie->children[*word - 'a']) {
            return;
        }
        contains(trie->children[*word - 'a'], word + 1);
    }
    else {
        number_containing += trie->freq;
        
        for (int i = 0; i < 26; i++) {
            if (trie->children[i]) {
                contains(trie->children[i], word);
            }
        }
    }
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    cin.ignore();

    Node* trie = new Node();

    while (n--) {
        string word;
        getline(cin, word);

        contains(trie, word.c_str());
        cout << number_containing << "\n";
        number_containing = 0;

        insert(trie, word);
    }
}

