#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let k be the number of rooms.
 * Each room i must have:
 * 1. boys_i >= X
 * 2. girls_i >= Y
 * 3. boys_i + girls_i <= N
 * 
 * Summing over k rooms:
 * Sum(boys_i) = B >= k * X
 * Sum(girls_i) = G >= k * Y
 * Sum(boys_i + girls_i) = B + G <= k * N
 * 
 * From these, we get:
 * k <= B / X
 * k <= G / Y
 * k >= ceil((B + G) / N)
 * 
 * So, we need to find the smallest integer k such that:
 * ceil((B + G) / N) <= k <= min(floor(B / X), floor(G / Y))
 * 
 * Let min_k = ceil((B + G) / N) = (B + G + N - 1) / N
 * Let max_k = min(B / X, G / Y)
 * 
 * If min_k <= max_k, then the answer is min_k.
 * Otherwise, it is impossible, so output -1.
 */

void solve() {
    long long B, G, X, Y, N;
    if (!(cin >> B >> G >> X >> Y >> N)) return;

    // Check if a single room can even satisfy the minimum requirements
    if (X + Y > N) {
        cout << -1 << "\n";
        return;
    }

    // Minimum rooms required to fit all people given capacity N
    long long min_k = (B + G + N - 1) / N;

    // Maximum rooms possible given the constraints on boys and girls per room
    long long max_k = min(B / X, G / Y);

    if (min_k <= max_k) {
        cout << min_k << "\n";
    } else {
        cout << -1 << "\n";
    }
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