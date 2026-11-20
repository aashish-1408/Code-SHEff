#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to find the length of the longest contiguous subarray with an even sum.
 * Given N <= 50, an O(N^2) approach is perfectly acceptable and efficient.
 * 
 * Logic:
 * 1. Iterate through all possible starting indices 'i'.
 * 2. Maintain a running sum for subarrays starting at 'i' and ending at 'j'.
 * 3. If the sum is even, update the maximum length.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int max_len = 0;

    // Iterate over all possible starting points of a subarray
    for (int i = 0; i < N; ++i) {
        long long current_sum = 0;
        // Iterate over all possible ending points
        for (int j = i; j < N; ++j) {
            current_sum += A[j];
            
            // Check if the sum is even
            if (current_sum % 2 == 0) {
                int current_len = j - i + 1;
                if (current_len > max_len) {
                    max_len = current_len;
                }
            }
        }
    }

    cout << max_len << "\n";
}

int main() {
    // Fast I/O to ensure no overhead
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}