#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to sort the array A = [1, 2, ..., N].
 * An operation at index i sorts the prefix A[1...i]. The cost is A[i].
 * 
 * Let's observe the state of the array. If the prefix A[1...k] is already 
 * sorted (i.e., A[1]=1, A[2]=2, ..., A[k]=k), we don't need to touch it.
 * We only need to consider the longest prefix that is already sorted.
 * Let this length be 'k'. If k == N, the cost is 0.
 * If k < N, we need to perform operations to fix the remaining part.
 * 
 * Actually, the problem asks for the minimum cost. Since we can perform 
 * operations as many times as we want, we can always sort the entire array 
 * by picking i = N, which costs A[N]. However, we can potentially do better.
 * 
 * If we find the largest index 'i' such that the prefix A[1...i] is NOT 
 * sorted (i.e., there exists some j <= i where A[j] != j), we must perform 
 * at least one operation at some index k >= i to fix the array.
 * 
 * Wait, the operation sorts the prefix. If we sort A[1...i], the new A[i] 
 * will be the maximum value in the original prefix A[1...i].
 * To minimize cost, we should identify the rightmost index 'i' that is 
 * "out of place". Any prefix operation at index 'k' where k >= i will 
 * effectively sort everything up to k.
 * 
 * Given N is small (100), we can observe that if the array is not sorted, 
 * we must perform at least one operation. The cost of an operation at index i 
 * is A[i]. To sort the whole array, we need to pick an index i such that 
 * after sorting, the array becomes [1, 2, ..., N].
 * 
 * Actually, the simplest strategy is: find the largest index 'i' such that 
 * A[i] != i. If no such i exists, cost is 0. Otherwise, we can sort the 
 * prefix ending at the rightmost index 'i' that is not in its correct 
 * sorted position. The cost is the value at that position.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int last_unsorted = -1;
    for (int i = 0; i < N; ++i) {
        if (A[i] != i + 1) {
            last_unsorted = i;
        }
    }

    if (last_unsorted == -1) {
        cout << 0 << "\n";
    } else {
        // We need to sort the prefix ending at last_unsorted or further.
        // The cost is A[last_unsorted].
        cout << A[last_unsorted] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}