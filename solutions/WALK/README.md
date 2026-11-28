# [Walk (WALK)](https://www.codechef.com/problems/WALK)

- **Difficulty Rating**: 1247
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given an array $W$ of length $N$, where $W_i$ represents the minimum velocity required to pass through the $i$-th segment. When you pass through a segment, your velocity decreases by 1. You need to find the minimum initial velocity $V$ required such that you can successfully traverse all $N$ segments without your velocity dropping below the required threshold for any segment.

## Intuition & Mathematical Observation
Let $V$ be the initial velocity at the first segment (index $i=0$).
- At segment $i$ (0-indexed), your velocity will have decreased by $i$ units due to the previous segments.
- Therefore, your velocity at segment $i$ will be $V - i$.
- The condition to pass segment $i$ is: $V - i \geq W_i$.
- Rearranging this inequality, we get: $V \geq W_i + i$.

To satisfy this condition for every segment from $0$ to $N-1$, the initial velocity $V$ must be at least the maximum value of $(W_i + i)$ for all $i$. Thus:
$$V_{min} = \max_{0 \leq i < N} (W_i + i)$$

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array exactly once to calculate the maximum value.
- **Space Complexity**: $O(1)$, as we only store the current maximum and the input value, requiring no additional data structures proportional to $N$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let V be the initial velocity at the first segment.
 * At segment i (0-indexed), the velocity will be V - i.
 * The condition for each segment i is:
 * V - i >= W_i
 * V >= W_i + i
 * 
 * To satisfy this for all i from 0 to N-1, we need:
 * V >= max(W_i + i) for all i.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    long long max_v = 0;
    for (int i = 0; i < N; ++i) {
        long long w;
        cin >> w;
        // Calculate the minimum velocity required to pass this specific segment
        long long current_required = w + i;
        // Update the global maximum required velocity
        if (current_required > max_v) {
            max_v = current_required;
        }
    }
    cout << max_v << "\n";
}

int main() {
    // Fast I/O for performance
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