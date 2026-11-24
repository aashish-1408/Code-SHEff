# [Friends Meetup (FRIMEET)](https://www.codechef.com/problems/FRIMEET)

- **Difficulty Rating**: 1098
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is at position $X_1$ and his friend is at position $X_2$. Chef moves at a speed of 1 unit/sec, and his friend moves at a speed of 2 units/sec. We need to determine if they can ever meet at the same position at the same time $t \ge 0$.

## Intuition & Mathematical Observation
To find if they meet, we define their positions as functions of time $t$:
*   Chef's position: $P_1(t) = X_1 + t$
*   Friend's position: $P_2(t) = X_2 + 2t$

They meet if there exists a non-negative integer $t$ such that $P_1(t) = P_2(t)$:
$$X_1 + t = X_2 + 2t$$
$$X_1 - X_2 = 2t - t$$
$$t = X_1 - X_2$$

Since the problem requires $t \ge 0$ (time cannot be negative), the condition for them to meet is:
$$X_1 - X_2 \ge 0 \implies X_1 \ge X_2$$

*   If $X_1 \ge X_2$, Chef starts at or ahead of the friend. Since the friend is moving faster, they will meet at time $t = X_1 - X_2$.
*   If $X_1 < X_2$, the friend starts ahead of Chef and is moving at a higher speed, meaning the gap between them will only increase over time. Thus, they will never meet.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a simple comparison. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input.

## Solution Code

```cpp
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
```