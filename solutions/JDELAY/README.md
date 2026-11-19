# [Judging Delay (JDELAY)](https://www.codechef.com/problems/JDELAY)

- **Difficulty Rating**: 964
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine how many submissions in a contest were "delayed." A submission is considered delayed if the difference between the time it was judged ($J_i$) and the time it was submitted ($S_i$) is strictly greater than 5 seconds. We are given $N$ submissions, each with its respective submission time and judging time, and we need to output the total count of delayed submissions for each test case.

## Intuition & Mathematical Observation
The condition for a submission to be delayed is defined by the inequality:
$$J_i - S_i > 5$$

Since the constraints are small ($N \le 100$ per test case), we do not need any complex data structures or algorithms. We can simply iterate through each submission, calculate the difference $J_i - S_i$, and increment a counter whenever the condition is met. 

- **Input Handling**: We read the number of test cases $T$, and for each test case, we read $N$ followed by $N$ pairs of $(S_i, J_i)$.
- **Logic**: A simple `if` statement inside a loop is sufficient to check the condition for every submission.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of submissions. Given $T$ test cases, the total time complexity is $O(T \times N)$. With $N, T \le 100$, this performs roughly $10^4$ operations, which is well within the 1-second time limit.
- **Space Complexity**: $O(1)$, as we only store a few integer variables (`N`, `S`, `J`, `count`) regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Judging Delay
 * Approach:
 * For each submission, the delay is calculated as (J_i - S_i).
 * We need to count how many submissions have (J_i - S_i) > 5.
 * Given the constraints (N <= 100, T <= 100), a simple O(N) loop per test case
 * is well within the time limit.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    int count = 0;
    for (int i = 0; i < N; ++i) {
        int S, J;
        cin >> S >> J;
        // The delay is J - S. We check if it is strictly greater than 5.
        if ((J - S) > 5) {
            count++;
        }
    }
    cout << count << "\n";
}

int main() {
    // Fast I/O setup
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