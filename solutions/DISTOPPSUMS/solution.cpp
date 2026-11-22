#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need a permutation P of length N (even) such that P[i] + P[N+1-i] are distinct for 1 <= i <= N/2.
 * Let's try to construct the permutation by placing elements such that the sums are distinct.
 * A simple strategy is to arrange the numbers such that we pick pairs from the ends of the range [1, N].
 * 
 * For N = 6:
 * Pairs: (1, 6), (2, 5), (3, 4)
 * Sums: 7, 7, 7 (Not distinct)
 * 
 * We need to shift the pairing. Let's try:
 * P = [1, 3, 5, 2, 4, 6]
 * i=1: P[1]+P[6] = 1+6 = 7
 * i=2: P[2]+P[5] = 3+4 = 7 (Still not distinct)
 * 
 * Let's try a construction that interleaves the sequence:
 * For N=6, try: 1, 2, 3, 4, 5, 6
 * P[1]+P[6] = 1+6 = 7
 * P[2]+P[5] = 2+5 = 7
 * P[3]+P[4] = 3+4 = 7
 * 
 * Actually, a very simple construction that works is to place the first N/2 elements as 1, 2, ..., N/2
 * and the remaining N/2 elements as N, N-1, ..., N/2 + 1.
 * For N=6: P = [1, 2, 3, 6, 5, 4]
 * i=1: 1+4 = 5
 * i=2: 2+5 = 7
 * i=3: 3+6 = 9
 * These are distinct!
 * 
 * Let's verify for N=4:
 * P = [1, 2, 4, 3]
 * i=1: 1+3 = 4
 * i=2: 2+4 = 6
 * Distinct.
 * 
 * This construction P = [1, 2, ..., N/2, N, N-1, ..., N/2 + 1] works.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> P(N);
    int half = N / 2;
    
    // Fill first half with 1 to N/2
    for (int i = 0; i < half; ++i) {
        P[i] = i + 1;
    }
    
    // Fill second half with N down to N/2 + 1
    int val = N;
    for (int i = half; i < N; ++i) {
        P[i] = val--;
    }
    
    for (int i = 0; i < N; ++i) {
        cout << P[i] << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}