# [Two Numbers (TWONMS)](https://www.codechef.com/problems/TWONMS)

- **Difficulty Rating**: 1320
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice and Bob start with two numbers, $A$ and $B$, respectively. They take turns multiplying their own number by 2 for a total of $N$ turns. Alice goes first, then Bob, and they alternate. We need to find the ratio of the maximum number to the minimum number after $N$ turns, specifically the integer part of the division (floor of the ratio).

## Intuition & Mathematical Observation
Let $N$ be the total number of turns.
- Alice takes turns $1, 3, 5, \dots$
- Bob takes turns $2, 4, 6, \dots$

The number of turns Alice takes is $\lceil N/2 \rceil$, and the number of turns Bob takes is $\lfloor N/2 \rfloor$.
After $N$ turns:
- Alice's number becomes $A' = A \times 2^{\lceil N/2 \rceil}$
- Bob's number becomes $B' = B \times 2^{\lfloor N/2 \rfloor}$

**Case 1: $N$ is even**
- Alice and Bob take the same number of turns ($N/2$).
- $A' = A \times 2^{N/2}$ and $B' = B \times 2^{N/2}$.
- The ratio $\frac{\max(A', B')}{\min(A', B')}$ simplifies to $\frac{\max(A, B)}{\min(A, B)}$.

**Case 2: $N$ is odd**
- Alice takes one extra turn compared to Bob.
- $A' = A \times 2^{(N+1)/2}$ and $B' = B \times 2^{(N-1)/2}$.
- The ratio becomes $\frac{\max(A \times 2, B)}{\min(A \times 2, B)}$.

Since we only need the integer part of the ratio, we do not need to calculate the actual powers of 2, which could exceed the capacity of standard integer types. We simply compare the values after applying the extra factor of 2 to $A$ if $N$ is odd.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations and comparisons. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and intermediate results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice and Bob take turns multiplying their numbers by 2.
 * Total turns = N.
 * 
 * If N is even:
 *   Alice and Bob take equal turns. The 2^(N/2) factor cancels out in the ratio.
 *   Ratio = max(A, B) / min(A, B)
 * 
 * If N is odd:
 *   Alice takes one more turn than Bob.
 *   A_final = A * 2^((N+1)/2), B_final = B * 2^((N-1)/2)
 *   Ratio = max(A * 2, B) / min(A * 2, B)
 */

void solve() {
    long long A, B, N;
    cin >> A >> B >> N;

    if (N % 2 == 0) {
        // Even turns: powers of 2 cancel out
        if (A >= B) {
            cout << A / B << "\n";
        } else {
            cout << B / A << "\n";
        }
    } else {
        // Odd turns: Alice has one extra factor of 2
        A *= 2;
        if (A >= B) {
            cout << A / B << "\n";
        } else {
            cout << B / A << "\n";
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