# [Maximum Alternating Sum (MXALT)](https://www.codechef.com/problems/MXALT)

- **Difficulty Rating**: 1111
- **Solved in**: 3 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we want to rearrange the elements to maximize the alternating sum defined as:
$$S = A_1 - A_2 + A_3 - A_4 + \dots + (-1)^{N-1} A_N$$
We are allowed to reorder the array elements in any way we choose to achieve the maximum possible value for $S$.

## Intuition & Mathematical Observation
The alternating sum expression can be grouped based on the signs of the elements:
- Elements at odd positions ($1, 3, 5, \dots$) are added.
- Elements at even positions ($2, 4, 6, \dots$) are subtracted.

In an array of size $N$:
- The number of elements added is $\lceil N/2 \rceil$.
- The number of elements subtracted is $\lfloor N/2 \rfloor$.

To maximize the total sum, we should assign the largest available values to the positions that are added and the smallest available values to the positions that are subtracted. 

**Strategy:**
1. Sort the array $A$ in non-decreasing order.
2. The first $\lfloor N/2 \rfloor$ elements (the smallest ones) will be subtracted.
3. The remaining $\lceil N/2 \rceil$ elements (the largest ones) will be added.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case, dominated by the sorting step. Given the constraints ($N \le 2 \cdot 10^5$), this is well within the time limit.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * The alternating sum is A_1 - A_2 + A_3 - A_4 + ...
 * There are ceil(N/2) positive positions and floor(N/2) negative positions.
 * To maximize the sum, we assign the largest values to the positive positions
 * and the smallest values to the negative positions.
 * 
 * Complexity: O(N log N) per test case due to sorting.
 * Total complexity: O(T * N log N), which fits within the 2*10^5 constraint.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort the array to easily pick smallest and largest elements
    sort(A.begin(), A.end());

    long long ans = 0;
    int num_neg = N / 2;

    // Subtract the smallest N/2 elements
    for (int i = 0; i < num_neg; ++i) {
        ans -= A[i];
    }
    
    // Add the remaining elements (the largest ones)
    for (int i = num_neg; i < N; ++i) {
        ans += A[i];
    }

    cout << ans << "\n";
}

int main() {
    // Fast I/O is essential for large input sizes
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```