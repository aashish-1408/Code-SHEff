#include <iostream>

/**
 * Problem Analysis:
 * A party needs a strict majority to form the government.
 * The threshold is floor(N / 2) + 1.
 * Let T = floor(N / 2) + 1.
 * If K >= T, the party already has a majority, so 0 additional seats are needed.
 * If K < T, the party needs (T - K) additional seats.
 * 
 * Note: The problem description does not mention multiple test cases.
 * The previous attempt incorrectly assumed a 't' test case loop.
 */

int main() {
    // Optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    if (std::cin >> n >> k) {
        // Calculate the required threshold for a strict majority
        // Using integer division, n / 2 is equivalent to floor(n / 2)
        int threshold = (n / 2) + 1;

        // If current seats are already >= threshold, need 0.
        // Otherwise, need threshold - k.
        if (k >= threshold) {
            std::cout << 0 << std::endl;
        } else {
            std::cout << (threshold - k) << std::endl;
        }
    }

    return 0;
}