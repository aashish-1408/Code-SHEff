#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A semi-prime is a product of two distinct primes.
 * N <= 200.
 * 1. Precompute all primes up to 200.
 * 2. Generate all semi-primes up to 200.
 * 3. For each test case N, check if there exist two semi-primes s1, s2 such that s1 + s2 = N.
 */

bool is_semi_prime(int n) {
    int count = 0;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int d1 = i;
            int d2 = n / i;
            // Check if d1 and d2 are distinct primes
            auto is_prime = [](int k) {
                if (k < 2) return false;
                for (int j = 2; j * j <= k; ++j) {
                    if (k % j == 0) return false;
                }
                return true;
            };
            if (d1 != d2 && is_prime(d1) && is_prime(d2)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Precompute semi-primes up to 200
    vector<int> semi_primes;
    for (int i = 1; i <= 200; ++i) {
        if (is_semi_prime(i)) {
            semi_primes.push_back(i);
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool found = false;
        // Check if n can be represented as sum of two semi-primes
        for (int s1 : semi_primes) {
            for (int s2 : semi_primes) {
                if (s1 + s2 == n) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        if (found) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}