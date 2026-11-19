#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * For a rectangle with dimensions A_i x B_j, the diameter of the largest 
 * inscribed circle is min(A_i, B_j).
 * We want to maximize the sum of diameters: sum_{i=1}^N min(A_i, B_{P_i}).
 * 
 * By sorting both arrays A and B in non-decreasing order and pairing 
 * A[i] with B[i], we maximize the sum of the minimums.
 * 
 * Complexity:
 * Sorting: O(N log N)
 * Summation: O(N)
 * Total: O(T * N log N), which is well within the 1.5s limit for N=10^4.
 * Data types: A_i, B_i up to 10^9, so the sum can exceed 2^31-1. 
 * Using long long for the sum is necessary.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }
    
    // Sorting both arrays to pair smallest with smallest
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    long long total_diameter = 0;
    for (int i = 0; i < N; ++i) {
        total_diameter += min(A[i], B[i]);
    }
    
    cout << total_diameter << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}