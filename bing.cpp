#include <bits/stdc++.h>

using namespace std;

int number_containing = 0;

struct Node {
    Node* children[26];
    bool is_end = false;
    int freq = 0;
    
    Node() {
        memset(children, 0, sizeof(children));
    }
};

auto insert(Node* trie, const char* word) -> void {
    if (*word) {
        if (!trie->children[*word - 'a']) { // subtracting ascii 'a' converts characters a-z to ints 0-25
            trie->children[*word - 'a'] = new Node();
        }
        insert(trie->children[*word - 'a'], word + 1); // word is a char-pointer so (word + 1) is the next char in the string
    }
    else {
        trie->freq++;
        trie->is_end = true; // end of word
    }
}

auto contains(Node* trie, const char* word) -> void {
    if (*word) {
        if (!trie->children[*word - 'a']) {
            return;
        }
        contains(trie->children[*word - 'a'], word + 1);
    }
    else {
        if (trie->is_end) {
            number_containing += trie->freq;
        }
        
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

        insert(trie, word.c_str());
    }
}
