#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N sectors with initial budgets A_i. We want to maximize the number of sectors
 * that have at least X. A sector i can give away its surplus (A_i - X) only if 
 * A_i >= X.
 * 
 * Strategy:
 * 1. Identify all sectors that already have >= X. These sectors contribute to the count
 *    and their surplus (A_i - X) can be used to help sectors that have < X.
 * 2. Sort the sectors that have < X in descending order. It is optimal to fill the 
 *    sectors that are closest to X first, because they require the least amount of 
 *    surplus to reach X.
 * 3. Keep track of the total surplus available. Iterate through the sorted sectors 
 *    (those with < X) and if the current surplus is enough to bring the sector to X,
 *    increment the count and subtract the required amount from the surplus.
 */

void solve() {
    int N;
    long long X;
    cin >> N >> X;
    vector<long long> A(N);
    vector<long long> surplus;
    vector<long long> deficit;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] >= X) {
            surplus.push_back(A[i] - X);
        } else {
            deficit.push_back(A[i]);
        }
    }

    // Sort deficits in descending order to fill the ones closest to X first
    sort(deficit.rbegin(), deficit.rend());

    long long total_surplus = 0;
    for (long long s : surplus) {
        total_surplus += s;
    }

    int count = surplus.size();
    for (long long d : deficit) {
        long long needed = X - d;
        if (total_surplus >= needed) {
            total_surplus -= needed;
            count++;
        } else {
            // Cannot fill any more sectors
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