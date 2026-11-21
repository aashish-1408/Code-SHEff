# [Distinct Palindrome (DISPAL)](https://www.codechef.com/problems/DISPAL)

- **Difficulty Rating**: 1304
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $N$ and $X$, construct a palindrome of length $N$ that contains exactly $X$ distinct characters. If it is impossible to construct such a palindrome, output `-1`.

## Intuition & Mathematical Observation
1. **Palindrome Property**: A palindrome of length $N$ is uniquely determined by its first $K = \lceil N/2 \rceil$ characters. Once these $K$ characters are chosen, the remaining characters are fixed by mirroring.
2. **Constraint on $X$**:
   - Since we only have $K$ positions to fill to determine the entire string, we cannot have more than $K$ distinct characters. Therefore, if $X > K$, it is impossible to satisfy the condition, and we output `-1`.
   - Additionally, since we are limited to the English alphabet, $X$ cannot exceed 26. However, the problem constraints imply $X \le K$, which naturally handles the alphabet limit for valid cases.
3. **Construction Strategy**:
   - To use exactly $X$ distinct characters, we fill the first $X-1$ positions of the first half with the first $X-1$ letters of the alphabet ('a', 'b', 'c', ...).
   - We fill the remaining $K - (X - 1)$ positions of the first half with the $X$-th character ('a' + $X - 1$).
   - This ensures that exactly $X$ distinct characters are used in the first $K$ positions, which are then mirrored to complete the palindrome.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the string of length $N$ to fill and mirror the characters.
- **Space Complexity**: $O(N)$ to store the resulting string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct a palindrome of length N with exactly X distinct characters.
 * A palindrome is determined by its first ceil(N/2) characters.
 * Let K = ceil(N/2). We need to use exactly X distinct characters in these K positions.
 * 
 * Constraints:
 * 1. We need at least X distinct characters, so K >= X.
 * 2. We can use at most 26 distinct characters.
 * 3. If K < X, it is impossible, output -1.
 */

void solve() {
    int N, X;
    cin >> N >> X;

    int K = (N + 1) / 2;

    // If we need more distinct characters than available positions, it's impossible
    if (X > K) {
        cout << -1 << "\n";
        return;
    }

    string s(N, ' ');
    // Fill the first K positions
    // Use characters 'a' to 'a' + X - 1
    for (int i = 0; i < K; ++i) {
        if (i < X - 1) {
            s[i] = (char)('a' + i);
        } else {
            s[i] = (char)('a' + X - 1);
        }
    }

    // Mirror to the second half
    for (int i = 0; i < N / 2; ++i) {
        s[N - 1 - i] = s[i];
    }

    cout << s << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```