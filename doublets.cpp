#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
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
        if (!trie->is_root) {   
            trie->has_letter = true;
            trie->letter = *word;
        }

        if (!trie->children[*word - 'a']) {
            trie->children[*word - 'a'] = new Node(false);
        }

        if (trie->is_root) {
            insert(trie->children[*word - 'a'], word, full_word);
        }
        else {
            insert(trie->children[*word - 'a'], word + 1, full_word);
        }
    }
    else {
        trie->is_end = true;
        trie->full_word = full_word;
    }
}

auto get_neighbours(Node* trie, const char* word, int diff_so_far = 0) -> void {
    cout << "actual: " << *word << " diff: " << trie->letter << ", diff so far: " << diff_so_far << "\n";
    if (*word) {
        if (trie->has_letter && trie->letter != *word) {
            diff_so_far++;
        }

        for (int i = 0; i < 26; i++) {
            if (trie->children[i]) {
                if (trie->is_root) {
                    get_neighbours(trie->children[i], word, diff_so_far);
                }
                else {
                    get_neighbours(trie->children[i], word + 1, diff_so_far);
                }
            }
        }
    }
    else if (trie->is_end && diff_so_far == 1) {
        cout << trie->full_word << " is valid!\n";
        neighbours.push_back(trie->full_word);
    }
    else {
        cout << "not valid!\n";
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
    // cin.tie(0)->sync_with_stdio(0);

    Node* trie = new Node(true);

    string word;
    while (getline(cin, word) && word != "") {
        insert(trie, word.c_str(), word);
    }
    /*
    cout << "root: " << trie->letter << "\n";
    for (int i = 0; i < 26; i++) {
        if (trie->children[i]) {
            cout << "children of root: " << trie->children[i]->letter << "\n";
        }
    }
    */
    // query each pair:
    string query;
    while (getline(cin, query)) {
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
                cout << "search: " << c << "\n";
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
        
        for (auto itr = dist.begin(); itr != dist.end(); itr++) {
            cout << "dist: " << itr->first << " " << itr->second << "\n";
        }
        
        if (dist[s2] != INF) {
            vector<string> path;
            string parent = parents[s2];
            while (parent != s1) {
                path.push_back(parent);
                parent = parents[parent];
            }

            cout << s1 << "\n";
            for (int i = path.size() - 1; i >= 0; i++) {
                cout << path[i] << "\n";
            }
            cout << s2 << "\n";
        }
        else {
            cout << "No solution." << "\n";
        }
        
    }
}
