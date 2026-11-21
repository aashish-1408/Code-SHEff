# [Chefland Library (BORROWBOOK)](https://www.codechef.com/problems/BORROWBOOK)

- **Difficulty Rating**: 1058
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ books, where the $i$-th book (indexed from 1 to $N$) is returned on day $A_i$. The penalty for returning the $i$-th book is $i$. For any given day $D$, if multiple books are returned, the penalty incurred for that day is the maximum index $i$ among all books returned on that day. We need to calculate the total penalty, which is the sum of the maximum penalties for every day on which at least one book was returned.

## Intuition & Mathematical Observation
The problem asks us to group books by their return day $A_i$ and, for each unique day, identify the largest book index $i$ associated with it.

1. **Data Structure**: Since the return days $A_i$ are constrained up to $10^5$, we can use an array or a vector of size $100,001$ to store the maximum index found for each day.
2. **Tracking**: As we iterate through the input array $A$, for each book $i$ returned on day $A_i$, we update `max_penalty[A_i] = max(max_penalty[A_i], i)`.
3. **Efficiency**: To handle multiple test cases efficiently without re-initializing the entire array (which would be $O(T \times 10^5)$), we keep track of the days that were actually updated in a separate list (`days_used`). After calculating the total penalty, we reset only those specific indices in the `max_penalty` array to 0 for the next test case.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of books. We iterate through the input once to find the maximums and once through the `days_used` list to calculate the sum. The total time complexity is $O(\sum N)$, which fits well within the limits.
- **Space Complexity**: $O(M)$, where $M$ is the maximum possible day value ($10^5$). This is used for the `max_penalty` array and the `days_used` vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N books. The i-th book (1-indexed) was returned on day A_i.
 * For each day D, we need to find the maximum penalty (book index i) among all books returned on day D.
 * The total penalty is the sum of max_penalty[D] for all days D where at least one book was returned.
 */

void solve() {
    int N;
    cin >> N;
    
    // max_penalty stores the highest book index for each day.
    // Using static to avoid repeated allocation.
    static vector<int> max_penalty(100001, 0);
    vector<int> days_used;
    
    for (int i = 1; i <= N; ++i) {
        int day;
        cin >> day;
        // If this is the first time we see this day, track it for resetting later
        if (max_penalty[day] == 0) {
            days_used.push_back(day);
        }
        // Update the max penalty for this day
        if (i > max_penalty[day]) {
            max_penalty[day] = i;
        }
    }
    
    long long total_penalty = 0;
    for (int day : days_used) {
        total_penalty += max_penalty[day];
        // Reset for next test case to keep the array clean
        max_penalty[day] = 0;
    }
    
    cout << total_penalty << "\n";
}

int main() {
    // Fast I/O for performance
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