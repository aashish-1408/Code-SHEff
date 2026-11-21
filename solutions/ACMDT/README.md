# [Accommodation (ACMDT)](https://www.codechef.com/problems/ACMDT)

- **Difficulty Rating**: 1286
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $B$ boys and $G$ girls who need to be accommodated in $k$ rooms. Each room must contain at least $X$ boys and at least $Y$ girls, and the total number of people in any single room cannot exceed $N$. We need to find the minimum number of rooms $k$ required to satisfy these conditions. If no such $k$ exists, output -1.

## Intuition & Mathematical Observation
To solve this, we derive constraints on $k$ based on the given parameters:

1.  **Capacity Constraint**: Since each room can hold at most $N$ people, the total number of people $(B + G)$ must fit into $k$ rooms. Thus, $k \cdot N \ge B + G$, which implies:
    $$k \ge \lceil \frac{B + G}{N} \rceil$$
    Using integer arithmetic, this is calculated as `(B + G + N - 1) / N`.

2.  **Minimum Requirement Constraint**: Each of the $k$ rooms must have at least $X$ boys and $Y$ girls. Therefore:
    - $k \cdot X \le B \implies k \le \lfloor \frac{B}{X} \rfloor$
    - $k \cdot Y \le G \implies k \le \lfloor \frac{G}{Y} \rfloor$
    Combining these, we get $k \le \min(\lfloor \frac{B}{X} \rfloor, \lfloor \frac{G}{Y} \rfloor)$.

3.  **Feasibility**:
    - First, check if a single room can satisfy the minimum requirements: if $X + Y > N$, it is impossible to satisfy the constraints even for one room, so output -1.
    - Let `min_k` be the lower bound derived from the capacity constraint and `max_k` be the upper bound derived from the minimum requirements.
    - If `min_k <= max_k`, then the smallest valid number of rooms is `min_k`.
    - Otherwise, it is impossible to satisfy all conditions, so output -1.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and intermediate calculations.

## Solution Code

```cpp
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
```