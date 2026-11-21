# [Chef and Secret Ingredients (CHEFING)](https://www.codechef.com/problems/CHEFING)

- **Difficulty Rating**: 1376
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ strings, we need to determine how many unique lowercase English characters appear in **every single one** of the $N$ strings.

## Intuition & Mathematical Observation
Since we are only dealing with lowercase English letters ('a' through 'z'), the search space is extremely small (constant size of 26). 

1. **Intersection of Sets**: We can treat each string as a set of unique characters. The problem asks for the size of the intersection of these $N$ sets.
2. **Boolean Array Approach**: 
   - We maintain a boolean array `common` of size 26, initialized to `true`. This array tracks which characters have appeared in every string processed so far.
   - For each input string, we create a temporary boolean array `present` to mark which characters exist in that specific string.
   - We then perform a logical `AND` operation between `common` and `present`. If a character was previously considered "common" but is not present in the current string, it is removed from the set of common characters.
3. **Final Count**: After processing all $N$ strings, the number of `true` values remaining in the `common` array is our answer.

## Complexity Analysis
- **Time Complexity**: $O(T \times (\sum |S_i| + N \times 26))$, where $T$ is the number of test cases and $|S_i|$ is the length of each string. Since 26 is a constant, this simplifies to $O(\sum |S_i|)$ per test case, which is highly efficient.
- **Space Complexity**: $O(1)$, as we only use fixed-size arrays of length 26 regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Approach:
 * 1. Initialize a boolean array `common` of size 26 to true.
 * 2. For each string, identify the unique characters present.
 * 3. Update `common` by performing a logical AND with the current string's characters.
 * 4. Count the number of true values in `common` at the end.
 */

void solve() {
    int N;
    cin >> N;
    
    // common[i] will be true if the i-th letter of the alphabet 
    // has appeared in every string processed so far.
    vector<bool> common(26, true);
    
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        
        vector<bool> present(26, false);
        for (char c : s) {
            present[c - 'a'] = true;
        }
        
        // Update common array: a character is only "common" if it was 
        // common before AND it is present in the current string.
        for (int j = 0; j < 26; ++j) {
            common[j] = common[j] && present[j];
        }
    }
    
    int result = 0;
    for (int j = 0; j < 26; ++j) {
        if (common[j]) {
            result++;
        }
    }
    
    cout << result << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```