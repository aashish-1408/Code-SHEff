# [Chef-Detective (CHEFDETE)](https://www.codechef.com/problems/CHEFDETE)

- **Difficulty Rating**: 1253
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ members in a reporting hierarchy. Each member $i$ reports to a supervisor $R_i$. A member is considered a "potential killer" if no one reports to them. Given the list of reports, we need to identify all such members who are not present in the list of supervisors.

## Intuition & Mathematical Observation
The problem asks us to find all integers $j \in \{1, 2, \dots, N\}$ such that $j$ does not appear in the input array $R$. 

1. **Reporting Chain**: If a member $i$ reports to $R_i$, then $R_i$ is "reported to."
2. **The Don**: The problem states that the Don reports to 0. Since 0 is not a valid member index (members are indexed 1 to $N$), we can ignore the 0s when marking members who have been reported to.
3. **Frequency Tracking**: We can use a boolean array (or a frequency array) of size $N+1$ to keep track of which members have been reported to. By iterating through the input once and marking `is_reported[R_i] = true`, we can identify all members who have at least one subordinate.
4. **Final Check**: Any index $i$ from $1$ to $N$ that remains `false` in our tracking array is a potential killer.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of members. We perform one pass to read the input and mark the array, and a second pass to print the results.
- **Space Complexity**: $O(N)$ to store the `is_reported` boolean array of size $N+1$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N members. Each member i reports to Ri.
 * A potential killer is defined as a member who nobody reports to.
 * This means we need to find all indices j (1 <= j <= N) such that 
 * there is no i where Ri == j.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    // is_reported[i] will be true if someone reports to member i
    // Using vector<bool> for space efficiency
    vector<bool> is_reported(N + 1, false);

    for (int i = 0; i < N; ++i) {
        int r;
        cin >> r;
        // If r is 0, it's the Don; we only care about marking members 
        // who have someone reporting to them (1 to N).
        if (r >= 1 && r <= N) {
            is_reported[r] = true;
        }
    }

    // Collect and print all indices that were never reported to
    bool first = true;
    for (int i = 1; i <= N; ++i) {
        if (!is_reported[i]) {
            if (!first) {
                cout << " ";
            }
            cout << i;
            first = false;
        }
    }
    cout << "\n";

    return 0;
}
```