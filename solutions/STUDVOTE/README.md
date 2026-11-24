# [Drumpf for President! (STUDVOTE)](https://www.codechef.com/problems/STUDVOTE)

- **Difficulty Rating**: 1205
- **Solved in**: 1 attempt(s)

## Problem Summary
In an election with $N$ students, each student casts exactly one vote for another student (or themselves). A student is eligible to be part of the government if and only if:
1. They receive at least $K$ votes.
2. They did not vote for themselves.

We need to determine the total number of students who meet these criteria.

## Intuition & Mathematical Observation
The problem can be solved by tracking two pieces of information for every student:
1. **Vote Count**: How many students voted for them.
2. **Self-Vote Status**: Whether they cast a vote for themselves.

By maintaining an array `votes` of size $N+1$ to store the tally and a boolean array `disqualified` to track self-voters, we can process the input in a single pass. 

- If student $i$ votes for student $A[i]$, we increment `votes[A[i]]`.
- If $i == A[i]$, we mark `disqualified[i]` as `true`.

After processing all votes, we iterate through the students from $1$ to $N$. A student is counted if `votes[i] >= K` AND `disqualified[i]` is `false`.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case. We iterate through the list of votes once to populate the arrays and once more to count the eligible candidates. Given $T$ test cases, the total time complexity is $O(T \times N)$.
- **Space Complexity**: $O(N)$. We use two auxiliary arrays of size $N+1$ to store the vote counts and the disqualification status.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. We have N students, each casting one vote.
 * 2. A student is disqualified if they vote for themselves.
 * 3. A student is eligible for the government if they receive at least K votes
 *    AND they are not disqualified.
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;

    vector<int> votes(N + 1, 0);
    vector<bool> disqualified(N + 1, false);

    for (int i = 1; i <= N; ++i) {
        int target;
        cin >> target;
        
        // Count the vote
        votes[target]++;
        
        // Check if the student voted for themselves
        if (i == target) {
            disqualified[i] = true;
        }
    }

    int government_size = 0;
    for (int i = 1; i <= N; ++i) {
        // Check eligibility criteria
        if (votes[i] >= K && !disqualified[i]) {
            government_size++;
        }
    }

    cout << government_size << "\n";
}

int main() {
    // Fast I/O setup
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