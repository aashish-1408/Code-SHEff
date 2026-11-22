# [Diagonal movement (DIAGMOVE)](https://www.codechef.com/problems/DIAGMOVE)

- **Difficulty Rating**: 1157
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a 2D grid starting at the origin $(0, 0)$. We are allowed to make moves of the form $(x \pm 1, y \pm 1)$. We need to determine if a target coordinate $(x, y)$ is reachable from the origin using any number of these diagonal moves.

## Intuition & Mathematical Observation
To determine reachability, let's analyze how each move affects the sum of the coordinates $S = x + y$:

1.  **Move options**: $(x+1, y+1), (x+1, y-1), (x-1, y+1), (x-1, y-1)$.
2.  **Effect on sum**:
    *   $(x+1) + (y+1) = x + y + 2$
    *   $(x+1) + (y-1) = x + y$
    *   $(x-1) + (y+1) = x + y$
    *   $(x-1) + (y-1) = x + y - 2$

In every possible move, the sum of the coordinates changes by either $+2, 0,$ or $-2$. This means the **parity** of the sum $(x + y)$ remains invariant. Since we start at $(0, 0)$, where the sum is $0$ (even), any reachable point $(x, y)$ must also have an even sum.

Conversely, if $x+y$ is even, it implies that $x$ and $y$ have the same parity. We can always reach such a point by moving diagonally towards the target until we align with it. Thus, the condition $(x + y) \pmod 2 == 0$ is both necessary and sufficient.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a simple parity check. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input coordinates.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The allowed moves are: (i+1, j+1), (i+1, j-1), (i-1, j+1), (i-1, j-1).
 * In every move, the parity of the sum of coordinates (x + y) remains the same.
 * Since the starting point (0, 0) has an even sum (0), any reachable point 
 * (x, y) must satisfy (x + y) % 2 == 0.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        // Check if the sum of coordinates is even
        if (abs(x + y) % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```