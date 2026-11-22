#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let the prime factorization of A be p1^a1 * p2^a2 * ... * pk^ak.
 * The number of divisors X is given by (a1 + 1) * (a2 + 1) * ... * (ak + 1).
 * The number of prime factors K is the number of distinct primes, which is k.
 * 
 * We are given X and K. We need to check if there exists an integer A such that:
 * 1. The number of prime factors (distinct) is exactly K.
 * 2. The total number of divisors is exactly X.
 * 
 * Since we want to check if it's possible to have exactly K prime factors, 
 * the smallest possible number of divisors for a given K is 2^K (when all ai = 1).
 * Also, the total number of prime factors (counting multiplicity) must be at least K.
 * 
 * The condition is:
 * 1. K must be less than or equal to the total number of prime factors (counting multiplicity).
 *    Since X = product(ai + 1), the maximum number of prime factors (with multiplicity) 
 *    is bounded by the number of factors of X.
 * 2. Specifically, if we represent X as a product of prime factors, the number of 
 *    prime factors of A (with multiplicity) is the sum of the exponents of the prime 
 *    factors of X.
 * 3. A simpler approach:
 *    - Find the number of prime factors of X (with multiplicity). Let this be `max_prime_factors`.
 *    - If K > max_prime_factors, it's impossible (return 0).
 *    - If K == 1, any prime number works (X=2, K=1).
 *    - If K > 1, we need to ensure we can construct A. Since we can always choose 
 *      large enough primes to satisfy the divisor count, the only constraint is 
 *      that we have enough "slots" to place the K primes.
 */

int count_prime_factors(int n) {
    int count = 0;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            count++;
            n /= i;
        }
    }
    if (n > 1) count++;
    return count;
}

void solve() {
    long long X, K;
    cin >> X >> K;

    // If K is greater than the number of prime factors of X, 
    // it's impossible to have K distinct prime factors.
    // Example: X=4, K=3. Prime factors of 4 are 2, 2. Max distinct primes = 2.
    if (K > 30) { // 2^30 > 10^9, so K cannot exceed 30 for X <= 10^9
        cout << 0 << "\n";
        return;
    }

    int max_k = count_prime_factors(X);
    
    if (K <= max_k) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}