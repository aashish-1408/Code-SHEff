#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find if there exists a non-empty subsequence whose sum is divisible by 3.
 * This is equivalent to finding a non-empty subset whose sum modulo 3 is 0.
 * 
 * Let dp[i][r] be a boolean indicating if it's possible to get a sum with remainder r (0, 1, 2)
 * using a subset of the first i elements.
 * 
 * Since N is small (up to 100), we can use dynamic programming.
 * dp[r] = true if remainder r is achievable.
 * When considering a new element x:
 * new_dp[(r + x) % 3] = true for all r where dp[r] is true.
 * Also, the element x itself can form a sum with remainder x % 3.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // dp[r] stores whether a sum with remainder r is possible using a non-empty subsequence
    vector<bool> dp(3, false);

    for (int i = 0; i < N; ++i) {
        int val = A[i] % 3;
        vector<bool> next_dp = dp;
        
        // Option 1: The element itself forms a subsequence
        next_dp[val] = true;
        
        // Option 2: The element is added to existing subsequences
        for (int r = 0; r < 3; ++r) {
            if (dp[r]) {
                next_dp[(r + val) % 3] = true;
            }
        }
        dp = next_dp;
    }

    if (dp[0]) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
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