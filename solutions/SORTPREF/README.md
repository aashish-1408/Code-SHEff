# [Sorting Prefixes (SORTPREF)](https://www.codechef.com/problems/SORTPREF)

- **Difficulty Rating**: 1291
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of size $N$ containing a permutation of numbers from $1$ to $N$, we want to sort the array such that $A[i] = i+1$ for all $i$. We are allowed to perform an operation at any index $i$ (where $0 \le i < N$), which sorts the prefix $A[0 \dots i]$. The cost of this operation is $A[i]$. We need to find the minimum cost to sort the entire array.

## Intuition & Mathematical Observation
1. **Identify the Goal**: The array is sorted if $A[i] = i+1$ for all $0 \le i < N$.
2. **Find the Out-of-Place Elements**: If the array is already sorted, the cost is $0$. If it is not sorted, we must perform at least one operation.
3. **The Strategy**: 
   - Let `last_unsorted` be the largest index $i$ such that $A[i] \neq i+1$. 
   - Any operation at index $k < \text{last\_unsorted}$ will not be able to fix the element at `last_unsorted` because the prefix sort only affects elements up to $k$.
   - By performing an operation at index `last_unsorted`, we sort the prefix $A[0 \dots \text{last\_unsorted}]$. Since all elements $A[j]$ for $j > \text{last\_unsorted}$ are already in their correct sorted positions ($A[j] = j+1$), sorting the prefix $A[0 \dots \text{last\_unsorted}]$ will result in the entire array being sorted.
   - The cost of this operation is the value $A[\text{last\_unsorted}]$. Since we must perform an operation at or beyond the rightmost out-of-place element, and the cost is defined by the value at the chosen index, picking the rightmost index is the optimal strategy to minimize the cost.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array once to find the `last_unsorted` index.
- **Space Complexity**: $O(N)$ to store the array $A$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We identify the rightmost index 'i' where A[i] is not in its correct 
 * sorted position (i+1). Performing a prefix sort at this index 
 * effectively sorts the entire array because all elements to the right 
 * of this index are already in their correct positions.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int last_unsorted = -1;
    // Find the rightmost index that is not in its correct position
    for (int i = 0; i < N; ++i) {
        if (A[i] != i + 1) {
            last_unsorted = i;
        }
    }

    if (last_unsorted == -1) {
        // Array is already sorted
        cout << 0 << "\n";
    } else {
        // The cost is the value at the rightmost unsorted position
        cout << A[last_unsorted] << "\n";
    }
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