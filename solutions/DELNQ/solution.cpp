#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allows us to delete one of two adjacent characters if they are different.
 * This means if we have a '0' and a '1' adjacent, we can remove one of them.
 * 
 * Case 1: If the string contains both '0' and '1', we can always reduce the string
 * until only one character remains. Why? Because as long as there is at least one '0'
 * and one '1', there must be at least one pair of adjacent characters that are different
 * (unless the string is all 0s or all 1s). By repeatedly applying the operation,
 * we can eliminate characters until only one remains.
 * 
 * Case 2: If the string consists of only '0's or only '1's, no operation can ever
 * be performed because there are no adjacent characters that are different.
 * In this case, the length remains N.
 * 
 * Conclusion:
 * If the string contains both '0' and '1', the answer is 1.
 * Otherwise, the answer is N.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool hasZero = false;
    bool hasOne = false;

    for (char c : s) {
        if (c == '0') hasZero = true;
        if (c == '1') hasOne = true;
    }

    if (hasZero && hasOne) {
        cout << 1 << "\n";
    } else {
        cout << n << "\n";
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