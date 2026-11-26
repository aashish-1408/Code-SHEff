# [Skip one (SKIPONE)](https://www.codechef.com/problems/SKIPONE)

- **Difficulty Rating**: 1182
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a sequence of $N$ items with costs $A_1, A_2, \dots, A_N$. We want to purchase a prefix of these items (i.e., items $1$ through $i$) such that the total cost, after applying a discount coupon to the most expensive item in that prefix, does not exceed our budget $K$. We need to find the maximum number of items $i$ that can be purchased under this constraint.

## Intuition & Mathematical Observation
1. **Cost Calculation**: If we choose to buy the first $i$ items, the total cost without any discount is the prefix sum $S_i = \sum_{j=1}^{i} A_j$.
2. **Applying the Coupon**: To minimize the cost, we should apply the discount to the most expensive item in the set $\{A_1, \dots, A_i\}$. Let $M_i = \max(A_1, \dots, A_i)$. The effective cost becomes $S_i - M_i$.
3. **Monotonicity**: 
   - As we increase $i$, the prefix sum $S_i$ strictly increases.
   - The maximum value $M_i$ is non-decreasing.
   - The function $f(i) = S_i - M_i$ is non-decreasing. Because $f(i)$ is non-decreasing, if we can afford $i$ items, we can definitely afford $i-1$ items. This allows us to iterate through the array and stop as soon as the cost exceeds $K$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we perform a single linear scan through the array of $N$ items.
- **Space Complexity**: $O(N)$ to store the array $A$. This could be optimized to $O(1)$ by processing the input on the fly, but $O(N)$ is well within limits.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to buy items in sequence 1, 2, ..., N.
 * We have a budget K and one discount coupon to make one item free.
 * Let S[i] be the prefix sum of costs A[1]...A[i].
 * If we buy 'm' items, we want to minimize the cost of these 'm' items
 * by applying the discount to the most expensive item among the first 'm'.
 * 
 * Let M[i] be the maximum cost among the first 'i' items.
 * The cost to buy 'i' items is (S[i] - M[i]).
 * We need to find the largest 'i' such that (S[i] - M[i]) <= K.
 */

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int ans = 0;
    long long current_sum = 0;
    long long max_val = 0;

    for (int i = 0; i < N; ++i) {
        current_sum += A[i];
        if (A[i] > max_val) {
            max_val = A[i];
        }

        // Cost to buy i+1 items is (sum of all items) - (the most expensive one)
        if (current_sum - max_val <= K) {
            ans = i + 1;
        } else {
            // Since the function is monotonic, once we exceed K, we can stop.
            break;
        }
    }

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