#include <bits/stdc++.h>
using namespace std;

/**
 * Logic:
 * 1. To make all elements EVEN:
 *    We need to pair all odd numbers. Each pair of odds (Odd + Odd) = Even.
 *    If cnt_odd is even, we need cnt_odd / 2 operations.
 *    If cnt_odd is odd, we cannot make the array all even (we'd be left with one odd).
 * 
 * 2. To make all elements ODD:
 *    We need to eliminate all even numbers. Each (Odd + Even) = Odd.
 *    We need exactly cnt_even operations to eliminate all even numbers.
 */

void solve() {
    int n;
    cin >> n;
    int cnt_odd = 0, cnt_even = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a % 2 == 0) cnt_even++;
        else cnt_odd++;
    }

    if (cnt_odd == 0 || cnt_even == 0) {
        cout << 0 << "\n";
    } else {
        // Option 1: Make all even (only possible if cnt_odd is even)
        // Option 2: Make all odd (always possible by using all even numbers)
        if (cnt_odd % 2 == 0) {
            cout << min(cnt_odd / 2, cnt_even) << "\n";
        } else {
            cout << cnt_even << "\n";
        }
    }
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