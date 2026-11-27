# [Chococut (CHOCUT)](https://www.codechef.com/problems/CHOCUT)

- **Difficulty Rating**: 1003
- **Solved in**: 2 attempt(s)

## Problem Summary
Alice has a chocolate bar of size $N \times M$. She wants to give Bob a piece of size at least $K$. To do this, she can make exactly one cut (either horizontal or vertical) to divide the bar into two rectangular pieces. After cutting, she gives one piece to Bob (which must be $\ge K$) and keeps the other piece for herself. The goal is to maximize the size of the piece Alice keeps. If it is impossible to give Bob a piece of size $\ge K$, the answer is 0.

## Intuition & Mathematical Observation
1. **No Cut Scenario**: If $K=0$, Alice keeps the entire bar ($N \times M$). If $K > 0$, she must make a cut.
2. **Horizontal Cuts**: A horizontal cut at row $i$ (where $1 \le i < N$) splits the bar into two pieces: $i \times M$ and $(N-i) \times M$. We check if either piece satisfies the condition $\ge K$. If it does, the other piece is a candidate for the maximum size Alice can keep.
3. **Vertical Cuts**: A vertical cut at column $j$ (where $1 \le j < M$) splits the bar into two pieces: $N \times j$ and $N \times (M-j)$. Similarly, we check if either piece satisfies the condition $\ge K$ and track the maximum size of the remaining piece.
4. **Constraints**: Since $N$ and $M$ are relatively small (implied by the problem constraints), iterating through all possible cut positions is efficient enough.

## Complexity Analysis
- **Time Complexity**: $O(N + M)$ per test case. We iterate through all possible horizontal cuts ($N-1$ iterations) and all possible vertical cuts ($M-1$ iterations).
- **Space Complexity**: $O(1)$, as we only use a few variables to track the maximum size and current piece dimensions.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has an N x M chocolate bar.
 * Total squares = N * M.
 * 
 * Options:
 * 1. No cut: 
 *    - If K == 0, Alice can keep the whole bar (N*M).
 * 2. Horizontal cut:
 *    - Cut into (i * M) and ((N-i) * M).
 *    - If (i * M) >= K, she can keep ((N-i) * M).
 *    - If ((N-i) * M) >= K, she can keep (i * M).
 * 3. Vertical cut:
 *    - Cut into (N * j) and (N * (M-j)).
 *    - If (N * j) >= K, she can keep (N * (M-j)).
 *    - If (N * (M-j)) >= K, she can keep (N * j).
 */

void solve() {
    long long N, M, K;
    cin >> N >> M >> K;

    // If K is 0, Alice keeps everything without cutting.
    if (K == 0) {
        cout << N * M << "\n";
        return;
    }

    long long max_kept = 0;

    // Case: Horizontal cut
    for (int i = 1; i < N; ++i) {
        long long piece1 = (long long)i * M;
        long long piece2 = (long long)(N - i) * M;
        
        if (piece1 >= K) max_kept = max(max_kept, piece2);
        if (piece2 >= K) max_kept = max(max_kept, piece1);
    }

    // Case: Vertical cut
    for (int j = 1; j < M; ++j) {
        long long piece1 = (long long)N * j;
        long long piece2 = (long long)N * (M - j);
        
        if (piece1 >= K) max_kept = max(max_kept, piece2);
        if (piece2 >= K) max_kept = max(max_kept, piece1);
    }

    cout << max_kept << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```