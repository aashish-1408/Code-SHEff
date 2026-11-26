# [Split and Maximize (SPLITMAX)](https://www.codechef.com/problems/SPLITMAX)

- **Difficulty Rating**: 1313
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $C$ of $N$ positive integers, we are allowed to perform an operation: choose an element $C_i > 1$ and replace it with two positive integers $x$ and $y$ such that $x + y = C_i$. We want to maximize the function $f(A) = \sum_{i=1}^{M} \sum_{j=1, j \neq i}^{M} (A_i \cdot A_j)$, where $A$ is the array after any number of operations.

## Intuition & Mathematical Observation
The expression $f(A) = \sum_{i=1}^{M} \sum_{j \neq i} (A_i \cdot A_j)$ can be simplified using the algebraic identity:
$$(\sum A_i)^2 = \sum A_i^2 + \sum_{i \neq j} A_i A_j$$
Rearranging this, we get:
$$f(A) = (\sum A_i)^2 - \sum A_i^2$$

Since the sum of elements $S = \sum C_i$ remains invariant regardless of how we split the numbers, the term $(\sum A_i)^2$ is constant ($S^2$). To maximize $f(A)$, we must **minimize** $\sum A_i^2$.

For any integer $x > 1$, splitting it into $1$ and $x-1$ results in a smaller sum of squares:
$1^2 + (x-1)^2 = 1 + x^2 - 2x + 1 = x^2 - 2x + 2$.
Since $x^2 - (x^2 - 2x + 2) = 2x - 2$, and $x \ge 1$, the sum of squares always decreases (or stays the same if $x=1$) when we split numbers. Therefore, the minimum sum of squares is achieved by splitting every element into $1$s.

If we split all elements into $1$s, we have $S$ elements, each equal to $1$.
The sum of squares becomes $\sum_{i=1}^{S} 1^2 = S$.
Substituting this into our formula:
$$f(A) = S^2 - S = S(S - 1)$$

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array, as we only need to compute the sum of the array elements.
- **Space Complexity**: $O(1)$, as we only store the running sum and the modulo result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let S be the sum of all elements in the array C.
 * f(A) = sum_{i=1 to M} sum_{j=1, j!=i to M} (A_i * A_j)
 * This is equivalent to: (sum_{i=1 to M} A_i)^2 - sum_{i=1 to M} (A_i^2)
 * Since the sum of elements S remains constant regardless of the operations,
 * f(A) = S^2 - sum_{i=1 to M} (A_i^2).
 * To maximize f(A), we need to minimize sum_{i=1 to M} (A_i^2).
 * 
 * We can split any element C_i into smaller positive integers.
 * To minimize the sum of squares, we should split every C_i into as many 1s as possible.
 * If we split C_i into C_i ones, the sum of squares becomes C_i * (1^2) = C_i.
 * If we don't split, the sum of squares is C_i^2.
 * Since C_i >= 1, C_i^2 >= C_i, with equality only if C_i = 1.
 * Thus, the optimal strategy is to split every element into 1s.
 * 
 * The final array will consist of S ones, where S = sum(C_i).
 * The number of elements M = S.
 * f(A) = S^2 - sum_{i=1 to S} (1^2) = S^2 - S = S * (S - 1).
 * 
 * All calculations should be done modulo 998244353.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    long long MOD = 998244353;

    while (t--) {
        int n;
        cin >> n;
        long long s = 0;
        for (int i = 0; i < n; ++i) {
            long long c;
            cin >> c;
            s = (s + c) % MOD;
        }

        // Result is S * (S - 1) mod MOD
        long long ans = (s * (s - 1 + MOD)) % MOD;
        cout << ans << "\n";
    }

    return 0;
}
```