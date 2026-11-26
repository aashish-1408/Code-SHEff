#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let N = 2^k * m, where m is an odd integer.
 * The odd divisors of N are exactly the divisors of m.
 * Let d(m) be the number of divisors of m. Then A = d(m).
 * Since m is a positive integer, d(m) must be at least 1.
 * Thus, if A = 0, it is impossible (since 1 is always an odd divisor).
 * 
 * The even divisors of N are of the form 2^i * d, where 1 <= i <= k and d is a divisor of m.
 * The number of such divisors is k * d(m) = k * A.
 * So, B = k * A.
 * 
 * Case 1: A = 0.
 * Impossible, because 1 is always an odd divisor. Output: No.
 * 
 * Case 2: A > 0.
 * We need to check if there exists an integer k >= 0 such that B = k * A.
 * If k = 0, then B = 0. This is possible (N = m).
 * If k > 0, then B must be a multiple of A.
 * 
 * Summary:
 * - If A == 0: No
 * - Else if B == 0: Yes (k=0)
 * - Else if B % A == 0: Yes
 * - Else: No
 */

void solve() {
    long long A, B;
    cin >> A >> B;

    if (A == 0) {
        cout << "No" << "\n";
    } else {
        if (B == 0) {
            cout << "Yes" << "\n";
        } else {
            if (B % A == 0) {
                cout << "Yes" << "\n";
            } else {
                cout << "No" << "\n";
            }
        }
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