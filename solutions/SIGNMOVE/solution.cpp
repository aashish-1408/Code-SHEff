#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let P(i) be the position after i steps.
 * P(0) = 0
 * i=1: P(0) >= 0, so P(1) = 0 - 1 = -1
 * i=2: P(1) < 0, so P(2) = -1 + 2 = 1
 * i=3: P(2) >= 0, so P(3) = 1 - 3 = -2
 * i=4: P(3) < 0, so P(4) = -2 + 4 = 2
 * i=5: P(4) >= 0, so P(5) = 2 - 5 = -3
 * i=6: P(5) < 0, so P(6) = -3 + 6 = 3
 * 
 * Pattern observed:
 * If N is even, P(N) = N / 2
 * If N is odd, P(N) = -(N + 1) / 2
 * 
 * Constraints: N up to 10^9, T up to 10^5.
 * The O(1) approach per test case is optimal.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;
        
        if (n % 2 == 0) {
            cout << (n / 2) << "\n";
        } else {
            cout << -((n + 1) / 2) << "\n";
        }
    }
    return 0;
}