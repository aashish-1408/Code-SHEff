# [Strange Number (STRNO)](https://www.codechef.com/problems/STRNO)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $X$ and $K$, determine if there exists an integer $A$ such that:
1. The total number of divisors of $A$ is exactly $X$.
2. The number of prime factors of $A$ (counting multiplicity) is exactly $K$.

## Intuition & Mathematical Observation
Let the prime factorization of $A$ be $A = p_1^{a_1} \cdot p_2^{a_2} \cdot \dots \cdot p_m^{a_m}$.
- The number of divisors $X$ is given by the formula: $X = (a_1 + 1)(a_2 + 1) \dots (a_m + 1)$.
- The total number of prime factors (counting multiplicity) is $K = a_1 + a_2 + \dots + a_m$.

To maximize the number of prime factors $K$ for a fixed number of divisors $X$, we should make the exponents $a_i$ as small as possible. The smallest possible value for each $(a_i + 1)$ is 2 (which implies $a_i = 1$). If we set all $a_i = 1$, then $X = 2^m$, which means $K = m = \log_2(X)$.

However, $X$ is not always a power of 2. For any $X$, the maximum number of prime factors $K$ we can obtain is equal to the number of prime factors of $X$ itself (counting multiplicity). For example, if $X=12$, $12 = 2 \times 2 \times 3$. The maximum $K$ is $1+1+1 = 3$ (corresponding to $A = p_1^1 \cdot p_2^1 \cdot p_3^1$). 

**Key Logic:**
1. Calculate the total number of prime factors of $X$ (let this be `max_k`).
2. If $K > \text{max\_k}$, it is impossible to construct such an $A$ because we cannot decompose the exponents of $A$ any further to increase the count of prime factors.
3. If $K \le \text{max\_k}$, it is always possible. We can take the prime factors of $X$ and group them to form the exponents $a_i$ such that their sum is $K$.
4. Special case: $X=1$ implies $A=1$, which has 0 prime factors.

## Complexity Analysis
- **Time Complexity**: $O(\sqrt{X})$ per test case, as we perform prime factorization of $X$ up to its square root.
- **Space Complexity**: $O(1)$, as we only use a few variables for calculation.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The number of divisors X = (a1 + 1) * (a2 + 1) * ... * (am + 1).
 * The number of prime factors K = a1 + a2 + ... + am.
 * We need to check if there exists an integer A satisfying these.
 * The maximum possible K for a given X is the number of prime factors of X.
 */

int count_prime_factors(int n) {
    int count = 0;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            count++;
            n /= i;
        }
    }
    if (n > 1) count++;
    return count;
}

void solve() {
    long long X, K;
    cin >> X >> K;

    // X=1 has 0 prime factors. If K > 0, it's impossible.
    if (X == 1) {
        cout << (K == 0 ? 1 : 0) << "\n";
        return;
    }

    // Calculate the maximum possible prime factors for X
    int max_k = count_prime_factors(X);
    
    // If K is within the range [1, max_k], it is possible to construct A.
    if (K <= max_k) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
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