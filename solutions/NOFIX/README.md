# [Avoid Fixed Points (NOFIX)](https://www.codechef.com/problems/NOFIX)

- **Difficulty Rating**: 1250
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers (1-indexed), we want to ensure that no element satisfies the condition $A[i] = i$. We are allowed to perform an operation where we insert an arbitrary integer at the beginning of the array. Each insertion shifts all existing elements one position to the right. We need to find the minimum number of insertions required to ensure that $A[i] \neq i$ for all $i$.

## Intuition & Mathematical Observation
The core observation is that inserting an element at the beginning of the array shifts the index of every existing element by $+1$. 

If we have performed `count` insertions, an element originally at index $i$ (1-indexed) will now be at index $i + \text{count}$. A fixed point occurs if the value $A[i]$ equals the current index. Therefore, the condition for a fixed point becomes:
$$A[i] = i + \text{count}$$

We can iterate through the array linearly. Whenever we encounter an index $i$ where $A[i] = i + \text{count}$, we must perform an insertion to shift the remaining elements. By incrementing `count` by 1, we effectively shift all subsequent elements, resolving the current conflict. Because each insertion shifts all elements to the right, this greedy approach is optimal as it resolves the current conflict while simultaneously adjusting the indices of all future elements.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of elements in the array. We perform a single pass through the array to check for fixed points.
- **Space Complexity**: $O(N)$ to store the input array. This could be optimized to $O(1)$ if we process the input elements on the fly.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to ensure that for all i, A[i] != i.
 * If we have a fixed point at index i (A[i] == i), we can insert an element 
 * at the beginning of the array. This shifts all elements to the right by 1.
 * If an element was at index i, it moves to index i+1.
 * 
 * Let 'count' be the number of insertions performed so far.
 * An element originally at index i (1-indexed) will be at index i + count.
 * We have a fixed point if A[i] == i + count.
 * We iterate through the array, and every time we find an index i such that 
 * A[i] == i + count, we increment 'count'.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int count = 0;
    for (int i = 0; i < N; ++i) {
        // Current index is (i + 1). After 'count' insertions, 
        // the element originally at index (i + 1) is now at index (i + 1 + count).
        // We have a fixed point if A[i] == (i + 1 + count).
        if (A[i] == (i + 1 + count)) {
            count++;
        }
    }
    cout << count << "\n";
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