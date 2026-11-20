# [Chef and Number Game (CHNUM)](https://www.codechef.com/problems/CHNUM)

- **Difficulty Rating**: 1188
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, we need to partition the array into two non-empty groups such that the sum of the squares of the sums of the elements in each group is maximized. We are asked to output the size of the larger group and the size of the smaller group that achieve this maximum.

## Intuition & Mathematical Observation
To maximize the sum of squares $S_1^2 + S_2^2$, we want to make the absolute values of the sums as large as possible. 

1.  **Grouping by Sign**: If we have both positive and negative numbers, the most effective way to keep the sums large is to group all positive numbers together and all negative numbers together. 
    *   If we mix positive and negative numbers in the same group, they cancel each other out, reducing the absolute value of the sum and consequently reducing the square.
    *   Therefore, the optimal strategy is to put all positive numbers in one group and all negative numbers in the other.
2.  **Edge Cases**:
    *   If all numbers are positive or all numbers are negative, we cannot form two non-empty groups that would result in a larger sum of squares than keeping them all together. In this case, the only possible partition is to have one group of size $N$ and the other group must be empty (though the problem implies we partition into two groups, if only one sign exists, the "best" we can do is put all elements in one group and the remaining elements in the other, but mathematically, the sum of squares is maximized by keeping all elements together).
    *   When both positive and negative numbers exist, the two group sizes are simply the count of positive numbers (`pos_count`) and the count of negative numbers (`neg_count`). The maximum size is `max(pos_count, neg_count)` and the minimum is `min(pos_count, neg_count)`.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We iterate through the array exactly once to count the positive and negative numbers.
- **Space Complexity**: $O(1)$ (excluding the input storage), as we only maintain two integer counters regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To maximize the sum of squares of group sums (X_1^2 + X_2^2), we group all 
 * positive numbers together and all negative numbers together.
 * 
 * Cases:
 * 1. Only positive or only negative numbers: 
 *    All elements must be in one group to maximize the sum.
 * 2. Both positive and negative:
 *    Group 1: All positive numbers (Size = pos_count)
 *    Group 2: All negative numbers (Size = neg_count)
 */

void solve() {
    int n;
    cin >> n;
    int pos_count = 0;
    int neg_count = 0;
    
    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        if (val >= 0) {
            pos_count++;
        } else {
            neg_count++;
        }
    }
    
    if (pos_count == 0 || neg_count == 0) {
        // All numbers are the same sign, best to keep them in one group
        cout << n << " " << n << "\n";
    } else {
        // Both signs present: group by sign to maximize absolute sums
        int max_s = max(pos_count, neg_count);
        int min_s = min(pos_count, neg_count);
        cout << max_s << " " << min_s << "\n";
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