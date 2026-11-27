#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to transform string A into string B using the minimum number of operations.
 * An operation allows us to pick a subsequence of indices and change all characters at 
 * those indices to a specific character alpha.
 * 
 * If A[i] == B[i], we don't need to do anything for that index.
 * If A[i] != B[i], we must eventually change A[i] to B[i].
 * 
 * Consider all indices i where A[i] != B[i]. Let the set of target characters 
 * required at these positions be {B[i] | A[i] != B[i]}.
 * If we have multiple positions that need to be changed to the same character 'x', 
 * we can change all of them in a single operation.
 * 
 * Therefore, the minimum number of operations is equal to the number of unique 
 * characters in string B at positions where A[i] != B[i].
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(1) auxiliary space (using a boolean array of size 26).
 */

void solve() {
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;

    // Use a boolean array to track which characters we need to "paint"
    // onto the string A to match B.
    bool needed[26] = {false};
    int operations = 0;

    for (int i = 0; i < N; ++i) {
        if (A[i] != B[i]) {
            int char_idx = B[i] - 'a';
            if (!needed[char_idx]) {
                needed[char_idx] = true;
                operations++;
            }
        }
    }

    cout << operations << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}