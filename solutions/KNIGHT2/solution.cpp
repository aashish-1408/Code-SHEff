#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A knight's move changes the parity of the sum of its coordinates (X + Y).
 * Specifically, a knight moves from (x, y) to (x±1, y±2) or (x±2, y±1).
 * In each move, the sum of coordinates changes by (±1 ± 2) = ±3 or ±1.
 * In all cases, the parity of (X + Y) changes every move.
 * 
 * After 100 moves (an even number of moves), the parity of (X1 + Y1) must be 
 * the same as the parity of (X2 + Y2).
 * 
 * Furthermore, on an 8x8 board, the knight can reach any square from any other 
 * square in a small number of moves (at most 6). Since 100 is much larger than 
 * the maximum distance and 100 is even, if the parity condition is met, 
 * the knight can always "waste" moves by jumping back and forth between two 
 * adjacent squares to reach the target in exactly 100 moves.
 * 
 * Parity condition: (X1 + Y1) % 2 == (X2 + Y2) % 2
 */

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // Check if the parity of the sum of coordinates is the same.
    // If (x1 + y1) and (x2 + y2) have the same parity, it is possible
    // to reach the destination in an even number of moves.
    if ((x1 + y1) % 2 == (x2 + y2) % 2) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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