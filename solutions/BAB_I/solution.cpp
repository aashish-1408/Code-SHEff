#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the maximum non-negative integer X such that for all A_i,
 * A_i is not in [-X, X].
 * This means for all i, |A_i| > X.
 * 
 * Let B_i = |A_i|. The condition becomes B_i > X for all i.
 * This is equivalent to X < min(|A_i|).
 * 
 * If we pick X = min(|A_i|) - 1, then for all i, |A_i| >= min(|A_i|),
 * so |A_i| > min(|A_i|) - 1 is satisfied.
 * 
 * However, there is a constraint: 0 is in the range [-X, X] for any X >= 0.
 * If any A_i = 0, then |A_i| = 0. The condition |A_i| > X becomes 0 > X.
 * Since X must be non-negative (X >= 0), there is no such X if 0 is in the array.
 * 
 * Also, if min(|A_i|) - 1 < 0, then no non-negative X exists.
 * This happens if min(|A_i|) = 0 (i.e., 0 is in the array).
 * 
 * Thus, the algorithm is:
 * 1. Find the minimum absolute value in the array.
 * 2. If 0 is present, output -1.
 * 3. Otherwise, output min(|A_i|) - 1.
 */

void solve() {
    int n;
    cin >> n;
    long long min_abs = 2e9; // Larger than any possible |A_i|
    bool has_zero = false;

    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        if (a == 0) {
            has_zero = true;
        }
        long long abs_a = abs(a);
        if (abs_a < min_abs) {
            min_abs = abs_a;
        }
    }

    if (has_zero) {
        cout << -1 << "\n";
    } else {
        cout << min_abs - 1 << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}