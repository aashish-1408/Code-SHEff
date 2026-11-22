# [Lose Less (LOSELESS)](https://www.codechef.com/problems/LOSELESS)

- **Difficulty Rating**: 900
- **Solved in**: 2 attempt(s)

## Problem Summary
Given $M$ matches played and $N$ total points earned, we need to determine the minimum number of losses ($l$) possible. Points are awarded as follows: 3 points for a win ($w$), 1 point for a tie ($t$), and 0 points for a loss ($l$). We are given that $w + t + l = M$ and $3w + t = N$.

## Intuition & Mathematical Observation
To minimize the number of losses ($l$), we must maximize the number of points earned from wins and ties while keeping the total number of matches fixed at $M$.

From the given equations:
1. $w + t + l = M$
2. $3w + t = N$

Subtracting the first from the second:
$(3w + t) - (w + t + l) = N - M$
$2w - l = N - M$
$l = 2w - N + M$

To minimize $l$, we need to minimize $w$. However, $w$ is constrained by:
- $w \ge 0$
- $t \ge 0 \implies N - 3w \ge 0 \implies w \le N/3$
- $w + t \le M \implies w + (N - 3w) \le M \implies N - 2w \le M \implies 2w \ge N - M$

Combining these, the minimum $w$ is $\max(0, \lceil \frac{N-M}{2} \rceil)$. Using integer arithmetic, $\lceil \frac{N-M}{2} \rceil$ can be calculated as `(N - M + 1) / 2` for non-negative results. Once the minimum $w$ is found, we substitute it back into the equation $l = M - N + 2w$ to find the minimum losses.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and results.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We have M matches and N points.
 * w = wins (3 pts), t = ties (1 pt), l = losses (0 pts)
 * w + t + l = M
 * 3w + t = N
 * 
 * Derived formula: l = 2w - N + M
 * To minimize l, we minimize w subject to constraints.
 */

void solve() {
    int M, N;
    if (!(cin >> M >> N)) return;
    
    // Calculate minimum w using the derived constraint 2w >= N - M
    // We use (N - M + 1) / 2 to perform ceiling division for positive values
    int min_w = max(0, (N - M + 1) / 2);
    
    // Calculate l using the derived formula
    int l = 2 * min_w - N + M;
    
    cout << l << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```