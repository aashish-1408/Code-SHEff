#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice and Bob take turns multiplying their numbers by 2.
 * Total turns = N.
 * Alice takes turns 1, 3, 5, ...
 * Bob takes turns 2, 4, 6, ...
 * 
 * Number of turns Alice takes: ceil(N / 2.0)
 * Number of turns Bob takes: floor(N / 2.0)
 * 
 * Let A_final = A * 2^(ceil(N/2))
 * Let B_final = B * 2^(floor(N/2))
 * 
 * If N is even:
 *   Alice takes N/2 turns, Bob takes N/2 turns.
 *   A_final = A * 2^(N/2)
 *   B_final = B * 2^(N/2)
 *   Ratio = max(A, B) / min(A, B)
 * 
 * If N is odd:
 *   Alice takes (N+1)/2 turns, Bob takes (N-1)/2 turns.
 *   A_final = A * 2^((N+1)/2)
 *   B_final = B * 2^((N-1)/2)
 *   Ratio = max(A * 2, B) / min(A * 2, B)
 * 
 * Constraints: A, B, N up to 10^9.
 * Calculations should use long long.
 */

void solve() {
    long long A, B, N;
    cin >> A >> B >> N;

    long long alice_turns = (N + 1) / 2;
    long long bob_turns = N / 2;

    // We need to calculate (A * 2^alice_turns) and (B * 2^bob_turns)
    // Since we only need the ratio, we can simplify:
    // If N is even, ratio is A/B or B/A.
    // If N is odd, ratio is (A*2)/B or B/(A*2).
    
    if (N % 2 == 0) {
        if (A >= B) {
            cout << A / B << "\n";
        } else {
            cout << B / A << "\n";
        }
    } else {
        A *= 2;
        if (A >= B) {
            cout << A / B << "\n";
        } else {
            cout << B / A << "\n";
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