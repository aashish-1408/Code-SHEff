#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a binary string S of length N. We can perform at most floor(N/2) deletions.
 * We need to obtain a palindrome.
 * 
 * Key Observation:
 * A binary string must contain more 0s than 1s, or more 1s than 0s, or equal amounts.
 * If we count the number of '0's and '1's in the string, we can simply keep all 
 * characters of the majority character. 
 * 
 * Let count0 be the number of '0's and count1 be the number of '1's.
 * If count0 >= count1, we can delete all '1's. The resulting string will be a 
 * sequence of '0's, which is a palindrome.
 * The number of deletions would be count1. Since count1 <= N/2 (because count0 + count1 = N 
 * and count0 >= count1), this satisfies the constraint of at most floor(N/2) deletions.
 * Similarly, if count1 > count0, we delete all '0's. The number of deletions is count0,
 * which is <= N/2.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int count0 = 0;
    int count1 = 0;
    for (char c : S) {
        if (c == '0') count0++;
        else count1++;
    }

    if (count0 >= count1) {
        // Keep only '0's
        for (int i = 0; i < count0; ++i) {
            cout << '0';
        }
        cout << "\n";
    } else {
        // Keep only '1's
        for (int i = 0; i < count1; ++i) {
            cout << '1';
        }
        cout << "\n";
    }
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