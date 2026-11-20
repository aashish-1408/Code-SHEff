# [Food Resources (FOODRES)](https://www.codechef.com/problems/FOODRES)

- **Difficulty Rating**: 1235
- **Solved in**: 2 attempt(s)

## Problem Summary
Given $N$ food resources with quantities $A_1, A_2, \dots, A_N$ and a requirement to support $M$ people, we need to find the maximum integer $D$ such that if each person consumes $D$ units of food, the total number of people supported is at least $M$. Mathematically, we want to maximize $D$ such that:
$$\sum_{i=1}^{N} \lfloor \frac{A_i}{D} \rfloor \ge M$$

## Intuition & Mathematical Observation
1. **Monotonicity**: Let $f(D) = \sum_{i=1}^{N} \lfloor \frac{A_i}{D} \rfloor$. As $D$ increases, the value of $\lfloor \frac{A_i}{D} \rfloor$ either stays the same or decreases. Therefore, $f(D)$ is a monotonically non-increasing function.
2. **Binary Search**: Because of the monotonic property, we can binary search for the optimal $D$ in the range $[1, \max(A_i)]$.
3. **Edge Cases**: If even with $D=1$ we cannot satisfy $M$ (though the problem constraints usually imply a solution exists), the answer would be 0. The binary search range should be carefully handled to avoid division by zero.

## Complexity Analysis
- **Time Complexity**: $O(N \log(\max(A_i)))$. We perform a binary search over the range of possible values for $D$, and for each check, we iterate through the array of size $N$.
- **Space Complexity**: $O(N)$ to store the food resource quantities.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to find the maximum D such that sum(floor(A_i / D)) >= M.
 * The function f(D) = sum(floor(A_i / D)) is monotonically non-increasing.
 * Binary search is appropriate.
 * 
 * Constraints:
 * N, M <= 10^5
 * A_i <= 10^4
 * Max possible D is 10^4.
 */

bool check(long long D, long long M, const vector<int>& A) {
    if (D == 0) return true;
    long long total_people_supported = 0;
    for (int val : A) {
        total_people_supported += (val / D);
        // Optimization: break early if we already satisfy M
        if (total_people_supported >= M) return true;
    }
    return total_people_supported >= M;
}

int main() {
    // Optimize I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long M;
    if (!(cin >> N >> M)) return 0;
    
    vector<int> A(N);
    int max_val = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] > max_val) max_val = A[i];
    }

    // Binary search for D in range [1, max_val]
    long long low = 1, high = max_val;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid == 0) {
            low = mid + 1;
            continue;
        }
        if (check(mid, M, A)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    cout << ans << endl;

    return 0;
}
```