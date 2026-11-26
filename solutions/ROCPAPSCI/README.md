# [Rock Paper Scissors (ROCPAPSCI)](https://www.codechef.com/problems/ROCPAPSCI)

- **Difficulty Rating**: 1220
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is playing a game of Rock-Paper-Scissors against Roku. Roku plays a sequence of $N$ moves. Chef must also play $N$ moves, but with one constraint: Chef cannot play the same move twice in a row. The goal is to maximize the total number of wins Chef achieves against Roku's sequence.

## Intuition & Mathematical Observation
This problem can be modeled using **Dynamic Programming**. Since the decision at index $i$ depends only on the move chosen at index $i-1$, we can maintain the state of the maximum wins achieved ending with each possible move ('R', 'P', or 'S').

1.  **State Definition**: Let `dp[curr]` be the maximum number of wins Chef can have after playing move `curr` at the current step.
2.  **Transitions**: For each step $i$ from $0$ to $N-1$:
    *   We calculate the potential wins for each possible move `curr` (0 for 'R', 1 for 'P', 2 for 'S').
    *   To calculate `next_dp[curr]`, we look at all possible moves `prev` from the previous step.
    *   The constraint is `curr != prev`.
    *   `next_dp[curr] = win_val + max(dp[prev])` for all `prev != curr`.
3.  **Base Case**: At the first step ($i=0$), there is no previous move constraint, so we simply evaluate the win condition for each move.
4.  **Optimization**: We only need to keep track of the previous step's DP values to calculate the current step, allowing us to reduce space complexity from $O(N)$ to $O(1)$ (constant space for the 3 moves).

## Complexity Analysis
- **Time Complexity**: $O(N \times 3^2)$, which simplifies to **$O(N)$**. For each of the $N$ moves, we perform a constant number of operations (checking 3 current moves against 3 previous moves).
- **Space Complexity**: **$O(1)$**, as we only store the DP state for the current and previous steps (vectors of size 3).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to maximize wins against a sequence of moves A[i].
 * Chef cannot play the same move twice consecutively.
 * 
 * dp[i][current_move] = (win_condition ? 1 : 0) + max(dp[i-1][prev_move])
 * where prev_move != current_move.
 */

void solve() {
    int N;
    cin >> N;
    string A;
    cin >> A;

    // dp[last_move] stores the max wins ending with that move
    // Initialize with 0
    vector<int> dp(3, 0);

    auto wins = [](char chef, char roku) {
        if (chef == 'R' && roku == 'S') return true;
        if (chef == 'P' && roku == 'R') return true;
        if (chef == 'S' && roku == 'P') return true;
        return false;
    };

    char moves[] = {'R', 'P', 'S'};

    for (int i = 0; i < N; ++i) {
        vector<int> next_dp(3, -1e9);
        for (int curr = 0; curr < 3; ++curr) {
            int win_val = wins(moves[curr], A[i]) ? 1 : 0;
            for (int prev = 0; prev < 3; ++prev) {
                // Constraint: Cannot play same move twice consecutively
                if (i == 0 || curr != prev) {
                    next_dp[curr] = max(next_dp[curr], dp[prev] + win_val);
                }
            }
        }
        dp = next_dp;
    }

    cout << max({dp[0], dp[1], dp[2]}) << "\n";
}

int main() {
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