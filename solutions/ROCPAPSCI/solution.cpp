#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to maximize wins against a sequence of moves A[i].
 * Chef cannot play the same move twice consecutively.
 * 
 * Let win(move) be the move that beats Roku's move A[i].
 * If Roku plays 'R', Chef wins with 'P'.
 * If Roku plays 'P', Chef wins with 'S'.
 * If Roku plays 'S', Chef wins with 'R'.
 * 
 * This is a Dynamic Programming problem.
 * Let dp[i][last_move] be the max wins up to index i, given that Chef's move at i was last_move.
 * last_move can be 0 ('R'), 1 ('P'), or 2 ('S').
 * 
 * dp[i][current_move] = (win_condition ? 1 : 0) + max(dp[i-1][prev_move])
 * where prev_move != current_move.
 */

void solve() {
    int N;
    cin >> N;
    string A;
    cin >> A;

    // dp[last_move] stores the max wins ending with that move
    // Initialize with 0
    vector<int> dp(3, 0);

    auto get_move_idx = [](char c) {
        if (c == 'R') return 0;
        if (c == 'P') return 1;
        return 2;
    };

    auto wins = [](char chef, char roku) {
        if (chef == 'R' && roku == 'S') return true;
        if (chef == 'P' && roku == 'R') return true;
        if (chef == 'S' && roku == 'P') return true;
        return false;
    };

    char moves[] = {'R', 'P', 'S'};

    for (int i = 0; i < N; ++i) {
        vector<int> next_dp(3, -1e9);
        for (int curr = 0; curr < 3; ++curr) {
            int win_val = wins(moves[curr], A[i]) ? 1 : 0;
            for (int prev = 0; prev < 3; ++prev) {
                if (i == 0 || curr != prev) {
                    next_dp[curr] = max(next_dp[curr], dp[prev] + win_val);
                }
            }
        }
        dp = next_dp;
    }

    cout << max({dp[0], dp[1], dp[2]}) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}