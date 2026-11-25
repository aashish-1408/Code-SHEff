# [Split the Str Ing (SPLITIT)](https://www.codechef.com/problems/SPLITIT)

- **Difficulty Rating**: 1251
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$ of length $N$, determine if it is possible to split $S$ into two non-empty strings $A$ and $B$ such that $S = A + B$ and $B$ is a substring of $A$.

## Intuition & Mathematical Observation
To satisfy the condition that $B$ is a substring of $A$, we need to find at least one split point. Let the last character of the string be $C = S[N-1]$. 

If we consider the simplest case where $B$ consists only of the last character ($B = S[N-1]$), then $A$ must be the prefix $S[0 \dots N-2]$. For this to be a valid split, the character $S[N-1]$ must exist somewhere within the prefix $S[0 \dots N-2]$.

**Why is this sufficient?**
If $S[N-1]$ exists in the prefix $S[0 \dots N-2]$, we can set $A = S[0 \dots N-2]$ and $B = S[N-1]$. Since $S[N-1]$ is a character present in $A$, $B$ is by definition a substring of $A$.

**What if $S[N-1]$ is not in the prefix?**
If the last character does not appear anywhere in the first $N-1$ characters, then no matter how we choose the split point to form a longer $B$, the last character of $S$ (which is also the last character of $B$) will never be found in $A$. Therefore, if $S[N-1]$ is not present in $S[0 \dots N-2]$, it is impossible to satisfy the condition.

Thus, the problem reduces to checking if the last character of the string appears at least once in the preceding $N-1$ characters.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string at most once to check for the existence of the last character.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The condition "B is a substring of A" is satisfied if the last character 
 * of the string S appears at least once in the prefix S[0...N-2].
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    char last_char = S[N - 1];
    bool found = false;
    
    // Check if the last character exists in the prefix S[0...N-2]
    for (int i = 0; i < N - 1; ++i) {
        if (S[i] == last_char) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
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