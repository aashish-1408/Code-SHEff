#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each element A_i, we add (A_i - k) and (A_i + k) to B.
 * Let the two elements added for A_i be x and y.
 * x = A_i - k
 * y = A_i + k
 * Summing these: x + y = (A_i - k) + (A_i + k) = 2 * A_i.
 * This implies that for every pair (x, y) chosen from B, their sum must be even.
 * 
 * If the sum of two numbers is even, it means both numbers must have the same parity.
 * That is, either both are even or both are odd.
 * 
 * Therefore, the sequence B must contain an even number of odd integers.
 * If the count of odd integers in B is even, we can always pair them up such that
 * each pair has an even sum (odd + odd = even, even + even = even).
 * 
 * Let the pairs be (x_i, y_i). We can set A_i = (x_i + y_i) / 2 and k = (y_i - x_i) / 2.
 * Since x_i and y_i have the same parity, (x_i + y_i) is always even, and (y_i - x_i) is always even.
 * Thus, A_i and k will always be integers.
 * 
 * Conclusion: The condition is satisfied if and only if the number of odd integers in B is even.
 */

void solve() {
    int N;
    cin >> N;
    int odd_count = 0;
    for (int i = 0; i < 2 * N; ++i) {
        long long val;
        cin >> val;
        // Check parity: works for both positive and negative integers
        if (abs(val) % 2 != 0) {
            odd_count++;
        }
    }

    if (odd_count % 2 == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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