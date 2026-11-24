# [Positive Products (POSPROD)](https://www.codechef.com/problems/POSPROD)

- **Difficulty Rating**: 1178
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, we need to find the number of pairs $(i, j)$ such that $1 \le i < j \le N$ and the product of the elements $A_i \times A_j > 0$.

## Intuition & Mathematical Observation
A product of two numbers is positive if and only if both numbers have the same sign (both positive or both negative). Zeroes do not contribute to a positive product, so they can be ignored.

1.  **Positive Pairs**: If there are `pos` positive numbers in the array, the number of ways to choose two distinct positive numbers is given by the combination formula $\binom{pos}{2} = \frac{pos \times (pos - 1)}{2}$.
2.  **Negative Pairs**: Similarly, if there are `neg` negative numbers in the array, the number of ways to choose two distinct negative numbers is $\binom{neg}{2} = \frac{neg \times (neg - 1)}{2}$.
3.  **Total**: The final answer is the sum of these two values.

**Note on Data Types**: Since $N$ can be up to $10^5$, the number of pairs can reach approximately $\frac{(10^5)^2}{2} = 5 \times 10^9$. This exceeds the capacity of a standard 32-bit `int`, so we must use `long long` to store the counts and the final result to prevent overflow.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array exactly once to count the positive and negative integers.
- **Space Complexity**: $O(1)$, as we only store a few variables (`pos`, `neg`, `val`) regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A product A_i * A_j > 0 if and only if:
 * 1. Both A_i and A_j are positive.
 * 2. Both A_i and A_j are negative.
 * 
 * If we have 'pos' count of positive numbers and 'neg' count of negative numbers,
 * the number of ways to choose two positive numbers is pos * (pos - 1) / 2.
 * The number of ways to choose two negative numbers is neg * (neg - 1) / 2.
 */

void solve() {
    int n;
    cin >> n;
    
    long long pos = 0;
    long long neg = 0;
    
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val > 0) {
            pos++;
        } else if (val < 0) {
            neg++;
        }
    }
    
    // Number of ways to choose 2 from pos: posC2 = pos * (pos - 1) / 2
    // Number of ways to choose 2 from neg: negC2 = neg * (neg - 1) / 2
    long long ans = (pos * (pos - 1)) / 2 + (neg * (neg - 1)) / 2;
    
    cout << ans << "\n";
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