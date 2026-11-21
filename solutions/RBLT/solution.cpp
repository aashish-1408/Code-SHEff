#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N lights.
 * C_i = 1 (Red), C_i = 2 (Blue), C_i = 0 (Undecided).
 * Total lights N must be even for a balanced configuration (equal number of red and blue).
 * If N is odd, it is impossible to have an equal number of red and blue lights.
 * Let R be the count of already decided red lights.
 * Let B be the count of already decided blue lights.
 * Let U be the count of undecided lights (C_i = 0).
 * We need to assign x of the U lights to be red and (U - x) to be blue.
 * The final count of red lights will be R + x.
 * The final count of blue lights will be B + (U - x).
 * For balance, R + x = B + U - x.
 * 2x = B + U - R.
 * Since x must be an integer such that 0 <= x <= U, we check:
 * 1. (B + U - R) must be non-negative and even.
 * 2. The resulting x must satisfy 0 <= x <= U.
 */

void solve() {
    int N;
    cin >> N;
    int R = 0, B = 0, U = 0;
    for (int i = 0; i < N; ++i) {
        int c;
        cin >> c;
        if (c == 1) R++;
        else if (c == 2) B++;
        else U++;
    }

    // If total lights is odd, cannot be balanced
    if (N % 2 != 0) {
        cout << "No" << "\n";
        return;
    }

    // We need R + x = N / 2
    // x = N / 2 - R
    int x = (N / 2) - R;

    // Check if x is a valid number of red lights to add
    if (x >= 0 && x <= U) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}