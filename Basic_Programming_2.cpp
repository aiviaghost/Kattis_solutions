#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, t;
    cin >> N >> t;
    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    if (t == 1) {
        set<int> complements;
        bool found = false;
        for (int i = 0; i < N; i++) {
            int diff = 7777 - A[i];
            if (complements.find(diff) != complements.end()) {
                found = true;
                break;
            }
            else {
                complements.emplace(A[i]);
            }
        }
        cout << (found ? "Yes" : "No") << "\n";
    }
    else if (t == 2) {
        set<int> unique;
        bool is_unique = true;
        for (int i = 0; i < N; i++) {
            if (unique.find(A[i]) != unique.end()) {
                is_unique = false;
                break;
            }
            else {
                unique.emplace(A[i]);
            }
        }
        cout << (is_unique ? "Unique" : "Contains duplicate") << "\n";
    }
    else if (t == 3) {
        unordered_map<int, int> count;
        for (int i = 0; i < N; i++) {
            if (count.find(A[i]) != count.end()) {
                count.at(A[i]) = count.at(A[i]) + 1;
            }
            else {
                count.emplace(A[i], 1);
            }
        }

        int found_int = -1;
        unordered_map<int, int>:: iterator itr;
        for (itr = count.begin(); itr != count.end(); itr++) {
            if (itr->second > N / 2) {
                found_int = itr->first;
                break;
            }
        }
        cout << found_int << "\n";
    }
    else if (t == 4) {
        sort(A.begin(), A.begin() + N);

        if ((N & 1) == 0) {
            cout << A[N / 2 - 1] << " " << A[N / 2] << "\n";
        }
        else {
            cout << A[N / 2] << "\n";
        }
    }
    else if (t == 5) {
        sort(A.begin(), A.begin() + N);

        string out = "";
        for (int i = 0; i < N; i++) {
            if (100 <= A[i] && A[i] <= 999) {
                out += to_string(A[i]) + " ";
            }
        }

        if (out != "") {
            out.pop_back();
            cout << out << "\n";
        }
    }

    return 0;
}
