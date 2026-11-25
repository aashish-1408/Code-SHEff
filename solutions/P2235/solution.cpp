#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * A palindrome P of length N satisfies P[i] = P[N - 1 - i] for all 0 <= i < N.
 * 
 * To uniquely reconstruct the palindrome:
 * 1. For any pair (i, N - 1 - i) where i != N - 1 - i:
 *    - If both S[i] and S[N - 1 - i] are '?', we have 26 choices (a-z). Not unique.
 *    - If one is '?' and the other is a character, the '?' is forced.
 *    - If both are characters, they are already fixed.
 * 2. For the middle element (if N is odd, i = N/2):
 *    - If S[i] is '?', we have 26 choices (a-z). Not unique.
 *    - If S[i] is a character, it is fixed.
 * 
 * If any of these "free choice" scenarios exist, the answer is NO. Otherwise, YES.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    string S;
    cin >> S;

    bool unique = true;
    
    // Check pairs (i, N-1-i)
    for (int i = 0; i < (N + 1) / 2; ++i) {
        int j = N - 1 - i;
        
        if (i == j) {
            // Middle element of odd length string
            if (S[i] == '?') {
                unique = false;
            }
        } else {
            // Pair of indices
            if (S[i] == '?' && S[j] == '?') {
                // Both are '?', can be any of 26 letters
                unique = false;
            }
            // If one is '?' and other is char, it's forced.
            // If both are chars, they are already fixed (guaranteed consistent).
        }
    }

    if (unique) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}