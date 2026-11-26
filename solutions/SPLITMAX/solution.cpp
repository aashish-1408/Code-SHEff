#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let S be the sum of all elements in the array C.
 * f(A) = sum_{i=1 to M} sum_{j=1, j!=i to M} (A_i * A_j)
 * This is equivalent to: (sum_{i=1 to M} A_i)^2 - sum_{i=1 to M} (A_i^2)
 * Since the sum of elements S remains constant regardless of the operations,
 * f(A) = S^2 - sum_{i=1 to M} (A_i^2).
 * To maximize f(A), we need to minimize sum_{i=1 to M} (A_i^2).
 * 
 * We can split any element C_i into smaller positive integers.
 * To minimize the sum of squares, we should split every C_i into as many 1s as possible.
 * If we split C_i into C_i ones, the sum of squares becomes C_i * (1^2) = C_i.
 * If we don't split, the sum of squares is C_i^2.
 * Since C_i >= 1, C_i^2 >= C_i, with equality only if C_i = 1.
 * Thus, the optimal strategy is to split every element into 1s.
 * 
 * The final array will consist of S ones, where S = sum(C_i).
 * The number of elements M = S.
 * f(A) = S^2 - sum_{i=1 to S} (1^2) = S^2 - S = S * (S - 1).
 * 
 * All calculations should be done modulo 998244353.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    long long MOD = 998244353;

    while (t--) {
        int n;
        cin >> n;
        long long s = 0;
        for (int i = 0; i < n; ++i) {
            long long c;
            cin >> c;
            s = (s + c) % MOD;
        }

        // Result is S * (S - 1) mod MOD
        long long ans = (s * (s - 1 + MOD)) % MOD;
        cout << ans << "\n";
    }

    return 0;
}