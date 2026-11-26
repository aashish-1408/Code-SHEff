# [Counting Characters (COUNTAB)](https://www.codechef.com/problems/COUNTAB)

- **Difficulty Rating**: 541
- **Solved in**: 2 attempt(s)

## Problem Summary
Given a string $S$ of length $N$ consisting only of characters 'a' and 'b', the task is to count the total number of occurrences of 'a' and 'b' in the string and print them separated by a space.

## Intuition & Mathematical Observation
The problem is a straightforward frequency counting task. Since the string only contains two types of characters, we can iterate through the string once and maintain two separate counters:
1. `count_a`: Incremented whenever the current character is 'a'.
2. `count_b`: Incremented whenever the current character is 'b'.

Given the constraints ($N \le 10$ and $T \le 10^4$), a simple linear scan $O(N)$ per test case is well within the time limits.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. For $T$ test cases, the total time complexity is $O(T \times N)$.
- **Space Complexity**: $O(N)$ to store the input string, or $O(1)$ if processing character by character.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem: COUNTAB
 * Complexity: O(N) per test case, O(T*N) total.
 * Given N <= 10 and T <= 10^4, this is highly efficient.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    int count_a = 0;
    int count_b = 0;

    // Iterate through the string and count occurrences
    for (char c : s) {
        if (c == 'a') {
            count_a++;
        } else if (c == 'b') {
            count_b++;
        }
    }

    cout << count_a << " " << count_b << "\n";
}

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
```