#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef starts at X1 and moves at a speed of 1 unit/sec.
 * Friend starts at X2 and moves at a speed of 2 units/sec.
 * After 't' seconds:
 * Chef's position: P1(t) = X1 + t
 * Friend's position: P2(t) = X2 + 2t
 * 
 * They meet if there exists a non-negative integer 't' such that P1(t) = P2(t):
 * X1 + t = X2 + 2t
 * X1 - X2 = 2t - t
 * X1 - X2 = t
 * 
 * Since 't' must be a non-negative integer (t >= 0), the condition for them to meet is:
 * X1 - X2 >= 0
 * X1 >= X2
 * 
 * If X1 >= X2, they will meet at time t = X1 - X2.
 * If X1 < X2, the friend is already ahead and moving faster, so they will never meet.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x1, x2;
        cin >> x1 >> x2;

        // Based on the derivation X1 >= X2
        if (x1 >= x2) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}