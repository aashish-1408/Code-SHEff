#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * We want to find the smallest W such that removing one digit from W yields A, 
 * and A is the largest possible result.
 * 
 * Strategy:
 * 1. If we insert a digit 'd' at index i, the resulting number is A if we remove 
 *    the digit at index i. For A to be the largest possible, we need d <= A[i].
 * 2. To minimize W, we want to insert the smallest possible digit at the 
 *    earliest possible position.
 * 3. If A[0] > '1', we can prepend '1'. W = '1' + A.
 * 4. If A[0] == '1', we look for the first index i such that A[i] > '0'. 
 *    We insert '0' at that position.
 */

void solve() {
    string A;
    cin >> A;

    if (A[0] > '1') {
        cout << '1' << A << "\n";
    } else {
        // A[0] is '1'. We need to insert '0' at the first position i where A[i] > '0'.
        // If no such i exists (e.g., 1000), we insert '0' at the end.
        bool inserted = false;
        for (int i = 1; i < A.length(); ++i) {
            if (A[i] > '0') {
                cout << A.substr(0, i) << '0' << A.substr(i) << "\n";
                inserted = true;
                break;
            }
        }
        if (!inserted) {
            cout << A << '0' << "\n";
        }
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