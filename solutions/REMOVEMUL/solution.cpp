#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with S = {1, 2, ..., N} and want to reach Q.
 * The operation allows us to remove the smallest multiple of k currently in S with cost k.
 * 
 * Let's consider the elements that are NOT in Q. These are the elements that must be removed.
 * If an element x is not in Q, it must be removed at some point.
 * When we remove x, we must choose some k such that x is the smallest multiple of k currently in S.
 * 
 * Actually, the problem can be simplified:
 * Any element x in {1, ..., N} \ Q must be removed.
 * If we choose to remove x by picking k = x, we can do so if x is still in S.
 * Since we want to maximize the cost, we should try to remove every element x not in Q 
 * by picking k = x.
 * 
 * Can we always remove x by picking k = x?
 * Yes, if we process removals in an order such that for any x not in Q, 
 * no multiple of x smaller than x (i.e., x/2, x/3, etc.) has been removed yet 
 * if that would have made x the "smallest multiple" of some other k.
 * Actually, the condition is simpler: we can remove every x not in Q by picking k = x.
 * The total cost is the sum of all x such that x is in {1, ..., N} but not in Q.
 * 
 * Proof sketch:
 * The sum of all integers from 1 to N is N*(N+1)/2.
 * The sum of elements in Q is given.
 * The sum of elements to be removed is (Sum of 1..N) - (Sum of elements in Q).
 * Since we can always choose k = x to remove x (provided x is not in Q), 
 * the maximum cost is indeed the sum of all elements in {1, ..., N} \ Q.
 */

void solve() {
    long long N;
    int M;
    if (!(cin >> N >> M)) return;
    
    long long sum_all = N * (N + 1) / 2;
    long long sum_q = 0;
    for (int i = 0; i < M; ++i) {
        long long val;
        cin >> val;
        sum_q += val;
    }
    
    cout << (sum_all - sum_q) << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}