#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Easy Speaking
 * Logic: Iterate through the string and maintain a counter of consecutive consonants.
 * If the counter reaches 4, the word is hard to pronounce.
 * Reset the counter to 0 whenever a vowel is encountered.
 */

bool is_consonant(char c) {
    return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int consecutive_consonants = 0;
    bool hard = false;

    for (int i = 0; i < n; ++i) {
        if (is_consonant(s[i])) {
            consecutive_consonants++;
            if (consecutive_consonants >= 4) {
                hard = true;
                break;
            }
        } else {
            consecutive_consonants = 0;
        }
    }

    if (hard) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}