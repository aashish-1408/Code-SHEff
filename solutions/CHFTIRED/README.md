# [Chef and Difficult Contests (CHFTIRED)](https://www.codechef.com/problems/CHFTIRED)

- **Difficulty Rating**: 1130
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $a$ and $b$, we are allowed to perform two types of operations any number of times:
1. Choose a positive integer $d$ and update $a \to a + d$ and $b \to b + d - 1$.
2. Choose a positive integer $d$ and update $a \to a + d - 1$ and $b \to b + d$.

The goal is to determine if it is possible to make $a$ equal to $b$ after performing these operations.

## Intuition & Mathematical Observation
Let's analyze how the difference between $a$ and $b$ changes after each operation:

*   **Operation 1:** The new difference is $(a + d) - (b + d - 1) = a - b + 1$.
*   **Operation 2:** The new difference is $(a + d - 1) - (b + d) = a - b - 1$.

In both cases, the difference $(a - b)$ changes by exactly $\pm 1$. Since we can choose any positive integer $d$ for each operation, we have full control over the direction of the change. If the current difference is $k$, we can apply an operation to change the difference to $k+1$ or $k-1$. 

By repeatedly applying these operations, we can reduce the absolute difference $|a - b|$ until it becomes $0$. Since we can always reach a state where $a - b = 0$, the answer for any two integers $a$ and $b$ is always **YES**.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a constant number of operations (printing "YES"). For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let the current values be a and b.
 * Operation 1: a' = a + d, b' = b + d - 1
 * Change in difference (a - b): (a + d) - (b + d - 1) = a - b + 1
 * Operation 2: a' = a + d - 1, b' = b + d
 * Change in difference (a - b): (a + d - 1) - (b + d) = a - b - 1
 * 
 * In both operations, the difference (a - b) changes by either +1 or -1.
 * Since we can choose any positive integer d, we can always change the 
 * difference (a - b) by 1 in either direction.
 * 
 * If we start with any two integers a and b, we can reach a state where 
 * a = b because we can always reduce the absolute difference |a - b| 
 * by 1 in each step until it becomes 0.
 * 
 * Therefore, it is always possible to make a = b for any positive integers a and b.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        // As derived, it is always possible to make a == b.
        cout << "YES" << "\n";
    }

    return 0;
}
```