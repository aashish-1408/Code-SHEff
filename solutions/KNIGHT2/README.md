# [Journey of the Knight (KNIGHT2)](https://www.codechef.com/problems/KNIGHT2)

- **Difficulty Rating**: 1144
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks whether a knight can travel from a starting square $(x_1, y_1)$ to a target square $(x_2, y_2)$ on an $8 \times 8$ chessboard in **exactly 100 moves**.

## Intuition & Mathematical Observation
The key to this problem lies in the properties of a knight's movement on a chessboard:

1.  **Parity of Moves**: A knight's move always changes the color of the square it is on. On a standard chessboard, this means that if the sum of the coordinates $(x + y)$ is even, the knight is on one color; if it is odd, it is on the other.
2.  **Coordinate Sum Parity**: Every move a knight makes changes the sum of its coordinates by an odd number ($\pm 1 \pm 2 = \pm 3$ or $\pm 1$). Therefore, after every move, the parity of $(x + y)$ flips.
3.  **The 100-Move Constraint**: Since 100 is an **even** number, the knight must end up on a square that has the same coordinate sum parity as the starting square. If $(x_1 + y_1)$ and $(x_2 + y_2)$ have different parities, it is impossible to reach the target in an even number of moves.
4.  **Reachability**: On an $8 \times 8$ board, the maximum number of moves required to reach any square from any other square is very small (at most 6). Since 100 is significantly larger than the minimum distance required, if the parity condition is satisfied, the knight can always "waste" moves by jumping back and forth between two squares to reach the target in exactly 100 moves.

**Conclusion**: The knight can reach the target in exactly 100 moves if and only if $(x_1 + y_1) \equiv (x_2 + y_2) \pmod 2$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are only performing basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the coordinates.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A knight's move changes the parity of the sum of its coordinates (X + Y).
 * In each move, the sum of coordinates changes by (±1 ± 2) = ±3 or ±1.
 * In all cases, the parity of (X + Y) changes every move.
 * 
 * After 100 moves (an even number of moves), the parity of (X1 + Y1) must be 
 * the same as the parity of (X2 + Y2).
 * 
 * Since 100 is much larger than the maximum distance between any two squares 
 * on an 8x8 board, if the parity condition is met, the knight can always 
 * "waste" moves to reach the target in exactly 100 moves.
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
```