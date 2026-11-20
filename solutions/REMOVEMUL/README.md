# [Remove Multiples (REMOVEMUL)](https://www.codechef.com/problems/REMOVEMUL)

- **Difficulty Rating**: 1315
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a set $S = \{1, 2, \dots, N\}$. We are also given a subset $Q \subseteq S$ that must remain in the set after performing a series of operations. In one operation, we can choose an integer $k$ and remove the smallest multiple of $k$ currently present in $S$. The cost of this operation is $k$. We want to remove all elements in $S \setminus Q$ such that the total cost of the operations is maximized.

## Intuition & Mathematical Observation
The core of the problem lies in determining the maximum cost to remove all elements that are not in $Q$. 

1. **The Operation**: When we choose a value $k$ to remove the smallest multiple of $k$ currently in $S$, the cost incurred is $k$.
2. **Strategy**: To maximize the total cost, we want to remove each element $x \in S \setminus Q$ by choosing $k = x$. 
3. **Feasibility**: Can we always remove every $x \in S \setminus Q$ by choosing $k = x$? Yes. If we choose $k = x$, the smallest multiple of $x$ currently in $S$ is $x$ itself (provided no smaller multiple of $x$ has been removed yet). By carefully ordering our removals, we can ensure that for every $x \in S \setminus Q$, we perform an operation with $k = x$.
4. **Conclusion**: Since we must remove every element in $S \setminus Q$, and the most efficient way to "spend" the removal of an element $x$ is to assign it a cost of $x$, the maximum total cost is simply the sum of all elements in $S$ that are not in $Q$.

Mathematically, the total cost is:
$$\text{Total Cost} = \sum_{x \in S \setminus Q} x = \left( \sum_{i=1}^{N} i \right) - \left( \sum_{q \in Q} q \right)$$
Using the arithmetic series formula, $\sum_{i=1}^{N} i = \frac{N(N+1)}{2}$.

## Complexity Analysis
- **Time Complexity**: $O(M)$ per test case, where $M$ is the number of elements in $Q$. We iterate through the input array once to calculate the sum of $Q$.
- **Space Complexity**: $O(1)$, as we only need to store the running sum of the elements in $Q$ and the total sum of $1 \dots N$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with S = {1, 2, ..., N} and want to reach Q.
 * The operation allows us to remove the smallest multiple of k currently in S with cost k.
 * 
 * Any element x in {1, ..., N} \ Q must be removed.
 * By choosing k = x for every x not in Q, we maximize the cost.
 * The total cost is the sum of all x such that x is in {1, ..., N} but not in Q.
 */

void solve() {
    long long N;
    int M;
    if (!(cin >> N >> M)) return;
    
    // Sum of all integers from 1 to N
    long long sum_all = N * (N + 1) / 2;
    long long sum_q = 0;
    
    // Subtract the sum of elements that must remain in the set
    for (int i = 0; i < M; ++i) {
        long long val;
        cin >> val;
        sum_q += val;
    }
    
    cout << (sum_all - sum_q) << "\n";
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```