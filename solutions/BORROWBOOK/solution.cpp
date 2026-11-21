#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N books. The i-th book (1-indexed) was returned i days late on day A_i.
 * For each day D, we need to find the maximum penalty among all books returned on day D.
 * The penalty for the i-th book is i.
 * Let max_penalty[D] be the maximum value of i such that A_i = D.
 * The total penalty is the sum of max_penalty[D] for all days D where at least one book was returned.
 * 
 * Constraints:
 * N <= 10^5, A_i <= 10^5.
 * Sum of N over test cases <= 2*10^5.
 * We can use an array (or vector) of size 100,001 to store the maximum penalty for each day.
 */

void solve() {
    int N;
    cin >> N;
    
    // Since A_i <= 10^5, we can use a vector to store the max penalty for each day.
    // We initialize with 0.
    // Using a static or local vector is fine given the constraints.
    // To avoid reallocating large memory repeatedly, we only clear the indices we use.
    static vector<int> max_penalty(100001, 0);
    vector<int> days_used;
    
    for (int i = 1; i <= N; ++i) {
        int day;
        cin >> day;
        if (max_penalty[day] == 0) {
            days_used.push_back(day);
        }
        if (i > max_penalty[day]) {
            max_penalty[day] = i;
        }
    }
    
    long long total_penalty = 0;
    for (int day : days_used) {
        total_penalty += max_penalty[day];
        // Reset for next test case
        max_penalty[day] = 0;
    }
    
    cout << total_penalty << "\n";
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