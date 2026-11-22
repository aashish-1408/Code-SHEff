# [Exun Handshake (EXSHAKE)](https://www.codechef.com/problems/EXSHAKE)

- **Difficulty Rating**: 815
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ groups, each with a specific number of people $A_i$. We want to select a subset of these groups such that the total number of handshakes among all people in the selected groups does not exceed $M$. The number of handshakes for $P$ people is calculated as $\frac{P(P-1)}{2}$. The goal is to maximize the number of groups selected.

## Intuition & Mathematical Observation
To maximize the number of groups selected, we should prioritize picking the groups with the smallest number of people first. This is a classic **Greedy Approach**:

1. **Sorting**: By sorting the array $A$ in non-decreasing order, we ensure that we add the smallest possible increments to our total population count $P$.
2. **Greedy Selection**: We iterate through the sorted list and maintain a running total of people ($P$). For each group, we check if adding its members would result in a total handshake count $\le M$.
3. **Termination**: If adding the current group causes the handshake count to exceed $M$, we stop, as adding any subsequent (larger) groups would also violate the condition.

The formula for handshakes is $\frac{P(P-1)}{2}$. Since $N$ and $A_i$ are small ($N, A_i \le 100$), the maximum possible $P$ is $10,000$. The resulting handshake count is approximately $5 \times 10^7$, which fits comfortably within a standard `long long` (and even a 32-bit `int`).

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent iteration through the array takes $O(N)$, making the overall complexity dominated by the sort.
- **Space Complexity**: $O(N)$ to store the group sizes in a vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N groups with sizes A_1, A_2, ..., A_N.
 * If we invite a subset of groups with total people P, the number of handshakes is P*(P-1)/2.
 * We want to maximize the number of groups invited such that P*(P-1)/2 <= M.
 */

void solve() {
    int N;
    long long M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort groups to pick the smallest ones first to maximize the count
    sort(A.begin(), A.end());

    long long current_people = 0;
    int count = 0;

    for (int i = 0; i < N; ++i) {
        long long next_people = current_people + A[i];
        long long handshakes = (next_people * (next_people - 1)) / 2;

        if (handshakes <= M) {
            current_people = next_people;
            count++;
        } else {
            // Since groups are sorted, if adding this group exceeds M, 
            // adding any larger group will also exceed M.
            break;
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