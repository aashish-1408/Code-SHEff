#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let the current values be a and b.
 * Operation 1: a' = a + d, b' = b + d - 1
 * Change in difference (a - b): (a + d) - (b + d - 1) = a - b + 1
 * Operation 2: a' = a + d - 1, b' = b + d
 * Change in difference (a - b): (a + d - 1) - (b + d) = a - b - 1
 * 
 * In both operations, the difference (a - b) changes by either +1 or -1.
 * Since we can choose any positive integer d, we can always change the 
 * difference (a - b) by 1 in either direction.
 * 
 * If we start with any two integers a and b, we can reach a state where 
 * a = b because we can always reduce the absolute difference |a - b| 
 * by 1 in each step until it becomes 0.
 * 
 * Therefore, it is always possible to make a = b for any positive integers a and b.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        // As derived, it is always possible to make a == b.
        cout << "YES" << "\n";
    }

    return 0;
}