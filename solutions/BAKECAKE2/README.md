# [Chef Bakes Cake 2 (BAKECAKE2)](https://www.codechef.com/problems/BAKECAKE2)

- **Difficulty Rating**: 612
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef needs to bake a cake that requires $N$ different ingredients. For each ingredient $i$, the recipe requires $A_i$ amount, but Chef currently has $B_i$ amount in stock. If the amount in stock is less than what is required, Chef must purchase the difference. Given that each unit of any ingredient costs 1, calculate the total cost Chef must incur to acquire the missing ingredients.

## Intuition & Mathematical Observation
For each ingredient $i$, we compare the required amount $A_i$ with the available amount $B_i$:
1. If $A_i > B_i$, the amount to be purchased is $A_i - B_i$.
2. If $A_i \le B_i$, Chef already has enough, so the amount to be purchased is $0$.

Mathematically, the cost for a single ingredient $i$ is $\max(0, A_i - B_i)$. The total cost is the summation of these values across all $N$ ingredients:
$$\text{Total Cost} = \sum_{i=1}^{N} \max(0, A_i - B_i)$$

Since the constraints are small ($N, A_i, B_i \le 100$), a simple linear scan through the arrays is sufficient to compute the result.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of ingredients. We iterate through the arrays once to calculate the difference.
- **Space Complexity**: $O(N)$ to store the input arrays $A$ and $B$. This can be optimized to $O(1)$ if we process the input values on the fly.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each ingredient i, we need A_i amount and we have B_i amount.
 * If A_i > B_i, we need to buy (A_i - B_i) amount.
 * If A_i <= B_i, we have enough, so we buy 0.
 * The cost per unit is 1, so the cost for ingredient i is max(0, A_i - B_i).
 * Total cost = sum of max(0, A_i - B_i) for all i from 1 to N.
 * 
 * Constraints:
 * T <= 100, N <= 100, A_i, B_i <= 100.
 * The maximum possible cost is 100 * 100 = 10,000, which fits in a standard int.
 * Using long long is safe practice.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        long long total_cost = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) {
                total_cost += (a[i] - b[i]);
            }
        }
        cout << total_cost << "\n";
    }

    return 0;
}
```