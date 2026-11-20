#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to maximize the sum of squares of group sums: X_1^2 + X_2^2 + ... + X_K^2.
 * Mathematically, for any set of numbers, the sum of squares is maximized by 
 * grouping all positive numbers together and all negative numbers together.
 * 
 * Let P be the set of positive numbers and N be the set of negative numbers.
 * If we have both positive and negative numbers:
 * - Group 1: All positive numbers (Sum = S_pos, Size = count_pos)
 * - Group 2: All negative numbers (Sum = S_neg, Size = count_neg)
 * Total score = S_pos^2 + S_neg^2.
 * 
 * If we only have positive numbers, the maximum is achieved by putting all in one group.
 * If we only have negative numbers, the maximum is achieved by putting all in one group.
 * 
 * Cases:
 * 1. Only positive numbers: 
 *    Max group size = N, Min group size = N.
 * 2. Only negative numbers: 
 *    Max group size = N, Min group size = N.
 * 3. Both positive and negative:
 *    We have two groups: one with all positives (size count_pos) and one with all negatives (size count_neg).
 *    - Max group size: max(count_pos, count_neg)
 *    - Min group size: min(count_pos, count_neg)
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    int pos_count = 0;
    int neg_count = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] >= 0) {
            pos_count++;
        } else {
            neg_count++;
        }
    }
    
    if (pos_count == 0 || neg_count == 0) {
        // All numbers are same sign, best to put them in one group
        cout << n << " " << n << "\n";
    } else {
        // We have both positive and negative numbers.
        // To maximize sum of squares, we group all positives together and all negatives together.
        // The two group sizes are pos_count and neg_count.
        int max_s = max(pos_count, neg_count);
        int min_s = min(pos_count, neg_count);
        cout << max_s << " " << min_s << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}