# [Budget Allotment (BUDGET25)](https://www.codechef.com/problems/BUDGET25)

- **Difficulty Rating**: 1258
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ sectors, each with an initial budget $A_i$. We want to maximize the number of sectors that have a budget of at least $X$. We can redistribute the surplus budget from sectors that have more than $X$ to those that have less than $X$. Specifically, if a sector has $A_i > X$, it can contribute $A_i - X$ to the total pool of surplus, which can then be used to increase the budget of other sectors.

## Intuition & Mathematical Observation
1. **Categorization**: First, divide the sectors into two groups:
   - **Surplus Group**: Sectors where $A_i \ge X$. These sectors already satisfy the condition, and their excess ($A_i - X$) is available to help others.
   - **Deficit Group**: Sectors where $A_i < X$. These sectors need $(X - A_i)$ additional budget to satisfy the condition.
2. **Greedy Strategy**: To maximize the total count of sectors meeting the requirement:
   - We start with the count of sectors already in the surplus group.
   - To increase this count, we should prioritize filling the deficits of sectors that require the **least amount of budget**. 
   - By sorting the deficit group in descending order (i.e., from the largest $A_i$ to the smallest), we ensure that we pick the sectors closest to $X$ first. This minimizes the "cost" to flip a sector from "not meeting" to "meeting" the requirement, allowing us to potentially flip more sectors with the available surplus.
3. **Execution**: Calculate the total available surplus. Iterate through the sorted deficit list, subtracting the required amount from the total surplus until we can no longer afford to bring a sector up to $X$.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting of the deficit array. The initial pass and the final iteration through the deficit array take $O(N)$ time.
- **Space Complexity**: $O(N)$ to store the `surplus` and `deficit` vectors.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N sectors with initial budgets A_i. We want to maximize the number of sectors
 * that have at least X. A sector i can give away its surplus (A_i - X) only if 
 * A_i >= X.
 * 
 * Strategy:
 * 1. Identify all sectors that already have >= X. These sectors contribute to the count
 *    and their surplus (A_i - X) can be used to help sectors that have < X.
 * 2. Sort the sectors that have < X in descending order. It is optimal to fill the 
 *    sectors that are closest to X first, because they require the least amount of 
 *    surplus to reach X.
 * 3. Keep track of the total surplus available. Iterate through the sorted sectors 
 *    (those with < X) and if the current surplus is enough to bring the sector to X,
 *    increment the count and subtract the required amount from the surplus.
 */

void solve() {
    int N;
    long long X;
    cin >> N >> X;
    vector<long long> A(N);
    vector<long long> surplus;
    vector<long long> deficit;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] >= X) {
            surplus.push_back(A[i] - X);
        } else {
            deficit.push_back(A[i]);
        }
    }

    // Sort deficits in descending order to fill the ones closest to X first
    sort(deficit.rbegin(), deficit.rend());

    long long total_surplus = 0;
    for (long long s : surplus) {
        total_surplus += s;
    }

    int count = surplus.size();
    for (long long d : deficit) {
        long long needed = X - d;
        if (total_surplus >= needed) {
            total_surplus -= needed;
            count++;
        } else {
            // Cannot fill any more sectors
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