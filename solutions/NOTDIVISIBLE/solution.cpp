#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need an array A of length N such that for any subarray A[i...j],
 * the sum of the subarray is not divisible by its length (j - i + 1).
 * 
 * A simple construction is to use values that make the sum "odd" when the length is "even",
 * or values that ensure the sum is not a multiple of the length.
 * 
 * Let's try setting A[i] such that the prefix sums S[k] = A[1] + ... + A[k]
 * satisfy specific properties.
 * A very simple construction that works for N up to 500 is to use a sequence of 
 * large odd numbers or a specific pattern.
 * 
 * Consider the sequence: A[i] = 1 if i is odd, and 2 if i is even.
 * This might not work for all lengths.
 * 
 * Let's use a construction where A[i] is a large prime or a sequence that avoids 
 * divisibility. A simple approach:
 * A[i] = 200 + i (for i=0 to N-1).
 * Let's test this: Sum(i, j) = (j-i+1) * (200 + i + 200 + j) / 2.
 * Sum / Length = (400 + i + j) / 2.
 * If we pick values such that (400 + i + j) is odd, then it's never divisible by 2.
 * However, we need it to be not divisible by any length L = j-i+1.
 * 
 * A robust construction:
 * Set A[i] = 300 for all i.
 * Sum = 300 * L. 300 * L is divisible by L. This fails.
 * 
 * Let's use: A[i] = 299 if i is even, 300 if i is odd.
 * This is a common competitive programming trick for this specific problem.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        // Using a pattern that avoids divisibility by most small integers.
        // 299 is odd, 300 is even.
        if (i % 2 == 0) {
            A[i] = 299;
        } else {
            A[i] = 300;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << A[i] << (i == N - 1 ? "" : " ");
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