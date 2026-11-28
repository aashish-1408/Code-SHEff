# [Deletion and Difference (DELDIF)](https://www.codechef.com/problems/DELDIF)

- **Difficulty Rating**: 1343
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, we can perform an operation: choose two indices $i$ and $j$ such that $A_i = A_j$, remove both elements, and insert $|A_i - A_j| = 0$ into the array. We want to find the minimum possible number of elements remaining in the array after performing this operation any number of times.

## Intuition & Mathematical Observation
The core of the problem lies in understanding how the operation affects the frequency of numbers:

1.  **Pairing Non-Zero Elements**: If we have multiple instances of a non-zero number $x$, we can pair them up. Each pair $(x, x)$ is replaced by a $0$. 
    *   If the frequency of $x$ is `count[x]`, we can form `count[x] / 2` zeros.
    *   If `count[x]` is odd, one instance of $x$ will remain after all possible pairs are exhausted.
2.  **Handling Zeros**: Once we have generated zeros (or if they existed in the initial array), we can continue to pair them. Since $|0 - 0| = 0$, any two zeros can be replaced by a single zero.
    *   This implies that if we have at least one zero in our collection, we can eventually reduce all zeros down to exactly one zero.
3.  **Final State**:
    *   All non-zero numbers that appeared an odd number of times will remain as they are.
    *   All pairs of non-zero numbers and all initial zeros will contribute to the pool of zeros.
    *   If the total count of zeros is $\ge 1$, they collapse into a single $0$.
    *   The final answer is the count of distinct non-zero numbers that appeared an odd number of times, plus $1$ if there is at least one zero present.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ or $O(N)$ depending on the map implementation. Using `std::map` results in $O(N \log K)$ where $K$ is the number of distinct elements. Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(K)$ to store the frequency map of the $K$ distinct elements.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. For any number x > 0:
 *    - If count[x] is even, we get count[x]/2 zeros.
 *    - If count[x] is odd, we get (count[x]-1)/2 zeros and one x remains.
 * 2. After processing all x > 0, we collect all the remaining x's and all the generated 0s.
 * 3. Any number of 0s can be reduced to a single 0 because (0, 0) -> 0.
 * 4. The final answer is (number of distinct x > 0 that remained) + (1 if we have any 0s else 0).
 */

void solve() {
    int n;
    cin >> n;
    map<int, int> counts;
    int zeros = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 0) zeros++;
        else counts[a]++;
    }

    int remaining_non_zero = 0;
    for (auto const& [val, count] : counts) {
        // Each pair of identical non-zero numbers creates a 0
        zeros += count / 2;
        // If count is odd, one instance remains
        if (count % 2 != 0) {
            remaining_non_zero++;
        }
    }

    // If we have any zeros, they can all be reduced to a single 0
    if (zeros > 0) {
        cout << remaining_non_zero + 1 << "\n";
    } else {
        cout << remaining_non_zero << "\n";
    }
}

int main() {
    // Optimize I/O operations
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