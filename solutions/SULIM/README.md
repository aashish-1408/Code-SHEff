# [Sugar Limit (SULIM)](https://www.codechef.com/problems/SULIM)

- **Difficulty Rating**: 1111
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ snacks, each with a sugar content $A_i$ and a sugar limit $B_i$. Chef chooses a threshold $L \ge 0$. For a chosen $L$, Chef can consume any subset of snacks where the sugar limit $B_i \le L$. The goal is to maximize the total sugar consumed minus the threshold $L$ (i.e., $\sum A_i - L$).

## Intuition & Mathematical Observation
1. **Optimal Strategy for a fixed $L$**: If we fix $L$, to maximize the total sugar, we should consume every snack $i$ that satisfies $B_i \le L$ and has a positive sugar content ($A_i > 0$). If $A_i \le 0$, consuming it would only decrease our total sum, so we ignore it.
2. **Range of $L$**: The problem states $B_i$ are integers between $1$ and $100$. 
   - If we choose $L > 100$, the set of available snacks remains identical to the set available at $L = 100$. However, the penalty $L$ increases, which strictly decreases the total satisfaction.
   - Therefore, we only need to test $L$ in the range $[0, 100]$.
3. **Base Case**: Since Chef can choose to eat nothing (e.g., by setting $L=0$), the minimum possible satisfaction is $0$.

## Complexity Analysis
- **Time Complexity**: $O(T \times L_{max} \times N)$, where $T$ is the number of test cases, $L_{max} = 100$, and $N$ is the number of snacks. Given the constraints, this performs roughly $100 \times N$ operations per test case, which easily fits within the time limit.
- **Space Complexity**: $O(N)$ to store the arrays $A$ and $B$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef chooses a threshold L >= 0.
 * For a fixed L, Chef can eat any subset of snacks where B_i <= L.
 * To maximize (Sum of A_i - L), for a fixed L, Chef should pick all snacks 
 * where B_i <= L AND A_i > 0.
 * 
 * Let S(L) = sum of all A_i such that (B_i <= L and A_i > 0).
 * Satisfaction = S(L) - L.
 * Since B_i are integers between 1 and 100, L only needs to be checked for 
 * values in the range [0, 100]. If L > 100, S(L) remains the same as S(100), 
 * but (S(L) - L) decreases, so L > 100 is never optimal.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    long long max_satisfaction = 0;

    // L can be any non-negative integer. 
    // Given B_i <= 100, checking L from 0 to 100 is sufficient.
    for (int L = 0; L <= 100; ++L) {
        long long current_sum = 0;
        for (int i = 0; i < N; ++i) {
            if (B[i] <= L && A[i] > 0) {
                current_sum += A[i];
            }
        }
        long long satisfaction = current_sum - L;
        if (satisfaction > max_satisfaction) {
            max_satisfaction = satisfaction;
        }
    }

    cout << max_satisfaction << "\n";
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