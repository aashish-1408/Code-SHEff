# [Distinct Characters Subsequence (DISCHAR)](https://www.codechef.com/problems/DISCHAR)

- **Difficulty Rating**: 1314
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$, we need to find the length of the longest subsequence that consists of only distinct characters. A subsequence is derived by deleting zero or more characters from the original string without changing the relative order of the remaining characters.

## Intuition & Mathematical Observation
To form a subsequence with distinct characters, we can pick at most one instance of every character present in the string. 

If a character appears multiple times in the string, we can only include it once in our subsequence to satisfy the "distinct" requirement. Since the order of characters in a subsequence must match their relative order in the original string, we can simply pick the first occurrence of every unique character found in the string. 

Therefore, the problem reduces to **counting the number of unique characters** present in the given string. For example, in the string `"aba"`, the unique characters are `'a'` and `'b'`, so the answer is 2.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string exactly once.
- **Space Complexity**: $O(1)$. We use a boolean array of fixed size 26 to track the occurrence of characters, which is constant space regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the size of the largest subsequence with distinct characters.
 * Since a subsequence maintains the relative order of characters, if we have 
 * multiple occurrences of the same character, we can only pick one of them 
 * to be in our subsequence if we want all characters to be distinct.
 * 
 * Therefore, the largest subsequence with distinct characters is simply the 
 * count of unique characters present in the string.
 */

void solve() {
    string s;
    cin >> s;
    
    // Use a boolean array to track which characters have appeared
    // Since the problem typically involves lowercase English letters
    bool seen[26] = {false};
    int distinct_count = 0;
    
    for (char c : s) {
        if (!seen[c - 'a']) {
            seen[c - 'a'] = true;
            distinct_count++;
        }
    }
    
    cout << distinct_count << "\n";
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