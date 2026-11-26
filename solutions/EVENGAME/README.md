# [Even Sum (EVENGAME)](https://www.codechef.com/problems/EVENGAME)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, two players take turns assigning a sign ($+$ or $-$) to each integer. Player 1 wins if the final sum of the signed integers is even, and Player 2 wins if the final sum is odd. We need to determine the winner assuming optimal play (though, as discovered, the outcome is predetermined by the input).

## Intuition & Mathematical Observation
The parity of the final sum is determined by the parity of the individual elements. Specifically:
1. **Even numbers:** Adding or subtracting an even number does not change the parity of the total sum (since $even \pm even = even$ and $even \pm odd = odd$, but we are looking at the parity of the *entire* sum). More simply, $x \equiv 0 \pmod 2$ means $x$ contributes nothing to the parity.
2. **Odd numbers:** Adding or subtracting an odd number always flips the parity of the sum. Since $1 \equiv -1 \pmod 2$, every odd number contributes exactly $1$ to the parity of the sum, regardless of whether it is assigned a positive or negative sign.

**Conclusion:**
Let $O$ be the count of odd numbers in the array.
- The total sum $S \equiv \sum_{i=1}^{O} (\pm 1) + \sum_{j=1}^{E} (\pm \text{even}) \pmod 2$.
- Since $\pm 1 \equiv 1 \pmod 2$, the sum is congruent to $O \pmod 2$.
- If $O$ is **even**, the sum is always even, so Player 1 wins.
- If $O$ is **odd**, the sum is always odd, so Player 2 wins.

The players' choices do not actually affect the parity of the final sum; the winner is determined solely by the initial count of odd numbers in the input array.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We iterate through the array exactly once to count the odd numbers.
- **Space Complexity**: $O(1)$, as we only store the count of odd numbers and the current input integer.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The parity of the final sum depends only on the parity of the elements.
 * Each odd number contributes 1 to the parity regardless of its sign.
 * Each even number contributes 0 to the parity.
 * Therefore, the sum is even if and only if the count of odd numbers is even.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int odd_count = 0;
        for (int i = 0; i < n; ++i) {
            long long a;
            cin >> a;
            // Check if the number is odd
            if (abs(a) % 2 != 0) {
                odd_count++;
            }
        }

        // If odd_count is even, sum is even (Player 1 wins)
        // If odd_count is odd, sum is odd (Player 2 wins)
        if (odd_count % 2 == 0) {
            cout << "1" << "\n";
        } else {
            cout << "2" << "\n";
        }
    }
    return 0;
}
```