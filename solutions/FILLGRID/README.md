# [The Grid Fill Problem (FILLGRID)](https://www.codechef.com/problems/FILLGRID)

- **Difficulty Rating**: 1393
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, construct an $N \times N$ grid consisting only of $1$s and $-1$s such that for every row and every column, the product of the sum of elements and the product of elements is strictly less than $0$. That is, for any row or column:
$(\sum \text{elements}) \times (\prod \text{elements}) < 0$.

## Intuition & Mathematical Observation

To satisfy the condition $(\text{Sum} \times \text{Product}) < 0$, we need the Sum and the Product to have opposite signs.

### Case 1: $N$ is Even
If we fill the entire grid with $-1$:
- The **Sum** of any row/column is $N \times (-1) = -N$. Since $N > 0$, the sum is negative.
- The **Product** of any row/column is $(-1)^N$. Since $N$ is even, the product is $1$.
- **Result**: $\text{Sum} \times \text{Product} = -N \times 1 = -N < 0$.
This configuration satisfies the condition for all rows and columns.

### Case 2: $N$ is Odd
If we fill the entire grid with $-1$:
- The **Sum** is $-N$ (negative).
- The **Product** is $(-1)^N = -1$ (negative).
- **Result**: $\text{Sum} \times \text{Product} = (-N) \times (-1) = N > 0$. This fails.

To fix this, we need to change the product to $1$ while keeping the sum negative. By changing one element in each row and column to $1$ (placing $1$s on the main diagonal), we observe:
- Each row/column now contains one $1$ and $(N-1)$ $-1$s.
- **Sum**: $1 + (N-1) \times (-1) = 1 - N + 1 = 2 - N$. For $N > 2$, this is negative.
- **Product**: $1 \times (-1)^{N-1}$. Since $N$ is odd, $N-1$ is even, so the product is $1$.
- **Result**: $\text{Sum} \times \text{Product} = (2-N) \times 1 = 2-N$. For $N > 2$, this is $< 0$.
*(Note: For $N=1$, the problem constraints usually imply $N > 1$, but the logic holds for the general construction).*

## Complexity Analysis
- **Time Complexity**: $O(N^2)$ per test case, as we must print $N^2$ elements.
- **Space Complexity**: $O(1)$, as we print the grid directly without storing it.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need (Sum * Product) < 0 for every row and every column.
 * 
 * Case 1: N is even.
 * Fill the entire grid with -1.
 * Sum = -N, Product = 1. Sum * Product = -N < 0.
 * 
 * Case 2: N is odd.
 * Fill with -1, but put 1 on the main diagonal.
 * Sum = 2 - N, Product = 1. Sum * Product = 2 - N < 0 (for N > 2).
 */

void solve() {
    int N;
    cin >> N;

    if (N % 2 == 0) {
        // Even N: Fill everything with -1
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << -1 << (j == N - 1 ? "" : " ");
            }
            cout << "\n";
        }
    } else {
        // Odd N: Fill with -1, but put 1 on the main diagonal
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) {
                    cout << 1 << (j == N - 1 ? "" : " ");
                } else {
                    cout << -1 << (j == N - 1 ? "" : " ");
                }
            }
            cout << "\n";
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