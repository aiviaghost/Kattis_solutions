#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

const int INF = 2e9;

inline auto m_dist(pii p1, pii p2) -> int {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    
    int R, C, F, S, G;
    cin >> R >> C >> F >> S >> G;
    vector<vector<pii>> faculty_spots(F);
    for (int f = 0; f < F; f++) {
        int K;
        cin >> K;
        faculty_spots[f].reserve(K);
        for (int k = 0; k < K; k++) {
            int r, c;
            cin >> r >> c, r--, c--;
            faculty_spots[f].push_back({r, c});
        }
        sort(faculty_spots[f].begin(), faculty_spots[f].end(), greater<pii>());
    }

    vector<vector<tuple<int, int, int>>> students(F);
    for (int s = 0; s < S; s++) {
        int r, c, D, f;
        cin >> r >> c >> D >> f, r--, c--, f--;
        students[f].push_back({D, r, c});
    }
    for (int i = 0; i < F; i++) {
        sort(students[i].begin(), students[i].end());
    }

    vector<int> compliance_targets;
    compliance_targets.reserve(F);
    for (int f = 0; f < F; f++) {
        int t;
        cin >> t;
        compliance_targets.push_back(t);
    }

    vector<ll> faculty_distances;
    faculty_distances.reserve(F);
    for (int f = 0; f < F; f++) {
        vector<int> distances;
        distances.reserve(students[f].size());
        int next_available_index = faculty_spots[f].size() - 1;
        for (int s = 0; s < students[f].size(); s++) {
            pii next_available = faculty_spots[f][next_available_index];
            next_available_index--;
            distances.push_back(m_dist(next_available, {get<1>(students[f][s]), get<2>(students[f][s])}));
        }
        sort(distances.begin(), distances.end());
        ll faculty_distance = 0;
        for (int i = 0; i < compliance_targets[f]; i++) {
            faculty_distance += distances[i];
        }
        faculty_distances.push_back(faculty_distance);
    }

    sort(faculty_distances.begin(), faculty_distances.end());
    ll total_distance = 0;
    for (int i = 0; i < G; i++) {
        total_distance += faculty_distances[i];
    }

    cout << total_distance << "\n";
}
