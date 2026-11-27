# [Chef And Babla (BAB_I)](https://www.codechef.com/problems/BAB_I)

- **Difficulty Rating**: 1346
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we need to find the maximum non-negative integer $X$ such that for every element $A_i$ in the array, $A_i$ does not lie in the closed interval $[-X, X]$. If no such non-negative integer $X$ exists, output $-1$.

## Intuition & Mathematical Observation
The condition "$A_i$ is not in $[-X, X]$" is mathematically equivalent to saying $|A_i| > X$. 

To satisfy this for all elements in the array, we must have:
$$X < |A_i| \quad \text{for all } i$$
This implies that $X$ must be strictly less than the minimum absolute value present in the array:
$$X < \min(|A_1|, |A_2|, \dots, |A_n|)$$

Since we want the **maximum** non-negative integer $X$:
1. If the array contains $0$, then $\min(|A_i|) = 0$. The condition $X < 0$ cannot be satisfied by any non-negative integer $X$. In this case, the answer is $-1$.
2. If the array does not contain $0$, the largest integer $X$ satisfying $X < \min(|A_i|)$ is simply $\min(|A_i|) - 1$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We iterate through the array exactly once to find the minimum absolute value.
- **Space Complexity**: $O(1)$, as we only store a few variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the maximum non-negative integer X such that for all A_i,
 * A_i is not in [-X, X]. This is equivalent to |A_i| > X.
 * 
 * Logic:
 * 1. If 0 is in the array, |0| > X implies 0 > X. Since X must be >= 0, 
 *    this is impossible. Output -1.
 * 2. Otherwise, X must be less than the minimum absolute value in the array.
 *    The largest such integer is min(|A_i|) - 1.
 */

void solve() {
    int n;
    cin >> n;
    long long min_abs = 2e9; // Initialize with a value larger than any possible |A_i|
    bool has_zero = false;

    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        if (a == 0) {
            has_zero = true;
        }
        long long abs_a = abs(a);
        if (abs_a < min_abs) {
            min_abs = abs_a;
        }
    }

    if (has_zero) {
        cout << -1 << "\n";
    } else {
        cout << min_abs - 1 << "\n";
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