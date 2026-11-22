#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef chooses a threshold L >= 0.
 * For a fixed L, Chef can eat any subset of snacks where B_i <= L.
 * To maximize (Sum of A_i - L), for a fixed L, Chef should pick all snacks 
 * where B_i <= L AND A_i > 0.
 * 
 * Let S(L) = sum of all A_i such that (B_i <= L and A_i > 0).
 * Satisfaction = S(L) - L.
 * Since B_i are integers between 1 and 100, L only needs to be checked for 
 * values in the range [0, 100]. If L > 100, S(L) remains the same as S(100), 
 * but (S(L) - L) decreases, so L > 100 is never optimal.
 * 
 * Algorithm:
 * 1. Iterate L from 0 to 100.
 * 2. For each L, calculate the sum of all A_i where B_i <= L and A_i > 0.
 * 3. Calculate satisfaction = sum - L.
 * 4. Keep track of the maximum satisfaction found.
 * 5. Initialize max_satisfaction to 0 (since Chef can choose L=0 and eat nothing).
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    long long max_satisfaction = 0;

    // L can be any non-negative integer. 
    // Given B_i <= 100, checking L from 0 to 100 is sufficient.
    for (int L = 0; L <= 100; ++L) {
        long long current_sum = 0;
        for (int i = 0; i < N; ++i) {
            if (B[i] <= L && A[i] > 0) {
                current_sum += A[i];
            }
        }
        long long satisfaction = current_sum - L;
        if (satisfaction > max_satisfaction) {
            max_satisfaction = satisfaction;
        }
    }

    cout << max_satisfaction << "\n";
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