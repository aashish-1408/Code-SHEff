# [FightBots (FIGBOT)](https://www.codechef.com/problems/FIGBOT)

- **Difficulty Rating**: 1329
- **Solved in**: 2 attempt(s)

## Problem Summary
Alice starts at $(0, 0)$ and follows a sequence of $N$ moves (Up, Down, Left, Right). Bob starts at $(X, Y)$. We need to determine if there exists any time $k$ ($1 \le k \le N$) such that Bob can reach Alice's position at that exact moment. Bob can move one unit in any of the four cardinal directions per second.

## Intuition & Mathematical Observation
For Bob to reach Alice's position $(Ax_k, Ay_k)$ at time $k$, two conditions must be satisfied:

1.  **Distance Constraint**: The Manhattan distance between Bob's starting position $(X, Y)$ and Alice's position $(Ax_k, Ay_k)$ must be less than or equal to the time elapsed $k$.
    *   $|Ax_k - X| + |Ay_k - Y| \le k$
2.  **Parity Constraint**: Bob moves on a grid. The parity of the Manhattan distance between two points on a grid changes with every step. If the distance is $D$, Bob needs $D$ steps to reach the target. If he has $k$ steps available, he can reach the target if and only if $k \ge D$ and $(k - D)$ is an even number. This is because he can "waste" moves by moving back and forth (e.g., Right then Left) to consume the remaining even number of steps.

By iterating through each second $k$ from $1$ to $N$, updating Alice's position, and checking these two conditions, we can determine if an intersection is possible.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string of moves. We perform a single pass through the string.
- **Space Complexity**: $O(N)$ to store the input string, or $O(1)$ if processing character by character.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * Alice starts at (0, 0). Bob starts at (X, Y).
 * At each second k (1 to N), Alice is at (Ax_k, Ay_k).
 * Bob can reach (Ax_k, Ay_k) at time k if:
 * 1. The Manhattan distance |Ax_k - X| + |Ay_k - Y| <= k.
 * 2. The parity of the Manhattan distance is the same as the parity of k.
 *    (i.e., (k - dist) % 2 == 0).
 */

void solve() {
    int N;
    long long X, Y;
    if (!(cin >> N >> X >> Y)) return;
    string S;
    cin >> S;

    long long curAx = 0;
    long long curAy = 0;

    bool possible = false;
    for (int i = 0; i < N; ++i) {
        // Update Alice's position based on the move
        if (S[i] == 'L') curAx--;
        else if (S[i] == 'R') curAx++;
        else if (S[i] == 'U') curAy++;
        else if (S[i] == 'D') curAy--;

        long long time = i + 1;
        long long dist = abs(curAx - X) + abs(curAy - Y);

        // Bob can reach Alice at time 'time' if:
        // 1. He has enough time to cover the Manhattan distance (dist <= time)
        // 2. The parity of the distance matches the parity of the time
        if (dist <= time && (time - dist) % 2 == 0) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```