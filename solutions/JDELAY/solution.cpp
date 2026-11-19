#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Judging Delay
 * Approach:
 * For each submission, the delay is calculated as (J_i - S_i).
 * We need to count how many submissions have (J_i - S_i) > 5.
 * Given the constraints (N <= 100, T <= 100), a simple O(N) loop per test case
 * is well within the time limit.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    int count = 0;
    for (int i = 0; i < N; ++i) {
        int S, J;
        cin >> S >> J;
        // The delay is J - S. We check if it is strictly greater than 5.
        if ((J - S) > 5) {
            count++;
        }
    }
    cout << count << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    
    return 0;
}