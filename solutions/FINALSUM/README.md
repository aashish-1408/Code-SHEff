# [Final Sum (FINALSUM)](https://www.codechef.com/problems/FINALSUM)

- **Difficulty Rating**: 1145
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we perform $Q$ operations. In each operation, we are given a range $[L, R]$. For this range, we perform the following updates:
- Add $1$ to $A[L]$
- Subtract $1$ from $A[L+1]$
- Add $1$ to $A[L+2]$
- Subtract $1$ from $A[L+3]$
- ... and so on, until index $R$.

We need to find the total sum of the array after all $Q$ operations are completed.

## Intuition & Mathematical Observation
The key to solving this problem efficiently is to observe the net change in the total sum of the array for a single operation on the range $[L, R]$.

The sequence of changes applied to the subarray is $+1, -1, +1, -1, \dots$.
- Let $len = R - L + 1$ be the number of elements in the range.
- If $len$ is **even**, the number of $+1$s equals the number of $-1$s. The net change to the total sum is $(+1) + (-1) + \dots = 0$.
- If $len$ is **odd**, there is one more $+1$ than $-1$. The net change to the total sum is $+1$.

The length $len = R - L + 1$ is odd if and only if $(R - L)$ is even. Therefore, for every query, we simply check the parity of $(R - L)$. If $(R - L) \pmod 2 == 0$, we increment the total sum by $1$. Otherwise, the sum remains unchanged.

This approach allows us to calculate the final sum in $O(N + Q)$ time, avoiding the need to perform actual array updates.

## Complexity Analysis
- **Time Complexity**: $O(N + Q)$, where $N$ is the number of elements in the array and $Q$ is the number of queries. We iterate through the array once to calculate the initial sum and then iterate through the queries once.
- **Space Complexity**: $O(1)$, as we only store the running sum and a few integer variables, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * In one operation on subarray [L, R], we add 1 to A[L], subtract 1 from A[L+1], 
 * add 1 to A[L+2], subtract 1 from A[L+3], and so on.
 * 
 * The net change to the sum is +1 if the subarray length (R - L + 1) is odd,
 * and 0 if the subarray length is even.
 */

void solve() {
    int N, Q;
    if (!(cin >> N >> Q)) return;
    
    long long current_sum = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        current_sum += a;
    }
    
    for (int i = 0; i < Q; ++i) {
        int L, R;
        cin >> L >> R;
        // The length of the subarray is R - L + 1.
        // If length is odd, sum increases by 1.
        // Length is odd if (R - L + 1) % 2 != 0, which is (R - L) % 2 == 0.
        if ((R - L) % 2 == 0) {
            current_sum += 1;
        }
    }
    
    cout << current_sum << "\n";
}

int main() {
    // Fast I/O
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