#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We need to find the maximum N such that there exists a sequence A_1, ..., A_N
 * satisfying A_i + S_i = K.
 * As derived: S_i = (S_{i-1} + K) / 2.
 * For S_i to be an integer, (S_{i-1} + K) must be even.
 * With S_0 = 0:
 * S_1 = K/2. Valid if K is divisible by 2.
 * S_2 = (K/2 + K)/2 = 3K/4. Valid if K is divisible by 4.
 * S_3 = (3K/4 + K)/2 = 7K/8. Valid if K is divisible by 8.
 * The sequence continues as long as the current K is divisible by 2^i.
 * The maximum length is the exponent of the highest power of 2 that divides K.
 */

void solve() {
    long long K;
    if (!(cin >> K)) return;
    
    int count = 0;
    // Count how many times K is divisible by 2
    while (K > 0 && K % 2 == 0) {
        K /= 2;
        count++;
    }
    cout << count << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}