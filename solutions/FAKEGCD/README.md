# [Fake GCD (FAKEGCD)](https://www.codechef.com/problems/FAKEGCD)

- **Difficulty Rating**: 1362
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to construct a permutation $A$ of the set $\{1, 2, \dots, N\}$ such that the greatest common divisor (GCD) of the sequence $(1+A_1, 2+A_2, \dots, N+A_N)$ is strictly greater than 1.

## Intuition & Mathematical Observation
To ensure that $\gcd(1+A_1, 2+A_2, \dots, N+A_N) > 1$, the simplest approach is to make every term $(i + A_i)$ even. If every term is even, then the GCD of the entire sequence will be at least 2.

For $(i + A_i)$ to be even, $i$ and $A_i$ must have the same parity (i.e., both must be odd or both must be even). 

1. We partition the numbers $\{1, 2, \dots, N\}$ into two separate lists:
   - **Odds**: $\{1, 3, 5, \dots\}$
   - **Evens**: $\{2, 4, 6, \dots\}$
2. For every index $i$ from $1$ to $N$:
   - If $i$ is odd, we assign an element from the **Odds** list to $A_i$.
   - If $i$ is even, we assign an element from the **Evens** list to $A_i$.
3. Since we are using all elements from $1$ to $N$ exactly once, the resulting sequence $A$ is a valid permutation. Because $i$ and $A_i$ always share the same parity, $i + A_i$ is always even, satisfying the condition $\gcd > 1$.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the input integer. We iterate through the numbers from $1$ to $N$ once to categorize them and once more to print the permutation.
- **Space Complexity**: $O(N)$ to store the odd and even numbers in separate vectors.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need a permutation A of {1, 2, ..., N} such that gcd(1+A_1, 2+A_2, ..., N+A_N) > 1.
 * By ensuring (i + A_i) is even for all i, the GCD will be at least 2.
 * This is achieved by ensuring i and A_i have the same parity.
 */

void solve() {
    int N;
    cin >> N;
    
    vector<int> odds, evens;
    for (int i = 1; i <= N; ++i) {
        if (i % 2 != 0) odds.push_back(i);
        else evens.push_back(i);
    }
    
    int odd_idx = 0, even_idx = 0;
    for (int i = 1; i <= N; ++i) {
        if (i % 2 != 0) {
            cout << odds[odd_idx++] << (i == N ? "" : " ");
        } else {
            cout << evens[even_idx++] << (i == N ? "" : " ");
        }
    }
    cout << "\n";
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