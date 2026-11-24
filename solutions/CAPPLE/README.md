# [Chef and Apple Trees (CAPPLE)](https://www.codechef.com/problems/CAPPLE)

- **Difficulty Rating**: 1301
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ apple trees, each with a certain number of apples. In one minute, Chef can choose a subset of trees that all have the same number of apples and reduce their apple count to any value that exists on another tree (or effectively remove them). The goal is to find the minimum number of minutes required to process all trees such that no apples remain (or all trees are reduced to a state where they can be cleared).

## Intuition & Mathematical Observation
The core of the problem lies in the rule: "In one minute, he can pick a subset of trees that have the same number of apples." 

If we have multiple trees with the same number of apples, they can all be processed in a single operation. If we have $K$ distinct values of apple counts present in the orchard, each distinct value represents a group that must be handled independently. Since each operation can only target one specific apple count value at a time, we need exactly one operation for each unique apple count present in the input.

Therefore, the problem simplifies to finding the **number of unique integers** in the given array. Using a `std::set` or sorting the array and counting unique elements provides the answer efficiently.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ or $O(N)$ depending on the implementation. Using a `std::set` takes $O(N \log N)$ due to insertions. If using a hash set (`std::unordered_set`), it would be $O(N)$ on average.
- **Space Complexity**: $O(N)$ to store the distinct apple counts in the set.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each distinct value represents a group that must be processed.
 * If we have multiple trees with the same number of apples, they can all be 
 * processed together in one operation.
 * 
 * The problem reduces to finding the number of distinct values present in the input array.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    // Using a set to store unique apple counts
    set<long long> distinct_apples;
    for (int i = 0; i < n; ++i) {
        long long apples;
        cin >> apples;
        distinct_apples.insert(apples);
    }
    
    // The number of distinct apple counts is the minimum time required.
    cout << distinct_apples.size() << "\n";
}

int main() {
    // Fast I/O setup for performance
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