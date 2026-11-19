# [School of Geometry (SNUG_FIT)](https://www.codechef.com/problems/SNUG_FIT)

- **Difficulty Rating**: -1
- **Solved in**: 2 attempt(s)

## Problem Summary
Given two sets of $N$ integers, $A$ and $B$, we need to form $N$ pairs by matching each element $A_i$ with exactly one element $B_j$. For each pair $(A_i, B_j)$, the diameter of the largest inscribed circle is defined as $\min(A_i, B_j)$. The goal is to find a permutation of $B$ such that the sum of these diameters, $\sum_{i=1}^N \min(A_i, B_{P_i})$, is maximized.

## Intuition & Mathematical Observation
To maximize the sum of minimums, we want to avoid pairing a very large number with a very small number, as the small number will "bottleneck" the result. 

By sorting both arrays $A$ and $B$ in non-decreasing order, we ensure that the smallest elements are paired with the smallest, and the largest with the largest. This strategy effectively pairs elements of similar magnitudes, preventing large values from being wasted on small values. This is a classic greedy approach: pairing the $i$-th smallest element of $A$ with the $i$-th smallest element of $B$ yields the optimal sum.

## Complexity Analysis
- **Time Complexity**: $O(T \cdot N \log N)$, where $T$ is the number of test cases and $N$ is the number of elements. The dominant factor is the sorting of the two arrays.
- **Space Complexity**: $O(N)$ to store the input arrays $A$ and $B$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * For a rectangle with dimensions A_i x B_j, the diameter of the largest 
 * inscribed circle is min(A_i, B_j).
 * We want to maximize the sum of diameters: sum_{i=1}^N min(A_i, B_{P_i}).
 * 
 * By sorting both arrays A and B in non-decreasing order and pairing 
 * A[i] with B[i], we maximize the sum of the minimums.
 * 
 * Complexity:
 * Sorting: O(N log N)
 * Summation: O(N)
 * Total: O(T * N log N), which is well within the 1.5s limit for N=10^4.
 * Data types: A_i, B_i up to 10^9, so the sum can exceed 2^31-1. 
 * Using long long for the sum is necessary.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }
    
    // Sorting both arrays to pair smallest with smallest
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    long long total_diameter = 0;
    for (int i = 0; i < N; ++i) {
        total_diameter += min(A[i], B[i]);
    }
    
    cout << total_diameter << "\n";
}

int main() {
    // Optimize I/O operations
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