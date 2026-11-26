#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N intervals, each with duration Ti and data usage Di per minute.
 * The first K minutes are free. We need to calculate the total cost for the 
 * remaining minutes.
 * 
 * Approach:
 * Iterate through the intervals. For each interval (Ti, Di):
 * 1. If K >= Ti, the entire interval is free. Subtract Ti from K.
 * 2. If 0 < K < Ti, the first K minutes are free, and the remaining (Ti - K) 
 *    minutes are charged at Di per minute. Cost += (Ti - K) * Di. Set K = 0.
 * 3. If K == 0, the entire interval is charged. Cost += Ti * Di.
 * 
 * Time Complexity: O(N) per test case, where N <= 10.
 * Space Complexity: O(1).
 */

void solve() {
    int N;
    long long K;
    cin >> N >> K;

    long long total_cost = 0;

    for (int i = 0; i < N; ++i) {
        long long Ti, Di;
        cin >> Ti >> Di;

        if (K >= Ti) {
            // Entire interval is free
            K -= Ti;
        } else if (K > 0) {
            // Part of the interval is free, part is charged
            long long charged_minutes = Ti - K;
            total_cost += charged_minutes * Di;
            K = 0;
        } else {
            // Entire interval is charged
            total_cost += Ti * Di;
        }
    }

    cout << total_cost << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}