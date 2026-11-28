# [Easy Speaking (EZSPK)](https://www.codechef.com/problems/EZSPK)

- **Difficulty Rating**: 708
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine if a given string is "hard to pronounce." A string is considered hard to pronounce if it contains at least 4 consecutive consonants. Given a string of length $N$ consisting of lowercase English letters, we need to output "Yes" if it is hard to pronounce, and "No" otherwise.

## Intuition & Mathematical Observation
The problem can be solved using a simple linear scan (greedy approach):
1. **Identify Consonants**: A character is a consonant if it is not one of the vowels: `a`, `e`, `i`, `o`, or `u`.
2. **Track Consecutive Count**: We maintain a counter `consecutive_consonants` that increments whenever we encounter a consonant.
3. **Reset Condition**: If we encounter a vowel, the sequence of consecutive consonants is broken, so we reset the counter to 0.
4. **Termination**: If the counter reaches 4 at any point during the iteration, we immediately flag the string as "hard" and stop processing to save time.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string exactly once.
- **Space Complexity**: $O(N)$ to store the input string (or $O(1)$ if we process the string character by character).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Easy Speaking
 * Logic: Iterate through the string and maintain a counter of consecutive consonants.
 * If the counter reaches 4, the word is hard to pronounce.
 * Reset the counter to 0 whenever a vowel is encountered.
 */

bool is_consonant(char c) {
    return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int consecutive_consonants = 0;
    bool hard = false;

    for (int i = 0; i < n; ++i) {
        if (is_consonant(s[i])) {
            consecutive_consonants++;
            if (consecutive_consonants >= 4) {
                hard = true;
                break;
            }
        } else {
            consecutive_consonants = 0;
        }
    }

    if (hard) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
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