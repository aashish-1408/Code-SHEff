# [Equal Strings (EQUALSTRING)](https://www.codechef.com/problems/EQUALSTRING)

- **Difficulty Rating**: 1092
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two strings $A$ and $B$ of length $N$, we want to transform $A$ into $B$. In one operation, we can choose a character $\alpha$ and a subsequence of indices, and change the characters at those indices in $A$ to $\alpha$. We need to find the minimum number of operations required to make $A$ equal to $B$.

## Intuition & Mathematical Observation
1. **Ignore Matching Positions**: If $A[i] == B[i]$, the character is already correct, so we do not need to perform any operations on this index.
2. **Focus on Mismatches**: For all indices $i$ where $A[i] \neq B[i]$, we must change $A[i]$ to $B[i]$.
3. **Grouping Operations**: The key observation is that an operation allows us to change *any* subsequence of indices to a specific character. This means if we have multiple positions where $B[i]$ is the same character (e.g., 'c'), we can change all those positions to 'c' in a single operation, regardless of what the original characters in $A$ were.
4. **Conclusion**: The minimum number of operations is simply the count of **unique** characters present in $B$ at all indices $i$ where $A[i] \neq B[i]$. We can track these unique characters using a boolean array or a set.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the strings, as we iterate through the strings exactly once.
- **Space Complexity**: $O(1)$ auxiliary space, as we only use a boolean array of size 26 to track the unique characters encountered.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to transform string A into string B using the minimum number of operations.
 * An operation allows us to pick a subsequence of indices and change all characters at 
 * those indices to a specific character alpha.
 * 
 * If A[i] == B[i], we don't need to do anything for that index.
 * If A[i] != B[i], we must eventually change A[i] to B[i].
 * 
 * Consider all indices i where A[i] != B[i]. Let the set of target characters 
 * required at these positions be {B[i] | A[i] != B[i]}.
 * If we have multiple positions that need to be changed to the same character 'x', 
 * we can change all of them in a single operation.
 * 
 * Therefore, the minimum number of operations is equal to the number of unique 
 * characters in string B at positions where A[i] != B[i].
 */

void solve() {
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;

    // Use a boolean array to track which characters we need to "paint"
    // onto the string A to match B.
    bool needed[26] = {false};
    int operations = 0;

    for (int i = 0; i < N; ++i) {
        if (A[i] != B[i]) {
            int char_idx = B[i] - 'a';
            // If we haven't counted this target character yet, increment operations
            if (!needed[char_idx]) {
                needed[char_idx] = true;
                operations++;
            }
        }
    }

    cout << operations << "\n";
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