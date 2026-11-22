# [Plus Multiply (PLMU)](https://www.codechef.com/problems/PLMU)

- **Difficulty Rating**: 1277
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we need to find the number of pairs $(i, j)$ such that $1 \le i < j \le N$ and the condition $A_i + A_j = A_i \times A_j$ holds true.

## Intuition & Mathematical Observation
To solve the equation $A_i + A_j = A_i \times A_j$, we can rearrange the terms:
1. $A_i \times A_j - A_i - A_j = 0$
2. Add $1$ to both sides to factorize: $A_i \times A_j - A_i - A_j + 1 = 1$
3. $(A_i - 1)(A_j - 1) = 1$

Since $A_i$ are integers, the product of two integers being $1$ only happens in two cases:
*   **Case 1:** $(A_i - 1) = 1$ and $(A_j - 1) = 1 \implies A_i = 2$ and $A_j = 2$.
*   **Case 2:** $(A_i - 1) = -1$ and $(A_j - 1) = -1 \implies A_i = 0$ and $A_j = 0$.

Thus, the problem reduces to counting how many $0$s and $2$s are in the array. If there are $c_0$ zeros and $c_2$ twos, the total number of valid pairs is the number of ways to choose 2 items from the set of zeros plus the number of ways to choose 2 items from the set of twos:
$$\text{Total Pairs} = \frac{c_0(c_0 - 1)}{2} + \frac{c_2(c_2 - 1)}{2}$$

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We iterate through the array exactly once to count the occurrences of $0$ and $2$.
- **Space Complexity**: $O(1)$, as we only store the counts of $0$ and $2$ regardless of the input size.

## Solution Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * The equation A_i + A_j = A_i * A_j can be rewritten as:
 * (A_i - 1) * (A_j - 1) = 1
 * 
 * This holds true only if (A_i, A_j) are (0, 0) or (2, 2).
 * We count the occurrences of 0 and 2 and use the combination formula 
 * nC2 = n * (n - 1) / 2 to find the number of pairs.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    long long count0 = 0;
    long long count2 = 0;
    
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val == 0) {
            count0++;
        } else if (val == 2) {
            count2++;
        }
    }
    
    // Calculate pairs using nC2 formula
    long long ans = (count0 * (count0 - 1) / 2) + (count2 * (count2 - 1) / 2);
    cout << ans << "\n";
}

int main() {
    // Optimize I/O operations for faster execution
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