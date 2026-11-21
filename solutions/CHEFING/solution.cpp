#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the number of characters that appear in every single string S_1, ..., S_N.
 * Since the alphabet size is small (26 lowercase English letters), we can maintain a frequency 
 * count or a boolean presence array for each string.
 * 
 * Approach:
 * 1. For each test case, initialize a frequency array `count[26]` to 0.
 * 2. For the first string, mark which characters are present (using a boolean array or set).
 * 3. For subsequent strings, update the global count of characters that appear in all strings.
 * 4. A more efficient way:
 *    - Create an array `common[26]` initialized to true (or 1).
 *    - For each string, create a local `present[26]` array.
 *    - For each character in the string, set `present[char - 'a'] = true`.
 *    - Update `common[i] = common[i] && present[i]` for all i from 0 to 25.
 * 5. Finally, count how many indices in `common` are true.
 * 
 * Complexity:
 * Time: O(T * N * |S_i|), which is well within the limit given the sum of lengths constraint.
 * Space: O(1) auxiliary space (fixed size 26 arrays).
 */

void solve() {
    int N;
    cin >> N;
    
    // common[i] will be true if the i-th letter of the alphabet 
    // has appeared in every string processed so far.
    vector<bool> common(26, true);
    
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        
        vector<bool> present(26, false);
        for (char c : s) {
            present[c - 'a'] = true;
        }
        
        // Update common array: a character is only "common" if it was 
        // common before AND it is present in the current string.
        for (int j = 0; j < 26; ++j) {
            common[j] = common[j] && present[j];
        }
    }
    
    int result = 0;
    for (int j = 0; j < 26; ++j) {
        if (common[j]) {
            result++;
        }
    }
    
    cout << result << "\n";
}

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}