#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N groups with sizes A_1, A_2, ..., A_N.
 * If we invite a subset of groups with total people P, the number of handshakes is P*(P-1)/2.
 * We want to maximize the number of groups invited such that P*(P-1)/2 <= M.
 * 
 * Since we want to maximize the count of groups, we should always pick the smallest groups first.
 * This is a greedy approach:
 * 1. Sort the group sizes in non-decreasing order.
 * 2. Iterate through the sorted groups and keep adding them to our set as long as the 
 *    total number of handshakes remains <= M.
 * 
 * Constraints:
 * N <= 100, A_i <= 100.
 * Max total people P = 100 * 100 = 10,000.
 * Max handshakes = 10,000 * 9,999 / 2 ≈ 5 * 10^7.
 * This fits within a standard 32-bit integer, but using long long is safer for calculations.
 */

void solve() {
    int N;
    long long M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort groups to pick the smallest ones first to maximize the count
    sort(A.begin(), A.end());

    long long current_people = 0;
    int count = 0;

    for (int i = 0; i < N; ++i) {
        long long next_people = current_people + A[i];
        long long handshakes = (next_people * (next_people - 1)) / 2;

        if (handshakes <= M) {
            current_people = next_people;
            count++;
        } else {
            // Since groups are sorted, if adding this group exceeds M, 
            // adding any larger group will also exceed M.
            break;
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