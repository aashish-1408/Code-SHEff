# [Three Powers of Two (THREEPOW2)](https://www.codechef.com/problems/THREEPOW2)

- **Difficulty Rating**: 1253
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ representing a positive integer $X$, determine if $X$ can be expressed as the sum of exactly three non-negative powers of two (i.e., $X = 2^a + 2^b + 2^c$ where $a, b, c \ge 0$).

## Intuition & Mathematical Observation
The problem asks us to represent a number $X$ as a sum of exactly three powers of two. Let $k$ be the number of set bits (1s) in the binary representation of $X$.

1.  **If $k > 3$**: It is impossible to represent $X$ as a sum of only three powers of two. Each power of two contributes exactly one bit to the binary representation, and while some powers can be combined (e.g., $2^n + 2^n = 2^{n+1}$), you can never reduce the number of set bits below the count required by the binary representation without increasing the total count of terms. Thus, $k > 3$ is always **NO**.
2.  **If $k = 3$**: The number is already a sum of three powers of two. Thus, always **YES**.
3.  **If $k = 2$**: Let $X = 2^a + 2^b$ (where $a > b$). We can rewrite $2^a$ as $2^{a-1} + 2^{a-1}$. Thus, $X = 2^{a-1} + 2^{a-1} + 2^b$. This is a sum of three powers of two. This is valid as long as $a \ge 1$. Since the string has no leading zeros and $k=2$, the highest bit position $a$ must be at least 1. Thus, always **YES**.
4.  **If $k = 1$**: Let $X = 2^a$. We need $2^a = 2^x + 2^y + 2^z$.
    *   If $a=0$ ($X=1$): $1 = 2^x + 2^y + 2^z$ is impossible for non-negative integers.
    *   If $a=1$ ($X=2$): $2 = 2^x + 2^y + 2^z$ is impossible.
    *   If $a=2$ ($X=4$): $4 = 2^1 + 2^1 = 2^1 + 2^0 + 2^0$. This works.
    *   Generally, for $a \ge 2$, we can always decompose $2^a$ into three powers. Thus, **YES** if $a \ge 2$, else **NO**.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the binary string, as we iterate through the string once to count the set bits.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We count the number of set bits 'k' in the binary string.
 * - k > 3: Impossible.
 * - k = 3: Already 3 powers.
 * - k = 2: Can split 2^a into 2^{a-1} + 2^{a-1} (if a >= 1).
 * - k = 1: Can split 2^a into 2^{a-1} + 2^{a-2} + 2^{a-2} (if a >= 2).
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int k = 0;
    for (char c : S) {
        if (c == '1') k++;
    }

    if (k == 1) {
        // X = 2^a. The power 'a' is (N-1) because the string is 0-indexed.
        if (N - 1 >= 2) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    } else if (k == 2) {
        // Always possible to split the highest bit.
        cout << "YES" << "\n";
    } else if (k == 3) {
        // Already 3 powers.
        cout << "YES" << "\n";
    } else {
        // More than 3 bits cannot be reduced to 3 powers.
        cout << "NO" << "\n";
    }
}

int main() {
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