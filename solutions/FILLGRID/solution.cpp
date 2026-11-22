#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need (Sum * Product) < 0 for every row and every column.
 * 
 * Case 1: N is even.
 * If we fill the entire grid with -1:
 * Sum of each row/column = N * (-1) = -N.
 * Product of each row/column = (-1)^N = 1 (since N is even).
 * Sum * Product = -N * 1 = -N < 0.
 * This satisfies the condition for all rows and columns.
 * 
 * Case 2: N is odd.
 * If we fill the entire grid with -1, Product = (-1)^N = -1.
 * Sum = -N. Sum * Product = (-N) * (-1) = N > 0. (Fails)
 * 
 * We need to change the product to 1 while keeping the sum negative.
 * If we change one element in each row/column to 1, the product becomes 1.
 * Let's place 1s on the main diagonal (i, i).
 * For N=3:
 * 1 -1 -1
 * -1 1 -1
 * -1 -1 1
 * Row sum: 1 + (-1) + (-1) = -1.
 * Row product: 1 * (-1) * (-1) = 1.
 * Sum * Product = -1 * 1 = -1 < 0. (Satisfied)
 * This works for any odd N.
 */

void solve() {
    int N;
    cin >> N;

    if (N % 2 == 0) {
        // Even N: Fill everything with -1
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << -1 << (j == N - 1 ? "" : " ");
            }
            cout << "\n";
        }
    } else {
        // Odd N: Fill with -1, but put 1 on the main diagonal
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) {
                    cout << 1 << (j == N - 1 ? "" : " ");
                } else {
                    cout << -1 << (j == N - 1 ? "" : " ");
                }
            }
            cout << "\n";
        }
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