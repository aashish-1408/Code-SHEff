#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * Alice starts at (0, 0). Bob starts at (X, Y).
 * At each second k (1 to N), Alice is at (Ax_k, Ay_k).
 * Bob can reach (Ax_k, Ay_k) at time k if:
 * 1. The Manhattan distance |Ax_k - X| + |Ay_k - Y| <= k.
 * 2. The parity of the Manhattan distance is the same as the parity of k.
 *    (i.e., (k - dist) % 2 == 0).
 */

void solve() {
    int N;
    long long X, Y;
    if (!(cin >> N >> X >> Y)) return;
    string S;
    cin >> S;

    long long curAx = 0;
    long long curAy = 0;

    bool possible = false;
    for (int i = 0; i < N; ++i) {
        // Update Alice's position
        if (S[i] == 'L') curAx--;
        else if (S[i] == 'R') curAx++;
        else if (S[i] == 'U') curAy++;
        else if (S[i] == 'D') curAy--;

        long long time = i + 1;
        long long dist = abs(curAx - X) + abs(curAy - Y);

        // Bob can reach Alice at time 'time' if:
        // 1. He has enough time to cover the Manhattan distance (dist <= time)
        // 2. The parity of the distance matches the parity of the time
        if (dist <= time && (time - dist) % 2 == 0) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}