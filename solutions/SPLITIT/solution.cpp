#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a string S of length N. We need to split S into A and B such that
 * S = A + B, and B is a substring of A.
 * 
 * Let the last character of S be S[N-1].
 * If we choose B to be just the last character of S (i.e., B = S[N-1]),
 * then A must be the prefix of S of length N-1 (i.e., A = S[0...N-2]).
 * 
 * The condition "B is a substring of A" becomes:
 * "The character S[N-1] must appear somewhere in the string S[0...N-2]".
 * 
 * If S[N-1] exists in the prefix S[0...N-2], then we can always find such a split.
 * If S[N-1] does not exist in the prefix, can we pick a longer B?
 * If we pick a longer B, say B = S[k...N-1], then A = S[0...k-1].
 * For B to be a substring of A, every character in B must be present in A.
 * Specifically, the last character S[N-1] must be present in A.
 * If S[N-1] is not present in S[0...N-2], it cannot be present in any prefix
 * S[0...k-1] where k-1 < N-1.
 * 
 * Therefore, the condition simplifies to:
 * Does the last character of S appear in the first N-1 characters of S?
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    char last_char = S[N - 1];
    bool found = false;
    for (int i = 0; i < N - 1; ++i) {
        if (S[i] == last_char) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}