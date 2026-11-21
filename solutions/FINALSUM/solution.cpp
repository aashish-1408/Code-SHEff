#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * In one operation on subarray [L, R], we add 1 to A[L], subtract 1 from A[L+1], 
 * add 1 to A[L+2], subtract 1 from A[L+3], and so on.
 * 
 * Let's look at the change in the total sum of the array:
 * The sequence of changes is: +1, -1, +1, -1, ...
 * The number of elements in the subarray is (R - L + 1).
 * 
 * If (R - L + 1) is even, there are equal numbers of +1s and -1s.
 * The net change to the sum is 0.
 * 
 * If (R - L + 1) is odd, there is one more +1 than -1.
 * The net change to the sum is +1.
 * 
 * Therefore, for each query [L, R], the total sum increases by 1 if (R - L + 1) is odd,
 * and remains unchanged if (R - L + 1) is even.
 * (R - L + 1) is odd if and only if (R - L) is even.
 * 
 * We can calculate the initial sum of the array and then for each query,
 * check the parity of (R - L). If (R - L) % 2 == 0, add 1 to the total sum.
 */

void solve() {
    int N, Q;
    if (!(cin >> N >> Q)) return;
    
    long long current_sum = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        current_sum += a;
    }
    
    for (int i = 0; i < Q; ++i) {
        int L, R;
        cin >> L >> R;
        // The length of the subarray is R - L + 1.
        // If length is odd, sum increases by 1.
        // Length is odd if (R - L + 1) % 2 != 0, which is (R - L) % 2 == 0.
        if ((R - L) % 2 == 0) {
            current_sum += 1;
        }
    }
    
    cout << current_sum << "\n";
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