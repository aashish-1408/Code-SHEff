#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let V be the initial velocity at the first segment.
 * At segment i (1-indexed), the velocity will be V - (i - 1).
 * The condition for each segment i is:
 * V - (i - 1) >= W_i
 * V >= W_i + i - 1
 * 
 * To satisfy this for all i from 1 to N, we need:
 * V >= max(W_i + i - 1) for all i in [1, N].
 * 
 * Therefore, the minimal velocity V is max(W_i + i - 1) for all i.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    long long max_v = 0;
    for (int i = 0; i < N; ++i) {
        long long w;
        cin >> w;
        // The condition is V >= W_i + i
        // where i is the 0-indexed position.
        // For i=0, V >= W_0 + 0
        // For i=1, V >= W_1 + 1
        long long current_required = w + i;
        if (current_required > max_v) {
            max_v = current_required;
        }
    }
    cout << max_v << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}