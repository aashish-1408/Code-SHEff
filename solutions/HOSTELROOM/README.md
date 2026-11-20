# [Hostel Room (HOSTELROOM)](https://www.codechef.com/problems/HOSTELROOM)

- **Difficulty Rating**: 1169
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given the initial number of people $X$ in a hostel room. You are then provided with a sequence of $N$ events, where each event represents either people entering (positive value) or leaving (negative value) the room. Your task is to determine the maximum number of people present in the room at any point in time, including the initial state.

## Intuition & Mathematical Observation
The problem asks for the maximum value of a running sum. 
1. We initialize a variable `current_people` with the starting value $X$.
2. We maintain a variable `max_people` initialized to $X$, which will store the highest value encountered so far.
3. As we iterate through the array of events, we update `current_people` by adding the current event value.
4. After each update, we compare `current_people` with `max_people` and update `max_people` if the current count is higher.
5. Since the constraints are small ($N, X \le 100$), a simple linear scan is efficient enough to solve the problem.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of events. We iterate through the list of events exactly once.
- **Space Complexity**: $O(1)$, as we only use a few variables to track the current and maximum number of people, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with X people. We iterate through the array A.
 * At each step, we update the current number of people in the room.
 * We need to track the maximum value reached by this count, including the initial state X.
 * 
 * Constraints:
 * T <= 100, N <= 100, X <= 100, A_i between -100 and 100.
 * The maximum possible number of people will not exceed 100 + 100 * 100 = 10100.
 * Standard integer types are sufficient.
 */

void solve() {
    int N;
    long long X;
    cin >> N >> X;

    long long current_people = X;
    long long max_people = X;

    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        current_people += a;
        if (current_people > max_people) {
            max_people = current_people;
        }
    }

    cout << max_people << "\n";
}

int main() {
    // Fast I/O setup
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