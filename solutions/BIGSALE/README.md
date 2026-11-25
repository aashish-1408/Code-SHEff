# [A Big Sale (BIGSALE)](https://www.codechef.com/problems/BIGSALE)

- **Difficulty Rating**: 1260
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the total loss incurred by a shopkeeper after a series of price adjustments. For each item, the price is first increased by $x\%$, and then a discount of $x\%$ is applied to the new increased price. We are given the original price ($p$), the quantity ($q$), and the percentage ($x$) for several items. We need to find the sum of the losses across all items.

## Intuition & Mathematical Observation
Let the original price be $p$.

1. **Price after $x\%$ increase**: 
   $$P_{increased} = p \times (1 + \frac{x}{100})$$
2. **Price after $x\%$ discount on the increased price**:
   $$P_{final} = P_{increased} \times (1 - \frac{x}{100})$$
   $$P_{final} = p \times (1 + \frac{x}{100}) \times (1 - \frac{x}{100})$$
   Using the difference of squares identity $(a+b)(a-b) = a^2 - b^2$:
   $$P_{final} = p \times (1 - (\frac{x}{100})^2)$$

3. **Loss per unit**:
   $$\text{Loss} = \text{Original Price} - \text{Final Price}$$
   $$\text{Loss} = p - p \times (1 - (\frac{x}{100})^2)$$
   $$\text{Loss} = p \times (\frac{x}{100})^2$$

4. **Total Loss**:
   For a given quantity $q$, the total loss for that item type is $q \times p \times (\frac{x}{100})^2$. Summing this for all items gives the final answer.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the number of items. Given $N \le 10^5$ and $T \le 10$, the total operations are well within the limit for a 2-second execution time.
- **Space Complexity**: $O(1)$, as we only store a few variables to calculate the running total of the loss.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Original price = p
 * Price after x% increase = p * (1 + x/100)
 * Price after x% discount on the increased price = (p * (1 + x/100)) * (1 - x/100)
 * Final price = p * (1 - (x/100)^2)
 * 
 * Loss per unit = p - p * (1 - (x/100)^2) = p * (x/100)^2
 * Total loss = quantity * (p * (x/100)^2)
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
```