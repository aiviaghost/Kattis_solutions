#include <bits/stdc++.h>

using namespace std;

int Find(vector<int> &parents, int x) {
    if (parents[x] == x) {
        return x;
    }
    else {
        parents[x] = Find(parents, parents[x]);
        return parents[x];
    }
}

void Union(vector<int> &ranks, vector<int> &parents, int &x, int &y) {
    int xRoot = Find(parents, x);
    int yRoot = Find(parents, y);
    if (ranks[xRoot] > ranks[yRoot]) {
        parents[yRoot] = xRoot;
    }
    else if (ranks[xRoot] < ranks[yRoot]) {
        parents[xRoot] = yRoot;
    }
    else if (xRoot != yRoot) {
        parents[yRoot] = xRoot;
        ranks[xRoot] = ranks[xRoot] + 1;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<int> ranks(n + 1), parents(n + 1);

    for (int i = 1; i <= n; i++) {
        parents[i] = i;
    }

    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        Union(ranks, parents, x, y);
    }

    vector<int> houses;
    for (int i = 2; i <= n; i++) {
        if (Find(parents, i) != Find(parents, 1)) {
            houses.push_back(i);
        }
    }
    sort(houses.begin(), houses.begin() + houses.size());

    if (houses.size() == 0) {
        cout << "Connected\n";
    }
    else {
        for (int i = 0; i < houses.size(); i++) {
            cout << houses[i] << "\n";
        }
    }

    return 0;
}
