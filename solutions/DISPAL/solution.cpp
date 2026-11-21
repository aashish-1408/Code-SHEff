#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct a palindrome of length N with exactly X distinct characters.
 * A palindrome is determined by its first ceil(N/2) characters.
 * Let K = ceil(N/2). We need to use exactly X distinct characters in these K positions.
 * 
 * Constraints:
 * 1. We need at least X distinct characters, so K >= X.
 * 2. We can use at most 26 distinct characters.
 * 3. If K < X, it is impossible, output -1.
 * 
 * Construction:
 * We can fill the first K positions using X distinct characters.
 * To ensure we use exactly X characters, we can use the first X-1 characters once,
 * and fill the remaining K - (X - 1) positions with the X-th character.
 * Then mirror this to the second half of the string.
 */

void solve() {
    int N, X;
    cin >> N >> X;

    int K = (N + 1) / 2;

    if (X > K) {
        cout << -1 << "\n";
        return;
    }

    string s(N, ' ');
    // Fill the first K positions
    // Use characters 'a' to 'a' + X - 1
    for (int i = 0; i < K; ++i) {
        if (i < X - 1) {
            s[i] = (char)('a' + i);
        } else {
            s[i] = (char)('a' + X - 1);
        }
    }

    // Mirror to the second half
    for (int i = 0; i < N / 2; ++i) {
        s[N - 1 - i] = s[i];
    }

    cout << s << "\n";
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