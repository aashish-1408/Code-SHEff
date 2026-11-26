# [Carrot Collection (CARRCOL)](https://www.codechef.com/problems/CARRCOL)

- **Difficulty Rating**: 914
- **Solved in**: 1 attempt(s)

## Problem Summary
The forest consists of $N$ clearings, each containing a certain number of carrots. A bear patrols a specific range of clearings $[L, R]$. The rabbit cannot enter any clearing within this range. The rabbit must choose to stay in either the clearings before the patrol ($[1, L-1]$) or the clearings after the patrol ($[R+1, N]$). The goal is to determine the maximum number of carrots the rabbit can collect by choosing the optimal region.

## Intuition & Mathematical Observation
The patrol range $[L, R]$ acts as a barrier that splits the forest into two disjoint sets of clearings:
1. **Left Region**: Clearings from index $1$ to $L-1$.
2. **Right Region**: Clearings from index $R+1$ to $N$.

Since the rabbit cannot cross the patrol zone, it is confined to one of these two regions. To maximize the carrots collected, we simply calculate the sum of carrots in the left region and the sum of carrots in the right region, then output the maximum of the two values.

- If $L=1$, the left region is empty (sum = 0).
- If $R=N$, the right region is empty (sum = 0).
- The constraints are small ($N \le 100$), so a simple linear scan or summation is highly efficient.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array to calculate the sums. Given $T$ test cases, the total time complexity is $O(T \times N)$.
- **Space Complexity**: $O(N)$ to store the number of carrots in each clearing.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The bear patrols clearings [L, R].
 * The rabbit cannot visit any clearing in the range [L, R].
 * This effectively splits the forest into two potential disconnected regions:
 * 1. Clearings [1, L-1] (if L > 1)
 * 2. Clearings [R+1, N] (if R < N)
 * 
 * Strategy:
 * 1. Calculate the sum of carrots in the range [1, L-1].
 * 2. Calculate the sum of carrots in the range [R+1, N].
 * 3. The answer is the maximum of these two sums.
 */

void solve() {
    int N, L, R;
    cin >> N >> L >> R;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    long long sum_left = 0;
    // Sum of carrots in [1, L-1]
    if (L > 1) {
        for (int i = 1; i < L; ++i) {
            sum_left += A[i];
        }
    }

    long long sum_right = 0;
    // Sum of carrots in [R+1, N]
    if (R < N) {
        for (int i = R + 1; i <= N; ++i) {
            sum_right += A[i];
        }
    }

    cout << max(sum_left, sum_right) << "\n";
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