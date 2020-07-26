#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

vector<string> neighbours;

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

auto get_neighbours(Node* trie, const string& word, int index = 0, int diff_so_far = 0) -> void {
    if (!trie->is_root) {
        if (index >= word.length()) {
            return;
        }

        if (trie->has_letter && trie->letter != word[index]) {
            diff_so_far++;
        }

        // cout << "searhech letter: " << word[index] << ", trie-letter: " << trie->letter << ", diff so far: " << diff_so_far << "\n";

        if (diff_so_far > 1) {
            // cout << "invalid!\n";
            return;
        }

        if (trie->is_end && diff_so_far == 1) {
            // cout << trie->full_word << " is valid!\n";
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

/*
auto contains(Node* trie, const char* word) -> bool {
    if (*word) {
        if (!trie->children[*word - 'a']) {
            return false;
        }
        return contains(trie->children[*word - 'a'], word + 1);
    }
    else {
        return trie->is_end;
    }
}
*/

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    Node* trie = new Node(true);

    string word;
    while (getline(cin, word) && word != "") {
        insert(trie, word.c_str(), word);
    }
    /*
    cout << "root: " << (trie->has_letter ? "yes" : "no") << "\n";
    for (int i = 0; i < 26; i++) {
        if (trie->children[i]) {
            cout << "children of root: " << trie->children[i]->letter << "\n";
        }
    }
    */
    // query each pair:
    string query;
    int t = 0;
    while (getline(cin, query)) {
        if (t != 0) {
            cout << "\n";
        }
        t++;

        string s1 = query.substr(0, query.find(' ')), s2 = query.substr(query.find(' ') + 1);

        /*
        get_neighbours(trie, s1.c_str());
        for (string s : neighbours) {
            cout << s << " ";
        }
        cout << "\n";
        neighbours.clear();
        */
        
        unordered_map<string, int> dist;
        dist[s1] = 0;
        dist[s2] = INF;
        unordered_set<string> vis{s1};
        vector<string> curr_layer{s1};
        unordered_map<string, string> parents;

        while (!curr_layer.empty()) {
            vector<string> next_layer;
            for (string c : curr_layer) {
                neighbours.clear();
                // cout << "search: " << c << "\n";
                get_neighbours(trie, c.c_str());
                for (string n : neighbours) {
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
        /*
        for (auto itr = dist.begin(); itr != dist.end(); itr++) {
            cout << "dist: " << itr->first << " " << itr->second << "\n";
        }
        */
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
