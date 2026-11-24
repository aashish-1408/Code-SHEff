# [Infernos (INFERNO)](https://www.codechef.com/problems/INFERNO)

- **Difficulty Rating**: 1162
- **Solved in**: 1 attempt(s)

## Problem Summary
Ved needs to defeat $N$ enemies, each having a specific health $H_i$. He has two modes of attack:
1. **Single-Target Mode**: Deals $X$ damage to one specific enemy per second.
2. **Multi-Target Mode**: Deals $1$ damage to all living enemies per second.

The goal is to determine the minimum time required to defeat all enemies by choosing the optimal strategy between the two modes.

## Intuition & Mathematical Observation
To solve this, we calculate the time required for each mode independently and take the minimum:

1. **Single-Target Mode**: 
   For each enemy with health $H_i$, the time taken is $\lceil H_i / X \rceil$. Using integer arithmetic, this is calculated as `(H[i] + X - 1) / X`. The total time is the sum of these values across all enemies.

2. **Multi-Target Mode**: 
   In this mode, every enemy takes 1 damage per second. The time required to kill all enemies is determined by the enemy with the highest health, as they will be the last one standing. Thus, the total time is simply $\max(H_i)$.

By comparing the total time from both strategies, we select the smaller value as the final answer.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of enemies. We iterate through the array of health values exactly once to compute the sum and the maximum.
- **Space Complexity**: $O(N)$ to store the health values (or $O(1)$ if we process the input on the fly without storing it in a vector).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Single-Target Mode: Total time = sum(ceil(H_i / X)) for all i.
 * 2. Multi-Target Mode: Total time = max(H_i) for all i.
 * The goal is to find the minimum of these two values.
 */

void solve() {
    int N, X;
    cin >> N >> X;
    vector<int> H(N);
    int max_h = 0;
    long long single_target_time = 0;

    for (int i = 0; i < N; ++i) {
        cin >> H[i];
        // Update max health for multi-target mode
        if (H[i] > max_h) {
            max_h = H[i];
        }
        // Calculate time for single-target mode
        // ceil(H[i] / X) is equivalent to (H[i] + X - 1) / X using integer division
        single_target_time += (H[i] + X - 1) / X;
    }

    // The answer is the minimum of the two modes
    long long ans = min((long long)max_h, single_target_time);
    cout << ans << "\n";
}

int main() {
    // Fast I/O
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