# [Pair Me (SUMPOS)](https://www.codechef.com/problems/SUMPOS)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Given three integers $x$, $y$, and $z$, determine if any one of these integers can be expressed as the sum of the other two. In other words, check if the equation $a = b + c$ holds true for any permutation of the given three numbers.

## Intuition & Mathematical Observation
The problem asks us to verify if the set of numbers $\{x, y, z\}$ satisfies the condition that the largest number is equal to the sum of the two smaller numbers. 

Mathematically, we need to check if any of the following conditions are true:
1. $x = y + z$
2. $y = x + z$
3. $z = x + y$

If any of these conditions evaluate to true, the answer is "YES"; otherwise, it is "NO". Since the constraints are small, simple conditional statements are sufficient to solve the problem efficiently.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of arithmetic and comparison operations.
- **Space Complexity**: $O(1)$, as we only use a fixed amount of memory to store the three input integers.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Given three integers x, y, and z, we need to check if:
 * x = y + z OR y = x + z OR z = x + y.
 * 
 * Since the constraints are small (up to 1000), standard integer types are sufficient.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        // Check the three possible conditions
        if ((x == y + z) || (y == x + z) || (z == x + y)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```