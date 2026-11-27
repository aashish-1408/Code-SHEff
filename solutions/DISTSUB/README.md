# [Distinct Substring (DISTSUB)](https://www.codechef.com/problems/DISTSUB)

- **Difficulty Rating**: 1251
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string of length $N$, we define an "island" as a contiguous block of '0's. We need to determine if it is possible to construct a binary string of length $N$ that contains exactly $K$ islands, where each island has a **distinct** length.

## Intuition & Mathematical Observation
To determine if such a string exists, we must calculate the minimum possible length required to satisfy the constraints:

1.  **Distinct Lengths**: To have $K$ islands with distinct lengths, the smallest possible set of lengths we can choose is $\{1, 2, 3, \dots, K\}$. The sum of these lengths is:
    $$\sum_{i=1}^{K} i = \frac{K(K+1)}{2}$$
2.  **Separation**: To ensure these $K$ blocks of '0's are distinct islands, we must place at least one '1' between every adjacent pair of islands. For $K$ islands, we need at least $K-1$ '1's.
3.  **Minimum Total Length**: Combining these, the absolute minimum length $N_{min}$ required to accommodate $K$ distinct islands is:
    $$N_{min} = \left( \sum_{i=1}^{K} i \right) + (K - 1) = \frac{K(K+1)}{2} + K - 1$$

**Construction Logic**:
- If $N < N_{min}$, it is impossible to satisfy the condition, so the answer is `NO`.
- If $N \ge N_{min}$, we can always construct the string. We place islands of lengths $1, 2, \dots, K-1$ and one final island of length $K + (N - N_{min})$. Since we add the remaining length to the largest island, all lengths remain distinct. Thus, the answer is `YES`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple arithmetic check.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An island is a contiguous block of '0's.
 * We need exactly K islands, each with a distinct length.
 * Minimum length required = (Sum of 1 to K) + (K-1 separators)
 * N_min = K*(K+1)/2 + K - 1
 */

void solve() {
    long long N, K;
    cin >> N >> K;

    // Calculate minimum length required for K distinct islands
    long long min_len = (K * (K + 1)) / 2 + (K - 1);

    if (N >= min_len) {
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