# [Download file (DWNLD)](https://www.codechef.com/problems/DWNLD)

- **Difficulty Rating**: 1147
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ time intervals, where each interval $i$ has a duration $T_i$ (in minutes) and a data usage cost $D_i$ (per minute). You are provided with $K$ minutes of free data usage. The free minutes are applied sequentially starting from the first interval. Your task is to calculate the total cost incurred for all data usage beyond the first $K$ minutes.

## Intuition & Mathematical Observation
The problem requires us to process the intervals chronologically. Since the free minutes $K$ are consumed as time passes, we can maintain the remaining balance of $K$ as we iterate through the list of intervals:

1. **Case 1: $K \ge T_i$**: The entire duration of the current interval is covered by the remaining free minutes. We subtract $T_i$ from $K$ and add nothing to the cost.
2. **Case 2: $0 < K < T_i$**: The first $K$ minutes of this interval are free. The remaining $(T_i - K)$ minutes are billable at rate $D_i$. After this, $K$ becomes 0 for all subsequent intervals.
3. **Case 3: $K = 0$**: All minutes in the current interval are billable. We add $(T_i \times D_i)$ to the total cost.

By updating $K$ dynamically, we ensure that we correctly account for the free minutes regardless of which interval they fall into.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of intervals. Since $N \le 10$, this is extremely efficient.
- **Space Complexity**: $O(1)$, as we only use a few variables to track the cost and the remaining free minutes.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N intervals, each with duration Ti and data usage Di per minute.
 * The first K minutes are free. We need to calculate the total cost for the 
 * remaining minutes.
 * 
 * Approach:
 * Iterate through the intervals. For each interval (Ti, Di):
 * 1. If K >= Ti, the entire interval is free. Subtract Ti from K.
 * 2. If 0 < K < Ti, the first K minutes are free, and the remaining (Ti - K) 
 *    minutes are charged at Di per minute. Cost += (Ti - K) * Di. Set K = 0.
 * 3. If K == 0, the entire interval is charged. Cost += Ti * Di.
 */

void solve() {
    int N;
    long long K;
    cin >> N >> K;

    long long total_cost = 0;

    for (int i = 0; i < N; ++i) {
        long long Ti, Di;
        cin >> Ti >> Di;

        if (K >= Ti) {
            // Entire interval is free
            K -= Ti;
        } else if (K > 0) {
            // Part of the interval is free, part is charged
            long long charged_minutes = Ti - K;
            total_cost += charged_minutes * Di;
            K = 0;
        } else {
            // Entire interval is charged
            total_cost += Ti * Di;
        }
    }

    cout << total_cost << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}
```