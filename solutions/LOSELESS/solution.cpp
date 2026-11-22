#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Problem Analysis:
 * We have M matches and N points.
 * w = wins (3 pts), t = ties (1 pt), l = losses (0 pts)
 * w + t + l = M
 * 3w + t = N
 * 
 * l = M - (w + t)
 * Since t = N - 3w:
 * l = M - (w + N - 3w) = M - N + 2w
 * 
 * To minimize l, we minimize w.
 * Constraints:
 * 1) w >= 0
 * 2) t >= 0 => N - 3w >= 0 => w <= N/3
 * 3) w + t <= M => N - 2w <= M => 2w >= N - M => w >= (N - M + 1) / 2 (using integer division for ceil)
 * 
 * Minimum w = max(0, (N - M + 1) / 2)
 */

void solve() {
    int M, N;
    if (!(cin >> M >> N)) return;
    
    // Calculate minimum w using the derived constraints
    int min_w = max(0, (N - M + 1) / 2);
    
    // Ensure min_w doesn't exceed N/3 (though problem guarantees a solution exists)
    int l = M - N + 2 * min_w;
    
    cout << l << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}