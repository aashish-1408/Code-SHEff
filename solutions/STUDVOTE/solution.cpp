#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. We have N students, each casting one vote.
 * 2. A student is disqualified if they vote for themselves.
 * 3. A student is eligible for the government if they receive at least K votes
 *    AND they are not disqualified.
 * 
 * Approach:
 * 1. Use an array `votes` of size N+1 to count the number of votes each student receives.
 * 2. Use a boolean array `disqualified` of size N+1 to track if a student voted for themselves.
 * 3. Iterate through the input array A:
 *    - If student i votes for student A[i], increment `votes[A[i]]`.
 *    - If i == A[i], mark `disqualified[i] = true`.
 * 4. After processing all votes, iterate from 1 to N:
 *    - If `votes[i] >= K` and `!disqualified[i]`, increment the count of government members.
 * 
 * Complexity:
 * - Time: O(N) per test case. With T test cases, O(T * N).
 * - Space: O(N) to store vote counts and disqualification status.
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