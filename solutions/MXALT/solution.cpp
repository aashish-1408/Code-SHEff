#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * The alternating sum is A_1 - A_2 + A_3 - A_4 + ...
 * There are ceil(N/2) positive positions and floor(N/2) negative positions.
 * To maximize the sum, we assign the largest values to the positive positions
 * and the smallest values to the negative positions.
 * 
 * Complexity: O(N log N) per test case due to sorting.
 * Total complexity: O(T * N log N), which fits within the 2*10^5 constraint.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort the array to easily pick smallest and largest elements
    sort(A.begin(), A.end());

    long long ans = 0;
    int num_neg = N / 2;

    // Subtract the smallest N/2 elements
    for (int i = 0; i < num_neg; ++i) {
        ans -= A[i];
    }
    
    // Add the remaining elements (the largest ones)
    for (int i = num_neg; i < N; ++i) {
        ans += A[i];
    }

    cout << ans << "\n";
}

int main() {
    // Fast I/O is essential for large input sizes
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}