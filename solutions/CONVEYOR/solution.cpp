#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The object starts at position P (1-indexed).
 * - If the object moves to the left (L) and reaches 0, it is collected.
 * - If the object moves to the right (R) and reaches N+1, it is collected.
 * 
 * To reach 0 (left collection point):
 * All slots from 1 to P must be 'L'. If any slot i (1 <= i <= P) is 'R', 
 * it must be reversed to 'L'.
 * Cost to reach 0 = count of 'R' in S[0...P-1].
 * 
 * To reach N+1 (right collection point):
 * All slots from P to N must be 'R'. If any slot i (P <= i <= N) is 'L', 
 * it must be reversed to 'R'.
 * Cost to reach N+1 = count of 'L' in S[P-1...N-1].
 * 
 * The minimum number of reversals is the minimum of these two costs.
 */

void solve() {
    int N, P;
    cin >> N >> P;
    string S;
    cin >> S;

    // Cost to reach 0: count 'R' in S[0...P-1]
    int cost_left = 0;
    for (int i = 0; i < P; ++i) {
        if (S[i] == 'R') {
            cost_left++;
        }
    }

    // Cost to reach N+1: count 'L' in S[P-1...N-1]
    int cost_right = 0;
    for (int i = P - 1; i < N; ++i) {
        if (S[i] == 'L') {
            cost_right++;
        }
    }

    cout << min(cost_left, cost_right) << "\n";
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