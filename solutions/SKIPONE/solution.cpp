#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to buy items in sequence 1, 2, ..., N.
 * We have a budget K and one discount coupon to make one item free.
 * Let S[i] be the prefix sum of costs A[1]...A[i].
 * If we buy 'm' items, we want to minimize the cost of these 'm' items
 * by applying the discount to the most expensive item among the first 'm'.
 * 
 * Let M[i] be the maximum cost among the first 'i' items.
 * The cost to buy 'i' items is (S[i] - M[i]).
 * We need to find the largest 'i' such that (S[i] - M[i]) <= K.
 * 
 * Since S[i] is strictly increasing and M[i] is non-decreasing,
 * the function f(i) = S[i] - M[i] is non-decreasing.
 * We can use binary search or a simple linear scan to find the maximum 'i'.
 */

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int ans = 0;
    long long current_sum = 0;
    long long max_val = 0;

    for (int i = 0; i < N; ++i) {
        current_sum += A[i];
        if (A[i] > max_val) {
            max_val = A[i];
        }

        // Cost to buy i+1 items is (sum of all items) - (the most expensive one)
        if (current_sum - max_val <= K) {
            ans = i + 1;
        } else {
            // Since the function is monotonic, once we exceed K, we can stop.
            break;
        }
    }

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