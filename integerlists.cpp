#include <bits/stdc++.h>

using namespace std;

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    cin.ignore();

    while (T--) {
        string p;
        getline(cin, p);

        int n;
        cin >> n;

        cin.ignore();

        list<int> nums;
        string in_nums;
        getline(cin, in_nums);
        in_nums = in_nums.substr(1, in_nums.length() - 2);
        istringstream iss{in_nums};
        for (string s; getline(iss, s, ','); nums.push_back(stoi(s)));
        
        bool is_rev = false, error = false;
        for (char op : p) {
            if (op == 'R') {
                is_rev = !is_rev;
            }
            else {
                if (nums.empty()) {
                    error = true;
                    break;
                }

                if (!is_rev) {
                    nums.pop_front();
                }
                else {
                    nums.pop_back();
                }
            }
        }

        if (error) {
            cout << "error\n";
        }
        else {
            string out = "[";
            if (!is_rev) {
                for (list<int>::iterator itr = nums.begin(); itr != nums.end(); itr++) {
                    out += to_string(*itr) + ",";
                }
            }
            else {
                for (list<int>::reverse_iterator itr = nums.rbegin(); itr != nums.rend(); itr++) {
                    out += to_string(*itr) + ",";
                }
            }
            if (out != "["){
                out.pop_back();
            }
            out += "]";

            cout << out << "\n";
        }
    }
}
