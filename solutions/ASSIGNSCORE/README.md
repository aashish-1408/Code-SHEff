# [Assignment Score (ASSIGNSCORE)](https://www.codechef.com/problems/ASSIGNSCORE)

- **Difficulty Rating**: 794
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has completed $N$ assignments, each worth 100 marks. There is one final assignment remaining, also worth 100 marks. To pass the course, Chef must achieve at least 50% of the total marks across all $N+1$ assignments. Given the scores of the first $N$ assignments, determine the minimum score required on the final assignment to pass. If it is impossible to pass, output -1.

## Intuition & Mathematical Observation
1. **Total Assignments**: There are $N+1$ assignments in total.
2. **Passing Criteria**: The total marks available are $(N+1) \times 100$. To pass, Chef needs at least 50% of this total, which is:
   $$\text{Target} = \frac{50}{100} \times (N+1) \times 100 = 50 \times (N+1)$$
3. **Calculation**: Let $S$ be the sum of the scores of the first $N$ assignments. Let $X$ be the score of the final assignment. We need:
   $$S + X \geq 50 \times (N+1)$$
   $$X \geq 50 \times (N+1) - S$$
4. **Constraints on $X$**:
   - Since the assignment is out of 100, $0 \leq X \leq 100$.
   - If the calculated $X > 100$, it is impossible to pass, so output `-1`.
   - If the calculated $X < 0$, it means Chef has already secured enough marks to pass even with a 0 on the final assignment, so output `0`.
   - Otherwise, output the calculated $X$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the $N$ given scores once to calculate their sum.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the sum and the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total assignments = N + 1.
 * Each assignment is out of 100 marks.
 * Total possible marks = (N + 1) * 100.
 * Passing criteria: Score >= 50% of total marks.
 * Passing marks = 0.5 * (N + 1) * 100 = 50 * (N + 1).
 * 
 * Let S be the sum of the first N assignments.
 * Let X be the score of the (N+1)-th assignment.
 * We need: S + X >= 50 * (N + 1)
 * Therefore: X >= 50 * (N + 1) - S
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            sum += a;
        }

        // Target total marks needed to pass
        long long target = 50LL * (n + 1);
        
        // Minimum score needed on the last assignment
        long long needed = target - sum;

        if (needed > 100) {
            // Even with 100, he cannot reach the target
            cout << -1 << "\n";
        } else if (needed < 0) {
            // He already has more than 50%
            cout << 0 << "\n";
        } else {
            // He needs exactly 'needed' marks
            cout << needed << "\n";
        }
    }

    return 0;
}
```