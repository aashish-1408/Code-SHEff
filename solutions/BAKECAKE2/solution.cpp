#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each ingredient i, we need A_i amount and we have B_i amount.
 * If A_i > B_i, we need to buy (A_i - B_i) amount.
 * If A_i <= B_i, we have enough, so we buy 0.
 * The cost per unit is 1, so the cost for ingredient i is max(0, A_i - B_i).
 * Total cost = sum of max(0, A_i - B_i) for all i from 1 to N.
 * 
 * Constraints:
 * T <= 100, N <= 100, A_i, B_i <= 100.
 * The maximum possible cost is 100 * 100 = 10,000, which fits in a standard int.
 * Using long long is safe practice.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        long long total_cost = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) {
                total_cost += (a[i] - b[i]);
            }
        }
        cout << total_cost << "\n";
    }

    return 0;
}