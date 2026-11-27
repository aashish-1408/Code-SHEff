#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Problem Analysis:
 * The operation allows swapping A[i] and A[i+2].
 * This means all characters at even indices can be rearranged, 
 * and all characters at odd indices can be rearranged.
 * 
 * For the string to be a palindrome, A[i] must equal A[N-1-i].
 * Since N is even, if i is even, N-1-i is odd. 
 * This implies the multiset of characters at even positions 
 * must be identical to the multiset of characters at odd positions.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    string S;
    cin >> S;

    int even_counts[26] = {0};
    int odd_counts[26] = {0};

    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            even_counts[S[i] - 'a']++;
        } else {
            odd_counts[S[i] - 'a']++;
        }
    }

    bool possible = true;
    for (int i = 0; i < 26; ++i) {
        if (even_counts[i] != odd_counts[i]) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}