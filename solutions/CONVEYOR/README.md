# [Conveyor Belt (CONVEYOR)](https://www.codechef.com/problems/CONVEYOR)

- **Difficulty Rating**: 1034
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given a conveyor belt represented by a string of length $N$ consisting of 'L' (left) and 'R' (right) directions. An object is placed at position $P$ (1-indexed). 
- If the object moves to the left and reaches index 0, it is collected.
- If the object moves to the right and reaches index $N+1$, it is collected.
You can reverse the direction of any slot on the belt. The goal is to find the minimum number of reversals required to ensure the object reaches either the left or right collection point.

## Intuition & Mathematical Observation
To make the object reach a specific collection point, every slot in its path must point toward that destination.

1.  **Reaching the Left (0):**
    For the object to reach the left end starting from $P$, every slot from index $1$ to $P$ must be 'L'. If any slot in this range is 'R', it must be flipped. Therefore, the cost is the count of 'R' characters in the substring $S[0 \dots P-1]$.

2.  **Reaching the Right ($N+1$):**
    For the object to reach the right end starting from $P$, every slot from index $P$ to $N$ must be 'R'. If any slot in this range is 'L', it must be flipped. Therefore, the cost is the count of 'L' characters in the substring $S[P-1 \dots N-1]$.

The final answer is simply the minimum of these two calculated costs.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the string to count the required reversals.
- **Space Complexity**: $O(N)$ to store the string $S$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To reach 0 (left collection point):
 * All slots from 1 to P must be 'L'. If any slot i (1 <= i <= P) is 'R', 
 * it must be reversed to 'L'.
 * Cost to reach 0 = count of 'R' in S[0...P-1].
 * 
 * To reach N+1 (right collection point):
 * All slots from P to N must be 'R'. If any slot i (P <= i <= N) is 'L', 
 * it must be reversed to 'R'.
 * Cost to reach N+1 = count of 'L' in S[P-1...N-1].
 */

void solve() {
    int N, P;
    cin >> N >> P;
    string S;
    cin >> S;

    // Cost to reach 0: count 'R' in S[0...P-1]
    int cost_left = 0;
    for (int i = 0; i < P; ++i) {
        if (S[i] == 'R') {
            cost_left++;
        }
    }

    // Cost to reach N+1: count 'L' in S[P-1...N-1]
    int cost_right = 0;
    for (int i = P - 1; i < N; ++i) {
        if (S[i] == 'L') {
            cost_right++;
        }
    }

    cout << min(cost_left, cost_right) << "\n";
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