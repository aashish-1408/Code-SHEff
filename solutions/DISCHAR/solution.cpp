#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the size of the largest subsequence with distinct characters.
 * Since a subsequence maintains the relative order of characters, if we have 
 * multiple occurrences of the same character, we can only pick one of them 
 * to be in our subsequence if we want all characters to be distinct.
 * 
 * Therefore, the largest subsequence with distinct characters is simply the 
 * count of unique characters present in the string.
 * 
 * Example: "aba"
 * Unique characters: 'a', 'b'. Count = 2.
 * 
 * Complexity:
 * Time: O(N) per test case, where N is the length of the string.
 * Space: O(1) auxiliary space (using a boolean array or set of size 26).
 */

void solve() {
    string s;
    cin >> s;
    
    // Use a boolean array to track which characters have appeared
    bool seen[26] = {false};
    int distinct_count = 0;
    
    for (char c : s) {
        if (!seen[c - 'a']) {
            seen[c - 'a'] = true;
            distinct_count++;
        }
    }
    
    cout << distinct_count << "\n";
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