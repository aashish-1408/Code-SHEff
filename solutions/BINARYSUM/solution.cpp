#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A binary string of length N with no two adjacent digits equal must be alternating.
 * There are only two such strings:
 * 1. 010101... (starts with 0)
 * 2. 101010... (starts with 1)
 * 
 * Case 1: N is even (N = 2m)
 * - String 0101...01: Sum = m = N/2
 * - String 1010...10: Sum = m = N/2
 * Both strings have the same sum: N/2.
 * 
 * Case 2: N is odd (N = 2m + 1)
 * - String 0101...010: Sum = m = (N-1)/2
 * - String 1010...101: Sum = m + 1 = (N+1)/2
 * The possible sums are (N-1)/2 and (N+1)/2.
 * 
 * Conclusion:
 * If N is even, K must be equal to N/2.
 * If N is odd, K must be equal to (N-1)/2 or (N+1)/2.
 */

void solve() {
    int N, K;
    cin >> N >> K;

    if (N % 2 == 0) {
        if (K == N / 2) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    } else {
        if (K == (N - 1) / 2 || K == (N + 1) / 2) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
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