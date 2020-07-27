#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

vector<string> neighbours;

// node-struct for trie
struct Node {
    Node* children[26];
    bool is_end = false, has_letter = false, is_root;
    char letter;
    string full_word;

    Node(bool is_root) {
        memset(children, 0, sizeof(children));
        this->is_root = is_root;
    }
};

// create trie from words and assign letters to each node along the way to use while searching later (to create adj list)
auto insert(Node* trie, const char* word, const string& full_word) -> void {
    if (*word) {
        if (!trie->children[*word - 'a']) {
            trie->children[*word - 'a'] = new Node(false);
            trie->children[*word - 'a']->has_letter = true;
            trie->children[*word - 'a']->letter = *word;
        }
        insert(trie->children[*word - 'a'], word + 1, full_word);
    }
    else {
        trie->is_end = true;
        trie->full_word = full_word;
    }
}

// search recursively to find all words that differ by one character
auto get_neighbours(Node* trie, const string& word, int index = 0, int diff_so_far = 0) -> void {
    if (!trie->is_root) {
        if (index >= word.length()) {
            return;
        }

        if (trie->has_letter && trie->letter != word[index]) {
            diff_so_far++;
        }

        if (diff_so_far > 1) {
            return;
        }

        if (trie->is_end && diff_so_far == 1 && trie->full_word.length() == word.length()) {
            neighbours.push_back(trie->full_word);
            return;
        }

        index++;

        for (int i = 0; i < 26; i++) {
            if (trie->children[i]) {
                get_neighbours(trie->children[i], word, index, diff_so_far);
            }
        }
    }
    else {
        for (int i = 0; i < 26; i++) {
            if (trie->children[i]) {
                get_neighbours(trie->children[i], word, index, diff_so_far);
            }
        } 
    }
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    Node* trie = new Node(true);

    vector<string> words;
    string word;
    while (getline(cin, word) && word != "") {
        words.push_back(word);
        insert(trie, word.c_str(), word);
    }

    unordered_map<string, vector<string>> adj;
    for (string w : words) { // generate adjacency list
        get_neighbours(trie, w);
        adj[w] = neighbours;
        neighbours.clear();
    }
    
    string query;
    int t = 0;
    while (getline(cin, query)) {
        if (t != 0) {
            cout << "\n";
        }
        t++;

        string s1 = query.substr(0, query.find(' ')), s2 = query.substr(query.find(' ') + 1);
        
        unordered_map<string, int> dist;
        dist[s1] = 0;
        dist[s2] = INF;
        unordered_set<string> vis{s1};
        vector<string> curr_layer{s1};
        unordered_map<string, string> parents;

        // bfs from s1, use adj to find neighbours
        while (!curr_layer.empty()) {
            vector<string> next_layer;
            for (string c : curr_layer) {
                for (string n : adj[c]) {
                    if (vis.find(n) == vis.end()) {
                        parents[n] = c;
                        vis.emplace(n);
                        dist[n] = dist[c] + 1;
                        next_layer.push_back(n);
                    }
                }
            }
            curr_layer = next_layer;
        }

        if (dist[s2] != INF) {
            vector<string> path;
            string parent = parents[s2];
            while (parent != s1) {
                path.push_back(parent);
                parent = parents[parent];
            }

            cout << s1 << "\n";
            for (int i = path.size() - 1; i >= 0; i--) {
                cout << path[i] << "\n";
            }
            cout << s2 << "\n";
        }
        else {
            cout << "No solution." << "\n";
        }
        
    }
}
