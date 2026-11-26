#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem: COUNTAB
 * Complexity: O(N) per test case, O(T*N) total.
 * Given N <= 10 and T <= 10^4, this is highly efficient.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    int count_a = 0;
    int count_b = 0;

    for (char c : s) {
        if (c == 'a') {
            count_a++;
        } else if (c == 'b') {
            count_b++;
        }
    }

    cout << count_a << " " << count_b << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}