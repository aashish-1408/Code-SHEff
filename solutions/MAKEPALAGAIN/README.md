# [Yet Another Palindrome Making Problem (MAKEPALAGAIN)](https://www.codechef.com/problems/MAKEPALAGAIN)

- **Difficulty Rating**: 1328
- **Solved in**: 3 attempt(s)

## Problem Summary
Given a string $S$ of even length $N$, we are allowed to perform an operation where we swap $S[i]$ and $S[i+2]$ any number of times. We need to determine if it is possible to rearrange the string into a palindrome using these operations.

## Intuition & Mathematical Observation
The key observation lies in the nature of the allowed operation:
1. **Independent Sets**: Swapping $S[i]$ and $S[i+2]$ means that all characters at even indices ($0, 2, 4, \dots$) can be permuted among themselves, and all characters at odd indices ($1, 3, 5, \dots$) can be permuted among themselves.
2. **Palindrome Constraint**: For a string of length $N$ to be a palindrome, the character at index $i$ must equal the character at index $N-1-i$.
3. **Parity Mapping**: Since $N$ is even, if $i$ is even, then $N-1-i$ is odd. Conversely, if $i$ is odd, $N-1-i$ is even.
4. **Conclusion**: Because we can rearrange all even-indexed characters and all odd-indexed characters independently, the string can form a palindrome if and only if the **multiset of characters at even positions is identical to the multiset of characters at odd positions**. If these two multisets match, we can arrange the even-indexed characters to match the required odd-indexed characters at their mirrored positions, and vice versa.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string once to count character frequencies and then perform a constant-time check (26 iterations) on the frequency arrays.
- **Space Complexity**: $O(1)$, as we only use two fixed-size arrays of size 26 to store character counts, regardless of the input size.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Problem Analysis:
 * The operation allows swapping A[i] and A[i+2].
 * This means all characters at even indices can be rearranged, 
 * and all characters at odd indices can be rearranged.
 * 
 * For the string to be a palindrome, A[i] must equal A[N-1-i].
 * Since N is even, if i is even, N-1-i is odd. 
 * This implies the multiset of characters at even positions 
 * must be identical to the multiset of characters at odd positions.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    string S;
    cin >> S;

    int even_counts[26] = {0};
    int odd_counts[26] = {0};

    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            even_counts[S[i] - 'a']++;
        } else {
            odd_counts[S[i] - 'a']++;
        }
    }

    bool possible = true;
    for (int i = 0; i < 26; ++i) {
        if (even_counts[i] != odd_counts[i]) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Optimize I/O operations
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