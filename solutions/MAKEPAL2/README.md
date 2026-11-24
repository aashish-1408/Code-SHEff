# [Make Palindrome 2 (MAKEPAL2)](https://www.codechef.com/problems/MAKEPAL2)

- **Difficulty Rating**: 1393
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$, we are allowed to perform at most $\lfloor N/2 \rfloor$ deletions. The goal is to transform the string into a palindrome by deleting characters. We need to output any such valid palindrome.

## Intuition & Mathematical Observation
The problem asks us to obtain a palindrome by deleting at most half of the characters. A key property of binary strings is that they consist only of '0's and '1's. 

1. **Majority Rule**: In any binary string, either the count of '0's is greater than or equal to the count of '1's, or vice versa.
2. **Palindrome Property**: A string consisting entirely of the same character (e.g., "000" or "1111") is always a palindrome.
3. **Constraint Satisfaction**: Let $count_0$ be the number of '0's and $count_1$ be the number of '1's. 
   - If $count_0 \ge count_1$, we can delete all $count_1$ characters. Since $count_1 \le count_0$, it follows that $count_1 \le N/2$. This satisfies the deletion constraint.
   - If $count_1 > count_0$, we can delete all $count_0$ characters. Since $count_0 < count_1$, it follows that $count_0 < N/2$. This also satisfies the deletion constraint.

By simply keeping the majority character and deleting all instances of the minority character, we are guaranteed to form a palindrome while staying within the allowed number of deletions.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string once to count the characters and once more to print the result.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a binary string S of length N. We can perform at most floor(N/2) deletions.
 * We need to obtain a palindrome.
 * 
 * Key Observation:
 * A binary string must contain more 0s than 1s, or more 1s than 0s, or equal amounts.
 * If we count the number of '0's and '1's in the string, we can simply keep all 
 * characters of the majority character. 
 * 
 * Let count0 be the number of '0's and count1 be the number of '1's.
 * If count0 >= count1, we can delete all '1's. The resulting string will be a 
 * sequence of '0's, which is a palindrome.
 * The number of deletions would be count1. Since count1 <= N/2 (because count0 + count1 = N 
 * and count0 >= count1), this satisfies the constraint of at most floor(N/2) deletions.
 * Similarly, if count1 > count0, we delete all '0's. The number of deletions is count0,
 * which is <= N/2.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int count0 = 0;
    int count1 = 0;
    for (char c : S) {
        if (c == '0') count0++;
        else count1++;
    }

    if (count0 >= count1) {
        // Keep only '0's
        for (int i = 0; i < count0; ++i) {
            cout << '0';
        }
        cout << "\n";
    } else {
        // Keep only '1's
        for (int i = 0; i < count1; ++i) {
            cout << '1';
        }
        cout << "\n";
    }
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