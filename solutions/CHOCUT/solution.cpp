#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has an N x M chocolate bar.
 * Total squares = N * M.
 * 
 * Options:
 * 1. No cut: 
 *    - If K == 0, Alice can keep the whole bar (N*M).
 *    - If K > 0, Alice can give the whole bar to Bob, keeping 0.
 * 2. Horizontal cut:
 *    - Cut into (i * M) and ((N-i) * M).
 *    - If (i * M) >= K, she can keep ((N-i) * M).
 *    - If ((N-i) * M) >= K, she can keep (i * M).
 * 3. Vertical cut:
 *    - Cut into (N * j) and (N * (M-j)).
 *    - If (N * j) >= K, she can keep (N * (M-j)).
 *    - If (N * (M-j)) >= K, she can keep (N * j).
 */

void solve() {
    long long N, M, K;
    cin >> N >> M >> K;

    // If K is 0, Alice keeps everything without cutting.
    if (K == 0) {
        cout << N * M << "\n";
        return;
    }

    long long max_kept = 0;

    // Case: No cut (give everything to Bob)
    if (N * M >= K) {
        max_kept = 0;
    }

    // Case: Horizontal cut
    for (int i = 1; i < N; ++i) {
        long long piece1 = (long long)i * M;
        long long piece2 = (long long)(N - i) * M;
        
        if (piece1 >= K) max_kept = max(max_kept, piece2);
        if (piece2 >= K) max_kept = max(max_kept, piece1);
    }

    // Case: Vertical cut
    for (int j = 1; j < M; ++j) {
        long long piece1 = (long long)N * j;
        long long piece2 = (long long)N * (M - j);
        
        if (piece1 >= K) max_kept = max(max_kept, piece2);
        if (piece2 >= K) max_kept = max(max_kept, piece1);
    }

    cout << max_kept << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}