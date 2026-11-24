#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Ved has two modes:
 * 1. Single-Target Mode:
 *    In one second, he can deal X damage to one enemy.
 *    To kill an enemy with health H_i, he needs ceil(H_i / X) seconds.
 *    Total time = sum(ceil(H_i / X)) for all i.
 * 
 * 2. Multi-Target Mode:
 *    In one second, he deals 1 damage to all living enemies.
 *    To kill all enemies, he needs to deal damage equal to the maximum health 
 *    among all enemies, because the enemy with the highest health will be the 
 *    last one to die.
 *    Total time = max(H_i) for all i.
 * 
 * The goal is to find the minimum of these two values.
 */

void solve() {
    int N, X;
    cin >> N >> X;
    vector<int> H(N);
    int max_h = 0;
    long long single_target_time = 0;

    for (int i = 0; i < N; ++i) {
        cin >> H[i];
        // Update max health for multi-target mode
        if (H[i] > max_h) {
            max_h = H[i];
        }
        // Calculate time for single-target mode
        // ceil(H[i] / X) is equivalent to (H[i] + X - 1) / X using integer division
        single_target_time += (H[i] + X - 1) / X;
    }

    // The answer is the minimum of the two modes
    long long ans = min((long long)max_h, single_target_time);
    cout << ans << "\n";
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