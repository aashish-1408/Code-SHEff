#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The parity of the final sum depends only on the parity of the elements.
 * Let 'o' be the count of odd numbers and 'e' be the count of even numbers.
 * Adding an even number does not change the parity of the sum.
 * Adding an odd number flips the parity of the sum.
 * 
 * Let the final sum be S = (sum of signed odd numbers) + (sum of signed even numbers).
 * Parity(S) = Parity(number of odd numbers with a '-' sign).
 * Specifically, if we have 'o' odd numbers, let 'k' be the number of odd numbers 
 * that are assigned a '-' sign. The sum of odd numbers is equivalent to 
 * (o - k) - k = o - 2k (mod 2), which is equivalent to o (mod 2).
 * Wait, let's re-evaluate:
 * Each odd number $x_i$ contributes either $+x_i$ or $-x_i$ to the sum.
 * Since $x_i \equiv 1 \pmod 2$, $+x_i \equiv 1$ and $-x_i \equiv -1 \equiv 1 \pmod 2$.
 * Thus, every odd number contributes exactly 1 to the parity of the sum, 
 * regardless of the sign chosen.
 * 
 * Therefore, the parity of the total sum is simply the parity of the count of odd numbers.
 * If 'o' is even, the sum is always even. If 'o' is odd, the sum is always odd.
 * 
 * Wait, the problem says players choose signs. Let's re-read.
 * "Player 1 wins if the resulting sum is even, else player 2 wins."
 * If the number of odd integers 'o' is even, the sum is always even regardless of signs.
 * If 'o' is odd, the sum is always odd regardless of signs.
 * 
 * Let's check the sample cases:
 * 1) 1, 2: o=1 (odd). Output: 2. (Correct, sum is always odd)
 * 2) 1, 1, 2: o=2 (even). Output: 1. (Correct, sum is always even)
 * 3) 1, 2, 4: o=1 (odd). Output: 2. (Correct, sum is always odd)
 * 
 * Conclusion:
 * If the count of odd numbers is even, Player 1 wins (1).
 * If the count of odd numbers is odd, Player 2 wins (2).
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int odd_count = 0;
        for (int i = 0; i < n; ++i) {
            long long a;
            cin >> a;
            if (abs(a) % 2 != 0) {
                odd_count++;
            }
        }

        if (odd_count % 2 == 0) {
            cout << "1" << "\n";
        } else {
            cout << "2" << "\n";
        }
    }
    return 0;
}