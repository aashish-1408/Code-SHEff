#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an operation: pick two equal elements A_i = A_j, remove them, and add |A_i - A_j| = 0.
 * Effectively, any pair of equal elements can be replaced by a single 0.
 * 
 * Let's track the counts of each number.
 * 1. For any number x > 0:
 *    - If we have count[x] elements, we can pair them up.
 *    - If count[x] is even, we get count[x]/2 zeros.
 *    - If count[x] is odd, we get (count[x]-1)/2 zeros and one x remains.
 * 2. After processing all x > 0, we collect all the remaining x's and all the generated 0s.
 * 3. Now we have a collection of 0s. Let the total count of 0s be 'cnt0'.
 *    - We can pair up 0s: (0, 0) -> |0-0| = 0.
 *    - This means two 0s become one 0.
 *    - If we have cnt0 > 0, we can keep reducing them until only one 0 remains.
 *    - If cnt0 == 0, we have no zeros.
 * 
 * Algorithm:
 * 1. Count frequencies of all numbers.
 * 2. For each x > 0, add count[x] / 2 to the count of 0s.
 * 3. If count[x] % 2 != 0, keep one x.
 * 4. After processing all x > 0, if we have any 0s (either from the input or generated), 
 *    they can all be merged into a single 0.
 * 5. The final answer is (number of distinct x > 0 that remained) + (1 if we have any 0s else 0).
 */

void solve() {
    int n;
    cin >> n;
    map<int, int> counts;
    int zeros = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 0) zeros++;
        else counts[a]++;
    }

    int remaining_non_zero = 0;
    for (auto const& [val, count] : counts) {
        zeros += count / 2;
        if (count % 2 != 0) {
            remaining_non_zero++;
        }
    }

    if (zeros > 0) {
        cout << remaining_non_zero + 1 << "\n";
    } else {
        cout << remaining_non_zero << "\n";
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