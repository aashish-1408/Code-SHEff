#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The allowed moves are:
 * (i+1, j+1), (i+1, j-1), (i-1, j+1), (i-1, j-1).
 * 
 * Notice that in every move, the parity of the sum of coordinates (x + y) 
 * changes as follows:
 * Let the current sum be S = i + j.
 * New sum S' = (i ± 1) + (j ± 1).
 * Possible values for S':
 * (i+1) + (j+1) = i + j + 2 = S + 2
 * (i+1) + (j-1) = i + j = S
 * (i-1) + (j+1) = i + j = S
 * (i-1) + (j-1) = i + j - 2 = S - 2
 * 
 * In all cases, the parity of (i + j) remains the same as the parity of (0 + 0) = 0.
 * Therefore, for a point (x, y) to be reachable, (x + y) must be even.
 * 
 * Is this condition sufficient?
 * Yes. If (x + y) is even, then x and y have the same parity (both even or both odd).
 * We can reach any (x, y) where x+y is even by moving diagonally.
 * Specifically, we can reach any (x, y) such that |x| + |y| is even and the 
 * parity of x and y matches.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        // The condition for reachability is that the sum of coordinates is even.
        // We use abs() to handle negative coordinates correctly, though 
        // (x + y) % 2 == 0 works for negative numbers in C++ as well.
        if (abs(x + y) % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}