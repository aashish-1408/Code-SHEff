# [Maximise Sum (P4149)](https://www.codechef.com/problems/P4149)

- **Difficulty Rating**: 1372
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, you are allowed to perform an operation where you choose any two elements and flip their signs simultaneously. The goal is to maximize the sum of the array elements after performing this operation any number of times.

## Intuition & Mathematical Observation
The key to this problem lies in the invariant property of the operation:
1. **Parity Invariant**: Flipping the signs of two elements simultaneously does not change the parity of the count of negative numbers in the array. 
   - If you flip two negative numbers, the count decreases by 2 (parity remains the same).
   - If you flip two positive numbers, the count increases by 2 (parity remains the same).
   - If you flip one positive and one negative, the count remains the same.

2. **Case 1: Even number of negative elements**:
   Since we can flip any two elements, we can pair up all negative numbers and flip them to positive. Thus, if the count of negative numbers is even, we can make all elements positive, and the maximum sum is simply the sum of the absolute values of all elements.

3. **Case 2: Odd number of negative elements**:
   We will always be left with at least one negative sign regardless of the operations performed. To maximize the total sum, we want the "cost" of this negative sign to be as small as possible. Therefore, we should assign the negative sign to the element with the smallest absolute value. The result is the sum of all absolute values minus twice the smallest absolute value (since it was added in `sum_abs` but should be subtracted).

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We iterate through the array exactly once to calculate the sum, count negatives, and find the minimum absolute value.
- **Space Complexity**: $O(N)$ to store the array (though this could be optimized to $O(1)$ by processing elements on the fly).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allows us to flip the signs of any two elements simultaneously.
 * This means the parity of the number of negative signs in the array remains invariant.
 * 
 * 1. If the number of negative elements is even, we can flip all of them to positive
 *    using the operation repeatedly (flip two negatives at a time).
 * 2. If the number of negative elements is odd, we will always be left with at least
 *    one negative sign. To maximize the sum, we should make the element with the 
 *    smallest absolute value negative.
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    int neg_count = 0;
    long long min_abs = 200000; // Larger than max possible |A_i|
    long long sum_abs = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < 0) {
            neg_count++;
        }
        long long abs_val = abs(a[i]);
        sum_abs += abs_val;
        if (abs_val < min_abs) {
            min_abs = abs_val;
        }
    }

    if (neg_count % 2 == 0) {
        cout << sum_abs << "\n";
    } else {
        // We must have one negative value. To maximize sum, 
        // we make the smallest absolute value negative.
        // Current sum_abs is sum(|A_i|). 
        // We need sum(|A_i|) - 2 * min(|A_i|).
        cout << sum_abs - 2 * min_abs << "\n";
    }
}

int main() {
    // Fast I/O
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