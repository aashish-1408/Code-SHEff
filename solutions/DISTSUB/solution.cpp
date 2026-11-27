#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An island is a contiguous block of '0's.
 * We need exactly K islands, each with a distinct length.
 * Let the lengths of the K islands be L_1, L_2, ..., L_K.
 * Since all lengths must be distinct and positive, the minimum sum of lengths 
 * is the sum of the first K positive integers: 1 + 2 + ... + K = K*(K+1)/2.
 * 
 * Between K islands, we need at least K-1 '1's to separate them.
 * If an island is at the start or end, it doesn't necessarily need a '1' on that side.
 * However, to have K islands, we need at least K-1 '1's to separate them.
 * Total length N = (Sum of lengths of islands) + (Number of '1's).
 * 
 * To minimize the total length N for K islands:
 * We need K distinct lengths: 1, 2, ..., K. Sum = K*(K+1)/2.
 * We need at least K-1 '1's to separate these K islands.
 * Minimum N = K*(K+1)/2 + (K-1).
 * 
 * If N < K*(K+1)/2 + (K-1), it is impossible to have K distinct islands.
 * If N >= K*(K+1)/2 + (K-1), we can always construct such a string.
 * We take the smallest K distinct lengths (1, 2, ..., K) and place them 
 * separated by single '1's. This uses K*(K+1)/2 + (K-1) length.
 * Any remaining length (N - min_N) can be added to the last island 
 * (or any island) to increase its length, keeping all lengths distinct 
 * (since we only increase the largest one, it remains the largest).
 */

void solve() {
    long long N, K;
    cin >> N >> K;

    // Minimum length required for K distinct islands:
    // Sum of 1, 2, ..., K is K*(K+1)/2.
    // We need at least K-1 '1's to separate them.
    // Total min length = K*(K+1)/2 + (K-1).
    
    long long min_len = (K * (K + 1)) / 2 + (K - 1);

    if (N >= min_len) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}