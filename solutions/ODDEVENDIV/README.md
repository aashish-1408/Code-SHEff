# [Check Odd Even Divisors (ODDEVENDIV)](https://www.codechef.com/problems/ODDEVENDIV)

- **Difficulty Rating**: 1105
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $A$ and $B$, determine if there exists a positive integer $N$ such that $A$ is the number of odd divisors of $N$ and $B$ is the number of even divisors of $N$.

## Intuition & Mathematical Observation
Any positive integer $N$ can be uniquely represented in the form $N = 2^k \times m$, where $m$ is an odd integer and $k \ge 0$.

1.  **Odd Divisors ($A$):** The odd divisors of $N$ are exactly the divisors of $m$. Let $d(m)$ be the number of divisors of $m$. Therefore, $A = d(m)$. Since $m \ge 1$, $d(m)$ must be at least 1. Thus, if $A=0$, no such $N$ exists.
2.  **Even Divisors ($B$):** An even divisor of $N$ must contain at least one factor of 2. These divisors are of the form $2^i \times d$, where $1 \le i \le k$ and $d$ is a divisor of $m$. The number of choices for $i$ is $k$, and the number of choices for $d$ is $A$. Thus, $B = k \times A$.

**Conditions for existence:**
*   If $A = 0$: Impossible, as $N$ always has at least one odd divisor (1). Output **No**.
*   If $B = 0$: This implies $k=0$ (i.e., $N$ is odd). This is possible for any $A \ge 1$. Output **Yes**.
*   If $B > 0$: We require $B$ to be a multiple of $A$ (since $B = k \times A$ for some integer $k \ge 1$). Output **Yes** if $B \% A == 0$, otherwise **No**.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic checks. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let N = 2^k * m, where m is an odd integer.
 * The odd divisors of N are exactly the divisors of m.
 * Let d(m) be the number of divisors of m. Then A = d(m).
 * Since m is a positive integer, d(m) must be at least 1.
 * Thus, if A = 0, it is impossible (since 1 is always an odd divisor).
 * 
 * The even divisors of N are of the form 2^i * d, where 1 <= i <= k and d is a divisor of m.
 * The number of such divisors is k * d(m) = k * A.
 * So, B = k * A.
 * 
 * Case 1: A = 0.
 * Impossible, because 1 is always an odd divisor. Output: No.
 * 
 * Case 2: A > 0.
 * We need to check if there exists an integer k >= 0 such that B = k * A.
 * If k = 0, then B = 0. This is possible (N = m).
 * If k > 0, then B must be a multiple of A.
 */

void solve() {
    long long A, B;
    cin >> A >> B;

    if (A == 0) {
        cout << "No" << "\n";
    } else {
        if (B == 0) {
            cout << "Yes" << "\n";
        } else {
            if (B % A == 0) {
                cout << "Yes" << "\n";
            } else {
                cout << "No" << "\n";
            }
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