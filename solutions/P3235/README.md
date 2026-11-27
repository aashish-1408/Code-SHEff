# [Balanced Positions in a Permutation (P3235)](https://www.codechef.com/problems/P3235)

- **Difficulty Rating**: 930
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a permutation $P$ of length $N$, we define two values for each index $i$ (0-indexed):
*   $L_i$: The number of elements $P_j$ such that $j < i$ and $P_j < P_i$.
*   $R_i$: The number of elements $P_j$ such that $j > i$ and $P_j > P_i$.

The goal is to count the total number of indices $i$ where $L_i = R_i$.

## Intuition & Mathematical Observation
The constraints state that $N \le 100$ and the number of test cases $T \le 10^4$. 
Since $N$ is small, we can compute $L_i$ and $R_i$ for every index $i$ by iterating through the array. 

For each index $i$:
1.  **Calculate $L_i$**: Iterate from $j = 0$ to $i-1$. If $P_j < P_i$, increment $L_i$.
2.  **Calculate $R_i$**: Iterate from $j = i+1$ to $N-1$. If $P_j > P_i$, increment $R_i$.
3.  **Compare**: Check if $L_i == R_i$. If true, increment our global counter.

This brute-force approach performs roughly $N^2$ operations per test case. With $N=100$, $N^2 = 10,000$. Across $10^4$ test cases, the total operations are approximately $10^8$, which comfortably fits within the standard 1-second time limit for C++.

## Complexity Analysis
- **Time Complexity**: $O(T \times N^2)$, where $T$ is the number of test cases and $N$ is the length of the permutation. Given $N=100$ and $T=10^4$, this is well within the limits.
- **Space Complexity**: $O(N)$ to store the permutation array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Given a permutation P of length N.
 * L_i = count of elements P_j < P_i where j < i.
 * R_i = count of elements P_j > P_i where j > i.
 * We need to count indices i such that L_i == R_i.
 * 
 * Constraints: N <= 100.
 * An O(N^2) approach per test case is perfectly acceptable given N=100 and T=10^4.
 * Total complexity: O(T * N^2) = 10^8 operations, which fits within 1s.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    int count = 0;
    for (int i = 0; i < N; ++i) {
        int L_i = 0;
        int R_i = 0;

        // Calculate L_i: elements smaller than P[i] to the left
        for (int j = 0; j < i; ++j) {
            if (P[j] < P[i]) {
                L_i++;
            }
        }

        // Calculate R_i: elements greater than P[i] to the right
        for (int j = i + 1; j < N; ++j) {
            if (P[j] > P[i]) {
                R_i++;
            }
        }

        if (L_i == R_i) {
            count++;
        }
    }
    cout << count << "\n";
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