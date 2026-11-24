#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allows us to flip the signs of any two elements simultaneously.
 * This means the parity of the number of negative signs in the array remains invariant.
 * 
 * 1. If the number of negative elements is even, we can flip all of them to positive
 *    using the operation repeatedly (flip two negatives at a time).
 * 2. If the number of negative elements is odd, we will always be left with at least
 *    one negative sign. To maximize the sum, we should make the element with the 
 *    smallest absolute value negative.
 * 
 * Algorithm:
 * - Count the number of negative elements.
 * - Keep track of the minimum absolute value in the array.
 * - Calculate the sum of absolute values of all elements.
 * - If the count of negative numbers is even, the answer is the sum of absolute values.
 * - If the count of negative numbers is odd, the answer is the sum of absolute values
 *   minus twice the smallest absolute value (because we effectively subtract it 
 *   instead of adding it).
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    int neg_count = 0;
    long long min_abs = 200000; // Larger than max possible |A_i|
    long long sum_abs = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < 0) {
            neg_count++;
        }
        long long abs_val = abs(a[i]);
        sum_abs += abs_val;
        if (abs_val < min_abs) {
            min_abs = abs_val;
        }
    }

    if (neg_count % 2 == 0) {
        cout << sum_abs << "\n";
    } else {
        // We must have one negative value. To maximize sum, 
        // we make the smallest absolute value negative.
        // Current sum_abs is sum(|A_i|). 
        // We need sum(|A_i|) - 2 * min(|A_i|).
        cout << sum_abs - 2 * min_abs << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}