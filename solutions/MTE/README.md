# [Make Them Equal (MTE)](https://www.codechef.com/problems/MTE)

- **Difficulty Rating**: 1348
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an array of $N$ integers, we want to make all elements in the array have the same parity (either all even or all odd). In one operation, we can choose two indices $i$ and $j$ and replace $A[i]$ with $A[i] + A[j]$. We need to find the minimum number of operations required to achieve this state.

## Intuition & Mathematical Observation
The parity of the sum of two numbers follows these rules:
1. `Even + Even = Even`
2. `Odd + Odd = Even`
3. `Odd + Even = Odd`

To make all elements have the same parity, we have two strategies:

### Strategy 1: Make all elements EVEN
*   We can only change the parity of an odd number to even by adding another odd number to it (`Odd + Odd = Even`).
*   If we have `cnt_odd` odd numbers, we can pair them up to create `cnt_odd / 2` even numbers.
*   This strategy is **only possible** if `cnt_odd` is even. If `cnt_odd` is odd, we will always be left with one odd number.

### Strategy 2: Make all elements ODD
*   We can change an even number to odd by adding an odd number to it (`Even + Odd = Odd`).
*   We have `cnt_even` even numbers. Each even number requires one operation (adding an existing odd number to it) to become odd.
*   This strategy is **always possible** as long as there is at least one odd number available to perform the addition.

### Conclusion
*   If `cnt_odd == 0` or `cnt_even == 0`, the array already satisfies the condition, so the answer is `0`.
*   Otherwise, if `cnt_odd` is even, we compare the cost of Strategy 1 (`cnt_odd / 2`) and Strategy 2 (`cnt_even`) and take the minimum.
*   If `cnt_odd` is odd, we must use Strategy 2, so the answer is `cnt_even`.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array once to count the parity of the elements.
- **Space Complexity**: $O(1)$, as we only store the counts of odd and even numbers.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Logic:
 * 1. To make all elements EVEN:
 *    We need to pair all odd numbers. Each pair of odds (Odd + Odd) = Even.
 *    If cnt_odd is even, we need cnt_odd / 2 operations.
 *    If cnt_odd is odd, we cannot make the array all even (we'd be left with one odd).
 * 
 * 2. To make all elements ODD:
 *    We need to eliminate all even numbers. Each (Odd + Even) = Odd.
 *    We need exactly cnt_even operations to eliminate all even numbers.
 */

void solve() {
    int n;
    cin >> n;
    int cnt_odd = 0, cnt_even = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a % 2 == 0) cnt_even++;
        else cnt_odd++;
    }

    // If already all same parity, 0 operations needed
    if (cnt_odd == 0 || cnt_even == 0) {
        cout << 0 << "\n";
    } else {
        // Option 1: Make all even (only possible if cnt_odd is even)
        // Option 2: Make all odd (always possible by using all even numbers)
        if (cnt_odd % 2 == 0) {
            cout << min(cnt_odd / 2, cnt_even) << "\n";
        } else {
            cout << cnt_even << "\n";
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