#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with X people. We iterate through the array A.
 * At each step, we update the current number of people in the room.
 * We need to track the maximum value reached by this count, including the initial state X.
 * 
 * Constraints:
 * T <= 100, N <= 100, X <= 100, A_i between -100 and 100.
 * The maximum possible number of people will not exceed 100 + 100 * 100 = 10100.
 * Standard integer types are sufficient.
 */

void solve() {
    int N;
    long long X;
    cin >> N >> X;

    long long current_people = X;
    long long max_people = X;

    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        current_people += a;
        if (current_people > max_people) {
            max_people = current_people;
        }
    }

    cout << max_people << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}