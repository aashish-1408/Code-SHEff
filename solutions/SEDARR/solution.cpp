#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a sequence A of N positive integers and a divisor K.
 * We want the sum of the sequence to be divisible by K.
 * We can change any element to any positive integer.
 * 
 * Let S be the sum of the elements in the sequence.
 * If S % K == 0, we need 0 operations.
 * If S % K != 0, we can change exactly one element to make the sum divisible by K.
 * For example, if the current sum is S, we want the new sum S' = S - A_i + X to be divisible by K.
 * We can always pick an X such that (S - A_i + X) % K == 0.
 * Since we can pick any positive integer X, we can always satisfy the condition 
 * by changing just one element, provided the resulting X is positive.
 * 
 * Thus, the answer is 0 if sum % K == 0, and 1 otherwise.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(1) auxiliary space (excluding input storage).
 */

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        long long a;
        cin >> a;
        sum += a;
    }
    
    if (sum % K == 0) {
        cout << 0 << "\n";
    } else {
        cout << 1 << "\n";
    }
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