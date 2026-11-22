# [False Number (FALSNUM)](https://www.codechef.com/problems/FALSNUM)

- **Difficulty Rating**: 1286
- **Solved in**: 2 attempt(s)

## Problem Summary
Given a string $A$ representing a number, we need to find the smallest number $W$ such that removing exactly one digit from $W$ results in $A$. Since there are multiple possible values for $W$, we must choose the one that is the smallest.

## Intuition & Mathematical Observation
To make $W$ as small as possible, we want to insert a digit at the earliest possible position. Let the given string be $A = a_0a_1a_2...a_n$.

1. **Case 1: $A[0] > '1'$**
   If the first digit is greater than '1', we can prepend '1' to the string. This results in $W = 1A$. Since $1 < A[0]$, this is the smallest possible way to form a number that reduces to $A$ by removing the first digit.

2. **Case 2: $A[0] == '1'$**
   If the first digit is '1', we cannot prepend '1' because that would result in a larger number than inserting '0' later. We want to insert '0' as early as possible to keep the number small.
   - We iterate through the string starting from the second digit (index 1).
   - The first time we encounter a digit $A[i] > '0'$, we insert '0' immediately before it. This ensures the resulting number is as small as possible.
   - If all digits after the first are '0' (e.g., $A = "1000"$), we append '0' to the end to satisfy the condition.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of digits in $A$. We perform a single pass through the string to find the insertion point and string concatenation takes linear time.
- **Space Complexity**: $O(N)$ to store the input string and the resulting output string.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * We want to find the smallest W such that removing one digit from W yields A.
 * 
 * Strategy:
 * 1. If A[0] > '1', prepending '1' gives the smallest W.
 * 2. If A[0] == '1', we insert '0' after the first digit to keep the number 
 *    as small as possible.
 */

void solve() {
    string A;
    cin >> A;

    if (A[0] > '1') {
        // Prepend '1' to make the smallest possible number
        cout << '1' << A << "\n";
    } else {
        // A[0] is '1'. We need to insert '0' at the first position i where A[i] > '0'.
        // If no such i exists (e.g., 1000), we insert '0' at the end.
        bool inserted = false;
        for (int i = 1; i < A.length(); ++i) {
            if (A[i] > '0') {
                cout << A.substr(0, i) << '0' << A.substr(i) << "\n";
                inserted = true;
                break;
            }
        }
        if (!inserted) {
            cout << A << '0' << "\n";
        }
    }
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