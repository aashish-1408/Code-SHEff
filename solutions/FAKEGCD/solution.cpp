#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need a permutation A of {1, 2, ..., N} such that gcd(1+A_1, 2+A_2, ..., N+A_N) > 1.
 * Let the GCD be g. We want g+1, g+2, ..., g+N to be divisible by some integer d > 1.
 * 
 * A simple strategy is to make all terms (i + A_i) equal to a common multiple.
 * If we choose d = 2, we want (i + A_i) to be even for all i.
 * This means i and A_i must have the same parity.
 * 
 * We can partition the set {1, ..., N} into two sets:
 * Odds: {1, 3, 5, ...}
 * Evens: {2, 4, 6, ...}
 * 
 * If we map all odd i to odd A_i and all even i to even A_i, then (i + A_i) will always be even.
 * Since all elements are even, their GCD will be at least 2.
 * 
 * Algorithm:
 * 1. Collect all odd numbers from 1 to N into a list.
 * 2. Collect all even numbers from 1 to N into a list.
 * 3. Iterate i from 1 to N:
 *    - If i is odd, pick an element from the odd list.
 *    - If i is even, pick an element from the even list.
 */

void solve() {
    int N;
    cin >> N;
    
    vector<int> odds, evens;
    for (int i = 1; i <= N; ++i) {
        if (i % 2 != 0) odds.push_back(i);
        else evens.push_back(i);
    }
    
    int odd_idx = 0, even_idx = 0;
    for (int i = 1; i <= N; ++i) {
        if (i % 2 != 0) {
            cout << odds[odd_idx++] << (i == N ? "" : " ");
        } else {
            cout << evens[even_idx++] << (i == N ? "" : " ");
        }
    }
    cout << "\n";
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