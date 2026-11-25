# [Recover Palindrome (P2235)](https://www.codechef.com/problems/P2235)

- **Difficulty Rating**: 825
- **Solved in**: 2 attempt(s)

## Problem Summary
Given a string $S$ of length $N$ containing lowercase English letters and '?' characters, determine if there is exactly one way to replace all '?' characters such that the resulting string is a palindrome.

## Intuition & Mathematical Observation
A string is a palindrome if $S[i] = S[N - 1 - i]$ for all $0 \le i < N$. To ensure the resulting palindrome is unique, every position must be constrained to exactly one possible character.

1.  **Pairs $(i, N-1-i)$ where $i \neq N-1-i$**:
    *   If both $S[i]$ and $S[N-1-i]$ are '?', we have 26 possible choices for the pair (e.g., 'aa', 'bb', ...), meaning the palindrome is not unique.
    *   If one is '?' and the other is a character, the '?' is forced to match the existing character.
    *   If both are characters, they are already fixed.
2.  **Middle element (if $N$ is odd, $i = N/2$)**:
    *   If $S[i]$ is '?', it can be any of the 26 letters, meaning the palindrome is not unique.
    *   If $S[i]$ is a character, it is already fixed.

**Conclusion**: The palindrome is unique if and only if there are no "free" '?' characters. Specifically, we must not have a middle '?' (in odd-length strings) and we must not have a pair of '?' at symmetric positions.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the string once up to the middle index.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * A palindrome P of length N satisfies P[i] = P[N - 1 - i] for all 0 <= i < N.
 * 
 * To uniquely reconstruct the palindrome:
 * 1. For any pair (i, N - 1 - i) where i != N - 1 - i:
 *    - If both S[i] and S[N - 1 - i] are '?', we have 26 choices (a-z). Not unique.
 *    - If one is '?' and the other is a character, the '?' is forced.
 *    - If both are characters, they are already fixed.
 * 2. For the middle element (if N is odd, i = N/2):
 *    - If S[i] is '?', we have 26 choices (a-z). Not unique.
 *    - If S[i] is a character, it is fixed.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    string S;
    cin >> S;

    bool unique = true;
    
    // Check pairs (i, N-1-i)
    for (int i = 0; i < (N + 1) / 2; ++i) {
        int j = N - 1 - i;
        
        if (i == j) {
            // Middle element of odd length string
            if (S[i] == '?') {
                unique = false;
            }
        } else {
            // Pair of indices
            if (S[i] == '?' && S[j] == '?') {
                // Both are '?', can be any of 26 letters
                unique = false;
            }
        }
    }

    if (unique) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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