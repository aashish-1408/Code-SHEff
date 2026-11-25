# [Sed Sequences (SEDARR)](https://www.codechef.com/problems/SEDARR)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ positive integers and an integer $K$, we want to determine the minimum number of operations required to make the sum of the array elements divisible by $K$. In one operation, we can replace any element of the array with any positive integer.

## Intuition & Mathematical Observation
The problem asks for the minimum number of changes to make the total sum $S$ divisible by $K$.

1. **Case 1: $S \pmod K = 0$**
   If the sum of the array is already divisible by $K$, we do not need to perform any operations. The answer is $0$.

2. **Case 2: $S \pmod K \neq 0$**
   If the sum is not divisible by $K$, we need to change at least one element. Let the current sum be $S$. We want to change one element $A_i$ to $A_i'$ such that:
   $$(S - A_i + A_i') \equiv 0 \pmod K$$
   This simplifies to:
   $$A_i' \equiv (A_i - S) \pmod K$$
   Since we are allowed to choose any positive integer $A_i'$, we can always find a value that satisfies this congruence. Therefore, we only ever need **at most one operation** to make the sum divisible by $K$.

Thus, the answer is simply $0$ if the sum is divisible by $K$, and $1$ otherwise.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we must iterate through the array once to calculate the sum.
- **Space Complexity**: $O(1)$ auxiliary space, as we only store the running sum and input variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a sequence A of N positive integers and a divisor K.
 * We want the sum of the sequence to be divisible by K.
 * We can change any element to any positive integer.
 * 
 * Let S be the sum of the elements in the sequence.
 * If S % K == 0, we need 0 operations.
 * If S % K != 0, we can change exactly one element to make the sum divisible by K.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(1) auxiliary space.
 */

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        long long a;
        cin >> a;
        sum += a;
    }
    
    if (sum % K == 0) {
        cout << 0 << "\n";
    } else {
        cout << 1 << "\n";
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