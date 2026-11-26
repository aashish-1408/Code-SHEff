#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N members. Each member i reports to Ri.
 * A potential killer is defined as a member who nobody reports to.
 * This means we need to find all indices j (1 <= j <= N) such that 
 * there is no i where Ri == j.
 * 
 * Approach:
 * 1. Create a frequency array or a boolean array 'is_reported' of size N+1.
 * 2. Iterate through the input array R. For each Ri, if Ri != 0, 
 *    mark is_reported[Ri] = true.
 * 3. After processing all inputs, iterate from 1 to N.
 * 4. If is_reported[i] is false, then member i is a potential killer.
 * 
 * Complexity:
 * Time: O(N) to read input and O(N) to iterate through the array. Total O(N).
 * Space: O(N) to store the status of each member.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    // is_reported[i] will be true if someone reports to member i
    vector<bool> is_reported(N + 1, false);

    for (int i = 0; i < N; ++i) {
        int r;
        cin >> r;
        // If r is 0, it's the Don, nobody reports to the Don in the context of 
        // the reporting chain, but the problem says "Ri equals 0" for the Don.
        // We only care about marking members who have someone reporting to them.
        if (r >= 1 && r <= N) {
            is_reported[r] = true;
        }
    }

    // Collect all indices that were never reported to
    bool first = true;
    for (int i = 1; i <= N; ++i) {
        if (!is_reported[i]) {
            if (!first) {
                cout << " ";
            }
            cout << i;
            first = false;
        }
    }
    cout << "\n";

    return 0;
}