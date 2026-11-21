#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For a soldier i, the neighbors are (i-1) and (i+1).
 * Note: Indices are 1-based. For soldier i, the left neighbor is (i-2+N)%N + 1
 * and the right neighbor is (i)%N + 1.
 * 
 * A soldier i survives if their defense d[i] is strictly greater than the sum of 
 * the attack values of any combination of neighbors that choose to attack them.
 * Since the neighbors choose independently, the worst-case scenario for soldier i 
 * is that both neighbors choose to attack them.
 * 
 * Thus, soldier i survives if and only if:
 * d[i] > a[left_neighbor] + a[right_neighbor]
 * 
 * We need to find the maximum d[i] among all soldiers who satisfy this condition.
 * If no soldier satisfies this, output -1.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> a(N), d(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> d[i];

    int max_defense = -1;

    for (int i = 0; i < N; ++i) {
        // Left neighbor index: (i - 1 + N) % N
        // Right neighbor index: (i + 1) % N
        int left = (i - 1 + N) % N;
        int right = (i + 1) % N;

        // Condition: d[i] > a[left] + a[right]
        if (d[i] > (a[left] + a[right])) {
            if (d[i] > max_defense) {
                max_defense = d[i];
            }
        }
    }

    cout << max_defense << "\n";
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