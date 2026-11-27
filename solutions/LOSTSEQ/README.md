# [Careless Chef (LOSTSEQ)](https://www.codechef.com/problems/LOSTSEQ)

- **Difficulty Rating**: 1345
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a sequence $B$ of length $2N$, which was generated from an original sequence $A$ of length $N$ and an integer $k$. For each element $A_i$ in the original sequence, two elements $(A_i - k)$ and $(A_i + k)$ were added to $B$. We need to determine if a given sequence $B$ could have been generated this way for some sequence $A$ and some integer $k$.

## Intuition & Mathematical Observation
For each $A_i$, the two corresponding elements in $B$ are $x = A_i - k$ and $y = A_i + k$. 
If we sum these two elements:
$$x + y = (A_i - k) + (A_i + k) = 2A_i$$

Since $2A_i$ is always even, the sum of every pair $(x, y)$ must be even. For the sum of two integers to be even, both integers must have the same parity (either both are even or both are odd).

1. If we have a pair of even numbers, their sum is even.
2. If we have a pair of odd numbers, their sum is even.
3. If we have one even and one odd number, their sum is odd.

Since every pair must have an even sum, we must pair up all numbers in $B$ such that each pair consists of two numbers with the same parity. This is only possible if the total count of odd numbers in $B$ is **even**. If the count of odd numbers is odd, there will inevitably be at least one pair consisting of one odd and one even number, resulting in an odd sum, which contradicts the construction rule.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the $2N$ elements of the sequence exactly once.
- **Space Complexity**: $O(1)$, as we only store the count of odd numbers and do not need to store the entire array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each element A_i, we add (A_i - k) and (A_i + k) to B.
 * Let the two elements added for A_i be x and y.
 * x = A_i - k
 * y = A_i + k
 * Summing these: x + y = (A_i - k) + (A_i + k) = 2 * A_i.
 * This implies that for every pair (x, y) chosen from B, their sum must be even.
 * 
 * If the sum of two numbers is even, it means both numbers must have the same parity.
 * That is, either both are even or both are odd.
 * 
 * Therefore, the sequence B must contain an even number of odd integers.
 */

void solve() {
    int N;
    cin >> N;
    int odd_count = 0;
    // The sequence B has 2*N elements
    for (int i = 0; i < 2 * N; ++i) {
        long long val;
        cin >> val;
        // Check parity: works for both positive and negative integers
        if (abs(val) % 2 != 0) {
            odd_count++;
        }
    }

    // If the count of odd numbers is even, we can pair them up
    if (odd_count % 2 == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
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