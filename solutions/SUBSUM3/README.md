# [Subset Sum 3 (SUBSUM3)](https://www.codechef.com/problems/SUBSUM3)

- **Difficulty Rating**: 990
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, determine if there exists at least one non-empty subsequence such that the sum of its elements is divisible by 3. In other words, we need to check if there exists a non-empty subset whose sum $S \equiv 0 \pmod 3$.

## Intuition & Mathematical Observation
The problem asks for a subset sum divisible by 3. Since we only care about the sum modulo 3, we only need to track three possible states for any subset:
1. Remainder 0
2. Remainder 1
3. Remainder 2

We can use **Dynamic Programming** to maintain a boolean array `dp[3]`, where `dp[r]` is true if a non-empty subsequence with sum $\equiv r \pmod 3$ has been found so far.

For every element $x$ in the array:
1. Let $val = x \pmod 3$.
2. The element $x$ itself can form a subsequence with remainder $val$.
3. If we have already formed a subsequence with remainder $r$, adding $x$ to it creates a new subsequence with remainder $(r + val) \pmod 3$.

By iterating through the array and updating our `dp` states, we can determine if `dp[0]` becomes true at any point.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of elements in the array. For each element, we perform a constant number of operations (looping through 3 states).
- **Space Complexity**: $O(1)$, as the `dp` array size is fixed at 3 regardless of the input size $N$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find if there exists a non-empty subsequence whose sum is divisible by 3.
 * This is equivalent to finding a non-empty subset whose sum modulo 3 is 0.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // dp[r] stores whether a sum with remainder r is possible using a non-empty subsequence
    vector<bool> dp(3, false);

    for (int i = 0; i < N; ++i) {
        int val = A[i] % 3;
        vector<bool> next_dp = dp;
        
        // Option 1: The element itself forms a subsequence
        next_dp[val] = true;
        
        // Option 2: The element is added to existing subsequences
        for (int r = 0; r < 3; ++r) {
            if (dp[r]) {
                next_dp[(r + val) % 3] = true;
            }
        }
        dp = next_dp;
    }

    if (dp[0]) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```