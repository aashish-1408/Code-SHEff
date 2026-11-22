# [Binary Sum (BINARYSUM)](https://www.codechef.com/problems/BINARYSUM)

- **Difficulty Rating**: 1015
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $N$ and $K$, determine if it is possible to construct a binary string of length $N$ such that no two adjacent characters are equal (i.e., the string must be alternating) and the sum of the digits in the string is exactly $K$.

## Intuition & Mathematical Observation
An alternating binary string of length $N$ can only take two forms:
1. Starting with '0': `010101...`
2. Starting with '1': `101010...`

We can analyze the sum of these strings based on the parity of $N$:

*   **Case 1: $N$ is even ($N = 2m$)**
    *   The string `0101...01` contains $m$ ones. Sum = $N/2$.
    *   The string `1010...10` contains $m$ ones. Sum = $N/2$.
    *   **Conclusion**: If $N$ is even, the sum must be exactly $N/2$.

*   **Case 2: $N$ is odd ($N = 2m + 1$)**
    *   The string `0101...0` contains $m$ ones. Sum = $(N-1)/2$.
    *   The string `1010...1` contains $m+1$ ones. Sum = $(N+1)/2$.
    *   **Conclusion**: If $N$ is odd, the sum must be either $(N-1)/2$ or $(N+1)/2$.

By checking these conditions, we can determine if a valid string exists for any given $N$ and $K$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic comparisons. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A binary string of length N with no two adjacent digits equal must be alternating.
 * There are only two such strings:
 * 1. 010101... (starts with 0)
 * 2. 101010... (starts with 1)
 * 
 * Case 1: N is even (N = 2m)
 * - String 0101...01: Sum = m = N/2
 * - String 1010...10: Sum = m = N/2
 * Both strings have the same sum: N/2.
 * 
 * Case 2: N is odd (N = 2m + 1)
 * - String 0101...010: Sum = m = (N-1)/2
 * - String 1010...101: Sum = m + 1 = (N+1)/2
 * The possible sums are (N-1)/2 and (N+1)/2.
 */

void solve() {
    int N, K;
    cin >> N >> K;

    if (N % 2 == 0) {
        // If N is even, sum must be N/2
        if (K == N / 2) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    } else {
        // If N is odd, sum must be (N-1)/2 or (N+1)/2
        if (K == (N - 1) / 2 || K == (N + 1) / 2) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
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