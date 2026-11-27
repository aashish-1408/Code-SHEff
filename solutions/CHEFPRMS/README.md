# [Chef and Semi-Primes (CHEFPRMS)](https://www.codechef.com/problems/CHEFPRMS)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine if a given integer $N$ ($1 \le N \le 200$) can be expressed as the sum of two semi-primes. A semi-prime is defined as the product of two **distinct** prime numbers.

## Intuition & Mathematical Observation
1.  **Definition**: A number $x$ is a semi-prime if $x = p \times q$, where $p$ and $q$ are prime numbers and $p \neq q$.
2.  **Constraint Analysis**: Since $N$ is small ($N \le 200$), we can precompute all semi-primes up to 200.
3.  **Precomputation**:
    *   Iterate through all numbers $i$ from 1 to 200.
    *   For each $i$, find its divisors. If $i$ can be expressed as $p \times q$ where $p, q$ are distinct primes, store $i$ in a list `semi_primes`.
4.  **Verification**: For each test case $N$, we iterate through the list of precomputed semi-primes. We check if there exist two semi-primes $s_1$ and $s_2$ (where $s_1$ and $s_2$ do not necessarily have to be distinct) such that $s_1 + s_2 = N$.

## Complexity Analysis
- **Time Complexity**: 
    - Precomputation: $O(M \sqrt{M})$, where $M=200$. Checking if a number is semi-prime takes $O(\sqrt{M})$ for each number up to $M$.
    - Query: For each test case, we perform a nested loop over the list of semi-primes. Since there are at most $M$ semi-primes, this is $O(K^2)$ where $K$ is the number of semi-primes ($K < 200$). Given $T$ test cases, the total complexity is $O(M\sqrt{M} + T \cdot K^2)$, which is well within the limits for $N=200$.
- **Space Complexity**: $O(K)$, where $K$ is the number of semi-primes up to 200, used to store the list of semi-primes.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A semi-prime is a product of two distinct primes.
 * N <= 200.
 * 1. Precompute all primes up to 200.
 * 2. Generate all semi-primes up to 200.
 * 3. For each test case N, check if there exist two semi-primes s1, s2 such that s1 + s2 = N.
 */

bool is_semi_prime(int n) {
    int count = 0;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int d1 = i;
            int d2 = n / i;
            // Check if d1 and d2 are distinct primes
            auto is_prime = [](int k) {
                if (k < 2) return false;
                for (int j = 2; j * j <= k; ++j) {
                    if (k % j == 0) return false;
                }
                return true;
            };
            if (d1 != d2 && is_prime(d1) && is_prime(d2)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Precompute semi-primes up to 200
    vector<int> semi_primes;
    for (int i = 1; i <= 200; ++i) {
        if (is_semi_prime(i)) {
            semi_primes.push_back(i);
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool found = false;
        // Check if n can be represented as sum of two semi-primes
        for (int s1 : semi_primes) {
            for (int s2 : semi_primes) {
                if (s1 + s2 == n) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        if (found) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```