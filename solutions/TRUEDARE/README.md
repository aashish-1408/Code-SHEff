# [Truth and Dare (TRUEDARE)](https://www.codechef.com/problems/TRUEDARE)

- **Difficulty Rating**: 1231
- **Solved in**: 1 attempt(s)

## Problem Summary
Ram and Shyam are playing a game of Truth and Dare. Ram has a list of truth tasks he can perform and a list of dare tasks he can perform. Shyam challenges Ram by providing a list of truth tasks and a list of dare tasks that Ram *must* be able to perform. Ram wins the game if and only if he possesses every single truth task Shyam asks for **and** every single dare task Shyam asks for. Otherwise, Shyam wins.

## Intuition & Mathematical Observation
The problem asks us to verify if two sets are subsets of two other sets:
1. Let $T_R$ be the set of truth tasks Ram can perform and $D_R$ be the set of dare tasks Ram can perform.
2. Let $T_S$ be the set of truth tasks Shyam demands and $D_S$ be the set of dare tasks Shyam demands.

Ram wins if and only if:
- $T_S \subseteq T_R$
- $D_S \subseteq D_R$

Since the constraints are small (up to 100 elements per list), we can store Ram's tasks in a `std::set` or a boolean array for $O(1)$ or $O(\log N)$ lookup. We then iterate through Shyam's lists and check if every element exists in Ram's corresponding set. If any element is missing, Ram loses immediately.

## Complexity Analysis
- **Time Complexity**: $O(T_R \log T_R + D_R \log D_R + T_S \log T_R + D_S \log D_R)$, where $T$ and $D$ are the number of tasks. Given the constraints, this is effectively $O(N \log N)$ per test case, which easily passes within the time limit.
- **Space Complexity**: $O(T_R + D_R)$ to store Ram's tasks in sets.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Ram wins if and only if every truth task Shyam asks is present in Ram's truth tasks
 * AND every dare task Shyam asks is present in Ram's dare tasks.
 * 
 * Since the constraints are small (up to 100), we can use a boolean array or 
 * a set to store Ram's tasks and check if all of Shyam's tasks exist in those sets.
 */

void solve() {
    int tr;
    cin >> tr;
    set<int> ram_truth;
    for (int i = 0; i < tr; ++i) {
        int val; cin >> val;
        ram_truth.insert(val);
    }

    int dr;
    cin >> dr;
    set<int> ram_dare;
    for (int i = 0; i < dr; ++i) {
        int val; cin >> val;
        ram_dare.insert(val);
    }

    int ts;
    cin >> ts;
    vector<int> ts_tasks(ts);
    for (int i = 0; i < ts; ++i) cin >> ts_tasks[i];

    int ds;
    cin >> ds;
    vector<int> ds_tasks(ds);
    for (int i = 0; i < ds; ++i) cin >> ds_tasks[i];

    bool ram_wins = true;

    // Check if all of Shyam's truth tasks are in Ram's truth tasks
    for (int task : ts_tasks) {
        if (ram_truth.find(task) == ram_truth.end()) {
            ram_wins = false;
            break;
        }
    }

    // Check if all of Shyam's dare tasks are in Ram's dare tasks
    if (ram_wins) {
        for (int task : ds_tasks) {
            if (ram_dare.find(task) == ram_dare.end()) {
                ram_wins = false;
                break;
            }
        }
    }

    if (ram_wins) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
    }
}

int main() {
    // Fast I/O
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