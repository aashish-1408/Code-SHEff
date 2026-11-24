#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A product A_i * A_j > 0 if and only if:
 * 1. Both A_i and A_j are positive.
 * 2. Both A_i and A_j are negative.
 * 
 * If we have 'pos' count of positive numbers and 'neg' count of negative numbers,
 * the number of ways to choose two positive numbers is pos * (pos - 1) / 2.
 * The number of ways to choose two negative numbers is neg * (neg - 1) / 2.
 * 
 * The total number of pairs is the sum of these two combinations.
 * We use long long to prevent overflow, although with N=10^5, the max pairs 
 * is roughly (10^5)^2 / 2 = 5 * 10^9, which exceeds the range of a 32-bit int.
 */

void solve() {
    int n;
    cin >> n;
    
    long long pos = 0;
    long long neg = 0;
    
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val > 0) {
            pos++;
        } else if (val < 0) {
            neg++;
        }
    }
    
    // Number of ways to choose 2 from pos: posC2 = pos * (pos - 1) / 2
    // Number of ways to choose 2 from neg: negC2 = neg * (neg - 1) / 2
    long long ans = (pos * (pos - 1)) / 2 + (neg * (neg - 1)) / 2;
    
    cout << ans << "\n";
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