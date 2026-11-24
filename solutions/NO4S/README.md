# [No 4 Please (NO4S)](https://www.codechef.com/problems/NO4S)

- **Difficulty Rating**: 993
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array consisting only of the integers $\{1, 2, 3\}$, we need to find the minimum number of elements to remove such that no two elements in the remaining array sum up to $4$.

## Intuition & Mathematical Observation
To ensure no two elements sum to $4$, we must avoid the following pairs:
1. **$(1, 3)$**: If the array contains both $1$s and $3$s, their sum is $4$. Therefore, we must choose to keep either all $1$s (and remove all $3$s) or keep all $3$s (and remove all $1$s).
2. **$(2, 2)$**: If the array contains more than one $2$, any pair of them will sum to $4$. Therefore, we can keep at most one $2$.

Based on these constraints, we have two primary strategies to minimize deletions:

*   **Strategy A (Keep 1s):**
    *   Remove all $3$s.
    *   If there are $2$s, keep only one and remove the rest (i.e., remove $\max(0, \text{count}_2 - 1)$).
    *   Total deletions: $\text{count}_3 + \max(0, \text{count}_2 - 1)$.

*   **Strategy B (Keep 3s):**
    *   Remove all $1$s.
    *   If there are $2$s, keep only one and remove the rest.
    *   Total deletions: $\text{count}_1 + \max(0, \text{count}_2 - 1)$.

The final answer is the minimum of these two strategies.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We iterate through the array exactly once to count the occurrences of $1, 2,$ and $3$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the counts regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array is "good" if no two elements sum to 4.
 * The elements are restricted to {1, 2, 3}.
 * Pairs that sum to 4: (1, 3) and (2, 2).
 * 
 * Strategy:
 * Count the occurrences of 1, 2, and 3.
 * Option A: Keep 1s, remove all 3s, keep at most one 2.
 * Option B: Keep 3s, remove all 1s, keep at most one 2.
 */

void solve() {
    int N;
    cin >> N;
    int count1 = 0, count2 = 0, count3 = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a == 1) count1++;
        else if (a == 2) count2++;
        else if (a == 3) count3++;
    }

    // Calculate deletions for both strategies
    int deletions_if_keep_1 = count3 + (count2 > 0 ? count2 - 1 : 0);
    int deletions_if_keep_3 = count1 + (count2 > 0 ? count2 - 1 : 0);

    cout << min(deletions_if_keep_1, deletions_if_keep_3) << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```