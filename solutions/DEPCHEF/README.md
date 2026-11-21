# [Deputy Chef (DEPCHEF)](https://www.codechef.com/problems/DEPCHEF)

- **Difficulty Rating**: 1397
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ soldiers arranged in a circle. Each soldier $i$ has an attack value $a_i$ and a defense value $d_i$. A soldier $i$ is attacked by their immediate neighbors (the soldier to their left and the soldier to their right). A soldier survives if their defense value $d_i$ is strictly greater than the sum of the attack values of the neighbors who choose to attack them. Since neighbors can choose to attack or not, the worst-case scenario for soldier $i$ is that **both** neighbors attack. We need to find the maximum defense value $d_i$ among all soldiers who can survive this worst-case scenario. If no soldier survives, output -1.

## Intuition & Mathematical Observation
The problem states that a soldier $i$ survives if $d_i > (\text{sum of attacking neighbors})$. To guarantee survival regardless of the neighbors' choices, we must consider the case where both neighbors attack. 

For a soldier at index $i$ (using 0-based indexing):
- The left neighbor is at index $(i - 1 + N) \pmod N$.
- The right neighbor is at index $(i + 1) \pmod N$.

The condition for survival is:
$$d_i > a_{(i-1+N)\%N} + a_{(i+1)\%N}$$

We iterate through all soldiers, check this condition, and keep track of the maximum $d_i$ that satisfies the inequality. If the condition is never met, we return -1.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we perform a single linear pass through the array of soldiers to evaluate the condition for each.
- **Space Complexity**: $O(N)$ to store the attack and defense values for the $N$ soldiers.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For a soldier i, the neighbors are (i-1) and (i+1).
 * Note: Indices are 0-based. For soldier i, the left neighbor is (i-1+N)%N
 * and the right neighbor is (i+1)%N.
 * 
 * A soldier i survives if their defense d[i] is strictly greater than the sum of 
 * the attack values of both neighbors.
 * 
 * We need to find the maximum d[i] among all soldiers who satisfy this condition.
 * If no soldier satisfies this, output -1.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> a(N), d(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> d[i];

    int max_defense = -1;

    for (int i = 0; i < N; ++i) {
        // Left neighbor index: (i - 1 + N) % N
        // Right neighbor index: (i + 1) % N
        int left = (i - 1 + N) % N;
        int right = (i + 1) % N;

        // Condition: d[i] > a[left] + a[right]
        if (d[i] > (a[left] + a[right])) {
            if (d[i] > max_defense) {
                max_defense = d[i];
            }
        }
    }

    cout << max_defense << "\n";
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