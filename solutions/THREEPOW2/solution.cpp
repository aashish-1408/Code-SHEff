#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a binary string S representing a number X.
 * We need to determine if X can be represented as the sum of exactly three non-negative powers of 2.
 * Let the number of set bits (1s) in the binary representation be 'k'.
 * 
 * Any number can be represented as a sum of 'k' powers of 2 (its binary expansion).
 * If we want to represent it as a sum of exactly 3 powers of 2:
 * 1. If k = 1: X = 2^a. We need 2^a = 2^x + 2^y + 2^z.
 *    This is only possible if we can split 2^a into three powers. 
 *    2^a = 2^{a-1} + 2^{a-1} = 2^{a-1} + 2^{a-2} + 2^{a-2}.
 *    This requires a >= 2. If a=0 (X=1), impossible. If a=1 (X=2), impossible.
 * 2. If k = 2: X = 2^a + 2^b (assume a > b).
 *    We need 2^a + 2^b = 2^x + 2^y + 2^z.
 *    We can write 2^a = 2^{a-1} + 2^{a-1}.
 *    So X = 2^{a-1} + 2^{a-1} + 2^b. This is exactly 3 powers.
 *    This is possible if a >= 1. Since S has no leading zeros, if k=2, the highest bit is at least 1.
 *    The only case where this fails is if we can't split (e.g., if the highest bit is 2^0, but that's impossible for k=2).
 *    Actually, for k=2, X = 2^a + 2^b. If a > 0, we can always split 2^a.
 * 3. If k = 3: X = 2^a + 2^b + 2^c. This is already 3 powers. Always YES.
 * 4. If k > 3: Impossible to represent as sum of 3 powers of 2.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int k = 0;
    for (char c : S) {
        if (c == '1') k++;
    }

    if (k == 1) {
        // X = 2^a. Need 2^a = 2^x + 2^y + 2^z.
        // Only possible if a >= 2. 
        // Since S has no leading zeros, the power 'a' is (N-1).
        if (N - 1 >= 2) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    } else if (k == 2) {
        // X = 2^a + 2^b. Always possible to split 2^a into 2^{a-1} + 2^{a-1}
        // as long as a >= 1. Since k=2, the highest bit must be at least 1.
        // The only case is if the number is 2^0 + 2^something, which is fine.
        cout << "YES" << "\n";
    } else if (k == 3) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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