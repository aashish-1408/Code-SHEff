#include <bits/stdc++.h>
using namespace std;

/**
 * Game Analysis:
 * - If N is 1: Proper divisors are none. Alice cannot move. BOB wins.
 * - If N is 2: Proper divisor is 1. Alice subtracts 1, N becomes 1. Bob cannot move. ALICE wins.
 * - If N is 3: Proper divisor is 1. Alice subtracts 1, N becomes 2. Bob subtracts 1, N becomes 1. BOB wins.
 * - If N is 4: Proper divisors are 1, 2. Alice can subtract 2 to make N=2. Then Bob must subtract 1 to make N=1. ALICE wins.
 * - If N is even: Alice can always subtract 1 to make N odd.
 * - If N is odd: Any proper divisor of an odd number must be odd. Subtracting an odd divisor from an odd number results in an even number.
 * 
 * Pattern:
 * - If N is even, Alice can subtract 1 to make it odd.
 * - If N is odd, any move leads to an even number.
 * - Specifically, if N is even, Alice can always win.
 * - If N is odd, Alice is forced to give Bob an even number, and Bob can then win.
 * 
 * Exception: N=1 is odd and Bob wins.
 * For N > 1:
 * If N is even, Alice wins.
 * If N is odd, Bob wins.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;
        
        // If N is even, Alice wins.
        // If N is odd, Bob wins.
        if (n % 2 == 0) {
            cout << "ALICE" << "\n";
        } else {
            cout << "BOB" << "\n";
        }
    }
    return 0;
}