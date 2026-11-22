#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * The equation A_i + A_j = A_i * A_j can be rewritten as:
 * A_i * A_j - A_i - A_j + 1 = 1
 * (A_i - 1) * (A_j - 1) = 1
 * 
 * Since A_i are integers, the factors of 1 are (1, 1) or (-1, -1).
 * 1) A_i - 1 = 1  => A_i = 2
 *    A_j - 1 = 1  => A_j = 2
 * 2) A_i - 1 = -1 => A_i = 0
 *    A_j - 1 = -1 => A_j = 0
 * 
 * We simply count the occurrences of 0 and 2.
 * For a count 'c', the number of pairs is c * (c - 1) / 2.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    long long count0 = 0;
    long long count2 = 0;
    
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val == 0) {
            count0++;
        } else if (val == 2) {
            count2++;
        }
    }
    
    // Use long long for calculation to prevent overflow, 
    // though with N=40,000, the result fits in long long.
    long long ans = (count0 * (count0 - 1) / 2) + (count2 * (count2 - 1) / 2);
    cout << ans << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}