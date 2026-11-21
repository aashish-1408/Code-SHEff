# [Election (ELECTION1)](https://www.codechef.com/problems/ELECTION1)

- **Difficulty Rating**: 241
- **Solved in**: 2 attempt(s)

## Problem Summary
The objective is to determine the minimum number of additional seats a political party needs to secure a "strict majority" in an election with $N$ total seats. A strict majority is defined as having more than half of the total seats. Given the current number of seats $K$ held by the party, we must calculate how many more are required to exceed $N/2$.

## Intuition & Mathematical Observation
To achieve a strict majority, the party must hold at least $T$ seats, where:
$$T = \lfloor N / 2 \rfloor + 1$$

- If the party already has $K$ seats such that $K \ge T$, they have already achieved a majority, meaning they need **0** additional seats.
- If $K < T$, the party needs exactly $T - K$ additional seats to reach the threshold.

**Key Note:** In C++, integer division `n / 2` automatically performs the floor operation, making the calculation of $T$ straightforward.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves a simple arithmetic calculation and a conditional check regardless of the input size.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <iostream>

/**
 * Problem Analysis:
 * A party needs a strict majority to form the government.
 * The threshold is floor(N / 2) + 1.
 * Let T = floor(N / 2) + 1.
 * If K >= T, the party already has a majority, so 0 additional seats are needed.
 * If K < T, the party needs (T - K) additional seats.
 */

int main() {
    // Optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    if (std::cin >> n >> k) {
        // Calculate the required threshold for a strict majority
        // Using integer division, n / 2 is equivalent to floor(n / 2)
        int threshold = (n / 2) + 1;

        // If current seats are already >= threshold, need 0.
        // Otherwise, need threshold - k.
        if (k >= threshold) {
            std::cout << 0 << std::endl;
        } else {
            std::cout << (threshold - k) << std::endl;
        }
    }

    return 0;
}
```