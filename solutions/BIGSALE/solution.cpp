#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Original price = p
 * Price after x% increase = p * (1 + x/100)
 * Price after x% discount on the increased price = (p * (1 + x/100)) * (1 - x/100)
 * Final price = p * (1 + x/100) * (1 - x/100)
 * Final price = p * (1 - (x/100)^2)
 * 
 * Loss per unit = Original price - Final price
 * Loss per unit = p - p * (1 - (x/100)^2)
 * Loss per unit = p * (x/100)^2
 * 
 * Total loss for a recipe type = quantity * (p * (x/100)^2)
 * 
 * Constraints:
 * T <= 10, N <= 10^5
 * price, quantity <= 100
 * discount <= 100
 * Total complexity: O(T * N), which is well within the 2s time limit.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        cin >> n;

        double total_loss = 0.0;
        for (int i = 0; i < n; ++i) {
            double p, q, x;
            cin >> p >> q >> x;

            // Loss per unit = p * (x/100) * (x/100)
            double loss_per_unit = p * (x / 100.0) * (x / 100.0);
            total_loss += (loss_per_unit * q);
        }

        // Output with required precision
        cout << fixed << setprecision(8) << total_loss << "\n";
    }

    return 0;
}