# [Even Sum Subarray (EVENSUMSUB)](https://www.codechef.com/problems/EVENSUMSUB)

- **Difficulty Rating**: 1079
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, the goal is to find the length of the longest contiguous subarray such that the sum of its elements is even. If no such subarray exists, the answer is 0.

## Intuition & Mathematical Observation
Since the constraint on $N$ is small ($N \le 50$), we do not need an optimized linear-time solution. An $O(N^2)$ approach is sufficient to explore all possible contiguous subarrays.

1.  **Subarray Generation**: A contiguous subarray is defined by its starting index $i$ and ending index $j$ (where $0 \le i \le j < N$).
2.  **Sum Calculation**: For every starting index $i$, we can iterate through all possible ending indices $j$ and maintain a running sum.
3.  **Parity Check**: As we extend the subarray by incrementing $j$, we update the `current_sum`. If `current_sum % 2 == 0`, the subarray $[i, j]$ has an even sum. We then calculate its length ($j - i + 1$) and update our global maximum if this length is greater than the previously recorded maximum.

## Complexity Analysis
- **Time Complexity**: $O(N^2)$, where $N$ is the number of elements in the array. We use nested loops to iterate through all possible subarrays, which is well within the limits for $N=50$.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to find the length of the longest contiguous subarray with an even sum.
 * Given N <= 50, an O(N^2) approach is perfectly acceptable and efficient.
 * 
 * Logic:
 * 1. Iterate through all possible starting indices 'i'.
 * 2. Maintain a running sum for subarrays starting at 'i' and ending at 'j'.
 * 3. If the sum is even, update the maximum length.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int max_len = 0;

    // Iterate over all possible starting points of a subarray
    for (int i = 0; i < N; ++i) {
        long long current_sum = 0;
        // Iterate over all possible ending points
        for (int j = i; j < N; ++j) {
            current_sum += A[j];
            
            // Check if the sum is even
            if (current_sum % 2 == 0) {
                int current_len = j - i + 1;
                if (current_len > max_len) {
                    max_len = current_len;
                }
            }
        }
    }

    cout << max_len << "\n";
}

int main() {
    // Fast I/O to ensure no overhead
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