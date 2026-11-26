#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to ensure that for all i, A[i] != i.
 * If we have a fixed point at index i (A[i] == i), we can insert an element 
 * at the beginning of the array. This shifts all elements to the right by 1.
 * If an element was at index i, it moves to index i+1.
 * If A[i] was equal to i, after shifting, the element is now at i+1, 
 * so its value is i, and its index is i+1. Since i != i+1, the fixed point is resolved.
 * 
 * Each insertion shifts all subsequent elements. If we encounter a fixed point 
 * at index i, inserting an element at the start effectively shifts the index 
 * of all elements from i to N by +1.
 * 
 * Let 'count' be the number of insertions performed so far.
 * An element originally at index i (1-indexed) will be at index i + count.
 * We have a fixed point if A[i] == i + count.
 * We iterate through the array, and every time we find an index i such that 
 * A[i] == i + count, we increment 'count'.
 * This greedy approach works because each insertion shifts all remaining elements 
 * by 1, potentially fixing the current conflict and potentially creating or 
 * avoiding future ones.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int count = 0;
    for (int i = 0; i < N; ++i) {
        // Current index is (i + 1). After 'count' insertions, 
        // the element originally at index (i + 1) is now at index (i + 1 + count).
        // We have a fixed point if A[i] == (i + 1 + count).
        if (A[i] == (i + 1 + count)) {
            count++;
        }
    }
    cout << count << "\n";
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