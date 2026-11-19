# [An Interesting Sequence (INTSEQ)](https://www.codechef.com/problems/INTSEQ)

- **Difficulty Rating**: 1393
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an integer $K$, we want to find the maximum length $N$ of a sequence $A_1, A_2, \dots, A_N$ such that for every $i \in [1, N]$, the sum of the sequence up to $i$ (denoted $S_i = \sum_{j=1}^i A_j$) satisfies the condition that $A_i + S_{i-1} = K$ (where $S_0 = 0$). Essentially, we are looking for the maximum number of times we can perform the operation $S_i = K - S_{i-1}$ while ensuring that the sequence remains valid under the constraints provided.

## Intuition & Mathematical Observation
Let's analyze the recurrence relation $S_i = K - S_{i-1}$:
1. $S_1 = K - S_0 = K$
2. $S_2 = K - S_1 = K - K = 0$
3. $S_3 = K - S_2 = K - 0 = K$

Wait, the problem constraints imply that $A_i$ must be chosen such that $S_i$ is derived from $K$. Specifically, the condition $A_i + S_i = K$ implies $S_i - S_{i-1} + S_i = K$, which simplifies to $2S_i = K + S_{i-1}$, or $S_i = \frac{K + S_{i-1}}{2}$.

For $S_i$ to be an integer, $(K + S_{i-1})$ must be even.
- Starting with $S_0 = 0$:
- $S_1 = \frac{K + 0}{2} = \frac{K}{2}$ (Requires $K$ to be divisible by 2)
- $S_2 = \frac{K + K/2}{2} = \frac{3K}{4}$ (Requires $K$ to be divisible by 4)
- $S_3 = \frac{K + 3K/4}{2} = \frac{7K}{8}$ (Requires $K$ to be divisible by 8)

By induction, $S_i = K \cdot \frac{2^i - 1}{2^i}$. For $S_i$ to be an integer, $K$ must be divisible by $2^i$. Therefore, the maximum length $N$ is simply the exponent of the highest power of 2 that divides $K$. This is equivalent to counting how many times we can divide $K$ by 2 before it becomes odd.

## Complexity Analysis
- **Time Complexity**: $O(\log K)$ per test case, as we are repeatedly dividing $K$ by 2.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the counter.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We need to find the maximum N such that there exists a sequence A_1, ..., A_N
 * satisfying A_i + S_i = K.
 * As derived: S_i = (S_{i-1} + K) / 2.
 * For S_i to be an integer, (S_{i-1} + K) must be even.
 * With S_0 = 0:
 * S_1 = K/2. Valid if K is divisible by 2.
 * S_2 = (K/2 + K)/2 = 3K/4. Valid if K is divisible by 4.
 * S_3 = (3K/4 + K)/2 = 7K/8. Valid if K is divisible by 8.
 * The sequence continues as long as the current K is divisible by 2^i.
 * The maximum length is the exponent of the highest power of 2 that divides K.
 */

void solve() {
    long long K;
    if (!(cin >> K)) return;
    
    int count = 0;
    // Count how many times K is divisible by 2
    while (K > 0 && K % 2 == 0) {
        K /= 2;
        count++;
    }
    cout << count << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```