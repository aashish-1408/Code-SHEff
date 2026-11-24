#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array is "good" if no two elements sum to 4.
 * The elements are restricted to {1, 2, 3}.
 * Pairs that sum to 4:
 * 1. (1, 3)
 * 2. (2, 2)
 * 
 * To make the array good:
 * - We cannot have both 1s and 3s in the array. If we have both, we must remove all 1s or all 3s.
 * - We cannot have more than one 2. If we have multiple 2s, we must remove all but one 2.
 * 
 * Strategy:
 * Count the occurrences of 1, 2, and 3.
 * Let count1 = number of 1s, count2 = number of 2s, count3 = number of 3s.
 * 
 * Option A: Keep 1s, remove all 3s, keep at most one 2.
 * Deletions = count3 + max(0, count2 - 1)
 * 
 * Option B: Keep 3s, remove all 1s, keep at most one 2.
 * Deletions = count1 + max(0, count2 - 1)
 * 
 * The answer is the minimum of these two options.
 */

void solve() {
    int N;
    cin >> N;
    int count1 = 0, count2 = 0, count3 = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a == 1) count1++;
        else if (a == 2) count2++;
        else if (a == 3) count3++;
    }

    int deletions_if_keep_1 = count3 + (count2 > 0 ? count2 - 1 : 0);
    int deletions_if_keep_3 = count1 + (count2 > 0 ? count2 - 1 : 0);

    cout << min(deletions_if_keep_1, deletions_if_keep_3) << "\n";
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