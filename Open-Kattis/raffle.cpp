#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

template <typename T> vector<T> make(T init, size_t size) { return vector<T>(size, init); }
template <typename T, typename... Args> auto make(T init, size_t first, Args... sizes) {
    auto inner = make<T>(init, sizes...);
    return vector<decltype(inner)>(first, inner);
}

#define all(x) x.begin(), x.end()

const int INF = 2e9;
const int MOD = 1e9 + 7;

/*

Consider the case of n = 4, p = 3 and you choose to add you name C times. 
Lets say C = 2, but the solutions generalizes easily to arbitrary C.
There are 3 outcomes where you win, they are (L = someone elses name got drawn, W = your name got drawn):

W L L L L L
L W L L L L
L L W L L L

And the probability you actually win with C = 2 is the sum of the probabilites of each of the above 
scenarios happening. You can write a long formula to descibe this sum but the key is to notice the 
pattern of adding an L on the left of the W and removing one L from the right. This leads to noting 
that at each step the probability changes by some factor so we can loop over the P different winning 
scenarios (there are P of them since any other sequences of the same length would result in your name 
being drawn multiple times within the first p draws (not a win) or your name not being drawn at all, 
obviously not a win) and keep a running sum over the probabilites. At each step we update the running 
sum and the running probability for the current sequence. This will yield a query function with time 
complexity O(p), but with quite a large constant factor, see below implementation for a concrete example.

double prob(int n, int p, int c) {
    double cp = 1;
    for (int i = 0; i <= p - 2; i++) {
        cp *= (n - c - i) / (double) (n - i - 1);
    }
    double P = (c / (double) n) * cp, curr = P;
    for (int i = 1; i <= p - 1; i++) {
        curr /= (c / (double) (n - (i - 1)));
        curr *= (c / (double) (n - i));
        curr /= (n - c - (i - 1)) / (double) (n - 1 - (i - 1));
        curr *= (n - c - (i - 1)) / (double) (n - (i - 1));
        P += curr;
    }
    return (isnan(P) ? 0 : P);
}

We can however notice that a lot of these terms cancel-out and in the end the function above can be 
reduced to the "accepted" function in the code below this comment. 

All that is left is to use this query function in a ternary search to efficiently traverse the possible 
choices. I don't have a great proof for why a ternary search works here but my intuitions tells me the 
probability distribution is unimodal.
*/

double prob(int n, int p, int c) {
    double cp = 1;
    for (int i = 0; i <= p - 2; i++) {
        cp *= (n - c - i) / (double) (n - i - 1);
    }
    double P = (c / (double) n) * cp * p;
    return (isnan(P) ? 0 : P);
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, p;
    cin >> n >> p;
    int lb = 0, rb = n;
    for (int i = 0; i < 34; i++) {
        int part = (rb - lb) / 3;
        int p1 = lb + part, p2 = rb - part;
        double q1 = prob(n + p1, p, p1), q2 = prob(n + p2, p, p2);
        if (q1 >= q2) {
            rb = p2 - 1;
        }
        else {
            lb = p1 + 1;
        }
    }
    cout << fixed << setprecision(11) << prob(n + lb, p, lb) << "\n";
}
