#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to find the maximum D such that sum(floor(A_i / D)) >= M.
 * The function f(D) = sum(floor(A_i / D)) is monotonically non-increasing.
 * Binary search is appropriate.
 * 
 * Constraints:
 * N, M <= 10^5
 * A_i <= 10^4
 * Max possible D is 10^4 (since even with N=1, A_i=10^4, M=1, D=10^4).
 */

bool check(long long D, long long M, const vector<int>& A) {
    if (D == 0) return true;
    long long total_people_supported = 0;
    for (int val : A) {
        total_people_supported += (val / D);
        // Optimization: break early if we already satisfy M
        if (total_people_supported >= M) return true;
    }
    return total_people_supported >= M;
}

int main() {
    // Optimize I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long M;
    if (!(cin >> N >> M)) return 0;
    
    vector<int> A(N);
    int max_val = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] > max_val) max_val = A[i];
    }

    // Binary search for D in range [0, max_val]
    // If D=0 is the only option, the answer is 0.
    long long low = 1, high = max_val;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid == 0) {
            low = mid + 1;
            continue;
        }
        if (check(mid, M, A)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    cout << ans << endl;

    return 0;
}