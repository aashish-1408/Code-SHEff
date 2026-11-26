#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The bear patrols clearings [L, R].
 * The rabbit cannot visit any clearing in the range [L, R].
 * This effectively splits the forest into two potential disconnected regions:
 * 1. Clearings [1, L-1] (if L > 1)
 * 2. Clearings [R+1, N] (if R < N)
 * 
 * Since the rabbit can move freely within any connected component of non-patrolled 
 * clearings, the rabbit can collect all carrots in any one of these components.
 * The goal is to maximize the total carrots collected.
 * 
 * Strategy:
 * 1. Calculate the sum of carrots in the range [1, L-1].
 * 2. Calculate the sum of carrots in the range [R+1, N].
 * 3. The answer is the maximum of these two sums.
 * 
 * Constraints:
 * N <= 100, A_i <= 100. The sum will not exceed 100 * 100 = 10,000.
 * 'int' is sufficient, but 'long long' is used for safety.
 */

void solve() {
    int N, L, R;
    cin >> N >> L >> R;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    long long sum_left = 0;
    // Sum of carrots in [1, L-1]
    if (L > 1) {
        for (int i = 1; i < L; ++i) {
            sum_left += A[i];
        }
    }

    long long sum_right = 0;
    // Sum of carrots in [R+1, N]
    if (R < N) {
        for (int i = R + 1; i <= N; ++i) {
            sum_right += A[i];
        }
    }

    cout << max(sum_left, sum_right) << "\n";
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