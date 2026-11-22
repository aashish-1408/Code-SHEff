# [Distinct Opposite Sums (DISTOPPSUMS)](https://www.codechef.com/problems/DISTOPPSUMS)

- **Difficulty Rating**: 1135
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an even integer $N$, we need to construct a permutation $P$ of the numbers from $1$ to $N$ such that all sums of opposite elements, $P[i] + P[N+1-i]$ for $1 \le i \le N/2$, are distinct.

## Intuition & Mathematical Observation
A naive approach of pairing elements from the ends of the sorted sequence (e.g., $1+N, 2+(N-1), \dots$) results in the same sum for every pair, which is invalid. 

To ensure the sums are distinct, we need to pair smaller numbers with smaller numbers and larger numbers with larger numbers in a way that creates an arithmetic progression of sums.

Consider splitting the sequence into two halves:
1. The first half: $1, 2, \dots, N/2$
2. The second half: $N, N-1, \dots, N/2 + 1$

When we pair $P[i]$ with $P[N-1-i]$ (using 0-based indexing):
- For $i=0$: $1 + (N/2 + 1)$
- For $i=1$: $2 + (N/2 + 2)$
- ...
- For $i=N/2 - 1$: $(N/2) + N$

Since each term in the sum increases by 1 as $i$ increases, the resulting sums will be strictly increasing, thus guaranteeing that all sums are distinct.

**Example for $N=6$:**
- First half: `[1, 2, 3]`
- Second half: `[6, 5, 4]`
- Permutation: `[1, 2, 3, 6, 5, 4]`
- Sums: $1+4=5, 2+5=7, 3+6=9$. All are distinct.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array once to fill it and once to print it.
- **Space Complexity**: $O(N)$ to store the permutation.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We construct the permutation by placing 1 to N/2 in the first half 
 * and N down to N/2 + 1 in the second half.
 * This ensures that P[i] + P[N-1-i] increases by 2 for each step,
 * guaranteeing all sums are distinct.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> P(N);
    int half = N / 2;
    
    // Fill first half with 1 to N/2
    for (int i = 0; i < half; ++i) {
        P[i] = i + 1;
    }
    
    // Fill second half with N down to N/2 + 1
    int val = N;
    for (int i = half; i < N; ++i) {
        P[i] = val--;
    }
    
    // Print the resulting permutation
    for (int i = 0; i < N; ++i) {
        cout << P[i] << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Optimize I/O operations
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