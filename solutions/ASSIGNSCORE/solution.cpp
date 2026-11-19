#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total assignments = N + 1.
 * Each assignment is out of 100 marks.
 * Total possible marks = (N + 1) * 100.
 * Passing criteria: Score >= 50% of total marks.
 * Passing marks = 0.5 * (N + 1) * 100 = 50 * (N + 1).
 * 
 * Let S be the sum of the first N assignments.
 * Let X be the score of the (N+1)-th assignment.
 * We need: S + X >= 50 * (N + 1)
 * Therefore: X >= 50 * (N + 1) - S
 * 
 * Constraints:
 * 0 <= X <= 100
 * If the calculated X > 100, it's impossible (-1).
 * If the calculated X < 0, it means Chef already has enough marks, so he needs 0.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            sum += a;
        }

        // Target total marks needed to pass
        long long target = 50LL * (n + 1);
        
        // Minimum score needed on the last assignment
        long long needed = target - sum;

        if (needed > 100) {
            // Even with 100, he cannot reach the target
            cout << -1 << "\n";
        } else if (needed < 0) {
            // He already has more than 50%
            cout << 0 << "\n";
        } else {
            // He needs exactly 'needed' marks
            cout << needed << "\n";
        }
    }

    return 0;
}